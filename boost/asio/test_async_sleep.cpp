#include <boost/asio.hpp>
#include <chrono>
#include <iostream>
#include <thread>

using namespace boost::asio;
using namespace std::chrono_literals;

// 使用回调函数的定时器
void wait_for_seconds(io_context &io, int seconds, std::function<void()> callback)
{
    // 使用 shared_ptr 管理定时器，确保其存活到异步操作完成。
    auto timer = std::make_shared<steady_timer>(io);
    timer->expires_after(std::chrono::seconds(seconds));
    std::cout << "Timer set for " << seconds << " seconds.\n";

    // 捕获 shared_ptr 以延长生命周期
    timer->async_wait([timer, callback, seconds](const boost::system::error_code &ec) {
        if (!ec)
        {
            std::cout << "Timer expired after " << seconds << " seconds.\n";
            callback();
        }
        else if (ec == boost::asio::error::operation_aborted)
        {
            std::cout << "Timer was canceled.\n";
        }
        else
        {
            std::cout << "Error: " << ec.message() << std::endl;
        }
    });
}

int main()
{
    // 创建 io_context
    boost::asio::io_context io_context;

    // 设置定时器并传入回调
    wait_for_seconds(io_context, 5, []() { std::cout << "Callback function called after timer expired.\n"; });

    // 运行 io_context，处理异步操作
    io_context.run();

    return 0;
}

/*
g++ -g -o test_async_sleep.out test_async_sleep.cpp


*/