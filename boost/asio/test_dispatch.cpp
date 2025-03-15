#include <boost/asio.hpp>
#include <iostream>
#include <thread>

namespace asio = boost::asio;

void use()
{
    asio::io_context io;

    // 直接在当前线程中投递任务
    asio::dispatch(io, [] { std::cout << "任务1: 在 io_context 线程中执行\n"; });

    // 运行 io_context
    io.run(); // 输出: 任务1: 在 io_context 线程中执行
}

void use_with_multi_thread()
{
    asio::io_context io;
    asio::io_context::work work(io); // 保持 io_context 运行

    // 创建两个工作线程
    std::vector<std::thread> threads;
    for (int i = 0; i < 2; ++i)
    {
        threads.emplace_back([&io] { io.run(); });
    }

    // 从主线程投递任务
    asio::dispatch(io, [] { std::cout << "任务2: 在线程 " << std::this_thread::get_id() << " 执行\n"; });

    // 从另一个工作线程投递任务
    std::thread([&io] {
        asio::dispatch(io, [] { std::cout << "任务3: 在线程 " << std::this_thread::get_id() << " 执行\n"; });
    }).join();

    // 停止 io_context 并等待线程结束
    io.stop();
    for (auto &t : threads)
        t.join();
}

void use_with_strand()
{
    asio::io_context io;
    asio::strand<asio::io_context::executor_type> strand(io.get_executor());

    // 通过 strand 投递任务（保证顺序执行）
    asio::dispatch(strand, [] { std::cout << "任务A: 在线程 " << std::this_thread::get_id() << " 执行\n"; });
    asio::dispatch(strand, [] { std::cout << "任务B: 在线程 " << std::this_thread::get_id() << " 执行\n"; });

    // 运行 io_context
    io.run();
}

class GUIApp
{
  public:
    GUIApp() : gui_executor_(gui_io_.get_executor())
    {
        // 启动 GUI 主线程
        gui_thread_ = std::thread([this] { gui_io_.run(); });
    }

    ~GUIApp()
    {
        gui_io_.stop();
        gui_thread_.join();
    }

    // 安全更新 UI（必须在 GUI 线程执行）
    void SafeUpdateUI(const std::string &message)
    {
        asio::dispatch(gui_executor_, [this, message] {
            std::cout << "UI 更新: " << message << " (线程 " << std::this_thread::get_id() << ")\n";
        });
    }

  private:
    asio::io_context gui_io_;
    asio::io_context::executor_type gui_executor_;
    std::thread gui_thread_;
};

void use_with_specified_thread()
{
    GUIApp app;

    // 从其他线程触发 UI 更新
    std::thread worker([&app] { app.SafeUpdateUI("来自工作线程的数据"); });
    worker.join();
}

int main()
{
    // use();

    // use_with_multi_thread();

    // use_with_strand();

    use_with_specified_thread();

    return 0;
}
