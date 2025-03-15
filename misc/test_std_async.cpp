#include <chrono>
#include <future>
#include <iostream>
#include <thread>

void async_sleep(int ms, std::function<void()> callback)
{
    std::async(std::launch::async, [ms, callback] {
        std::cout << "异步任务所在线程：" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        callback();
    });
}

int main()
{
    async_sleep(2000, [] { std::cout << "2秒后执行的回调" << std::endl; });

    std::cout << "主线程继续运行：" << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3)); // 等待异步任务完成
    return 0;
}
