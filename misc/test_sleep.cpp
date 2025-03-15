#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    std::cout << "开始执行..." << std::endl;

    // 休眠 1.5 秒
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    std::cout << "1.5 秒后继续执行" << std::endl;

    // 休眠 300 毫秒
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    std::cout << "再休眠 300 毫秒后结束" << std::endl;
    return 0;
}

/*
优先使用 C++11 的 std::this_thread::sleep_for，避免依赖平台特定的头文件。
所有延时函数均为线程安全，但需注意在 GUI 主线程中长时间休眠可能导致界面卡顿。

std::chrono::milliseconds, std::chrono::seconds 支持加法操作，具体见test_chrone.cpp
*/
