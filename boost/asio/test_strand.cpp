#include <boost/asio.hpp>
#include <iostream>
#include <thread>
namespace asio = boost::asio;

class SafeCounter
{
  public:
    SafeCounter(asio::io_context &io) : strand_(io.get_executor()), count_(0)
    {
    }

    // 线程安全的增加计数
    void Increment()
    {
        // 通过 strand 提交任务
        asio::post(strand_, [this] {
            ++count_;
            std::cout << "Count: " << count_ << " (Thread: " << std::this_thread::get_id() << ")\n";
        });
    }

  private:
    asio::strand<asio::io_context::executor_type> strand_;
    int count_;
};

int main()
{
    asio::io_context io;
    auto work = asio::make_work_guard(io); // 添加 work guard
    SafeCounter counter(io);

    // 启动 4 个工作线程
    const int thread_count = 4;
    std::vector<std::thread> threads;
    std::cout << "工作线程启动\n";
    for (int i = 0; i < thread_count; ++i)
    {
        threads.emplace_back([&io] {
            std::cout << "线程 " << std::this_thread::get_id() << " 开始运行\n";
            io.run();
            std::cout << "线程 " << std::this_thread::get_id() << " 结束运行\n";
        });
    }

    // 并发调用增加计数
    for (int i = 0; i < 10; ++i)
    {
        std::thread([&counter] { counter.Increment(); }).detach();
    }

    work.reset(); // 允许 io_context 停止

    // 等待所有线程完成
    for (auto &t : threads)
    {
        if (t.joinable())
            t.join();
    }
}
