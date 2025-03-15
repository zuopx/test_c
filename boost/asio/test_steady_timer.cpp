#include <boost/asio.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <chrono>
#include <iostream>

using namespace boost::asio;

// 协程函数，使用 steady_timer
awaitable<void> wait_for_seconds(int seconds)
{
    // 创建一个 io_context 对象
    auto exec = co_await this_coro::executor;
    steady_timer timer(exec);

    // 设置定时器
    timer.expires_after(std::chrono::seconds(seconds));

    std::cout << "Timer set for " << seconds << " seconds.\n";

    // 挂起协程，直到定时器到期
    co_await timer.async_wait(use_awaitable);

    std::cout << "Timer expired after " << seconds << " seconds.\n";
}

// 协程的入口点
awaitable<void> start()
{
    co_await wait_for_seconds(5); // 等待 5 秒
}

int main()
{
    // 创建 io_context
    boost::asio::io_context io_context;

    // 启动协程
    co_spawn(io_context, start(), detached);

    // 运行 io_context
    io_context.run();

    return 0;
}

/*
g++ -g -o test_steady_timer.out test_steady_timer.cpp -std=c++20
*/
