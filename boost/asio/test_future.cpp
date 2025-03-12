#include <future>
#include <iostream>
#include <thread>

int main()
{
    // 异步任务返回 42
    std::future<int> fut = std::async([] {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return 42;
    });

    // 1. 使用 wait()：仅等待完成
    fut.wait(); // 阻塞直到任务完成
    std::cout << "任务已完成\n";

    // 2. 使用 get()：获取结果（且只能调用一次）
    int value = fut.get(); // 正确：获取结果
    // int value2 = fut.get(); // 错误！future 已失效

    std::cout << "结果值: " << value << "\n";
    return 0;
}
