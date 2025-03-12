#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
namespace asio = boost::asio;
using namespace std::chrono_literals;

class SafeCounter
{
public:
    SafeCounter(asio::io_context &io)
        : strand_(asio::make_strand(io)), count_(0) {}

    void AsyncIncrement()
    {
        // 创建独立timer（生命周期由shared_ptr管理）
        auto timer = std::make_shared<asio::steady_timer>(strand_);
        timer->expires_after(std::chrono::seconds(count_));

        // 绑定执行器并异步等待，捕获timer变量是为了确保定时器对象的生命周期能够延续到异步回调执行时
        timer->async_wait(
            boost::asio::bind_executor(strand_,
                                       [this, timer](const boost::system::error_code &ec)
                                       {
                                           if (!ec)
                                           {
                                               ++count_;
                                               std::cout << "Count: " << count_
                                                         << " (Thread: " << std::this_thread::get_id()
                                                         << ")\n";
                                           }

                                           if (count_ < 10)
                                           {
                                               AsyncIncrement();
                                           }
                                       }));
    }

private:
    asio::strand<asio::io_context::executor_type> strand_;
    int count_;
};

int main()
{
    asio::io_context io;
    auto work = asio::make_work_guard(io); // 保持IO上下文活动
    SafeCounter counter(io);

    // 启动4个工作线程
    const int thread_count = 4;
    std::vector<std::thread> threads;
    for (int i = 0; i < thread_count; ++i)
    {
        threads.emplace_back([&io]
                             { io.run(); });
    }

    // 提交10个异步增量请求
    for (int i = 0; i < 4; ++i)
    {
        counter.AsyncIncrement();
    }

    // 等待所有操作完成（约10秒）
    std::this_thread::sleep_for(11s);

    // 清理
    work.reset();
    io.stop();
    for (auto &t : threads)
    {
        if (t.joinable())
            t.join();
    }
}
