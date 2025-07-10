/*
c++程序示例，分主线程和从线程，写数据放在主线程，读数据放在从线程。

在 C++ 中，您可以使用标准库中的线程功能（`<thread>`）来创建主线程和从线程，以便在一个线程中写数据，而在另一个线程中读取数据。为了保证线程安全，您可以使用互斥量（`std::mutex`）来同步访问共享数据。下面是一个示例程序，展示了主线程写数据，而从线程读数据：
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

std::vector<int> data; // 共享数据
std::mutex data_mutex; // 互斥量用于保护共享数据

// 从线程执行的函数
void reader()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 休眠以模拟读取数据的延迟

        std::lock_guard<std::mutex> lock(data_mutex); // 锁定互斥量
        if (!data.empty())
        {
            int value = data.back(); // 读取数据
            data.pop_back();         // 移除已读取的数据
            std::cout << "Reader thread read: " << value << std::endl;
        }
        else
        {
            std::cout << "Reader thread found no data." << std::endl;
        }
    }
}

int main()
{
    std::thread reader_thread(reader); // 创建并启动从线程

    // 主线程写数据
    for (int i = 0; i < 10; ++i)
    {
        {
            std::lock_guard<std::mutex> lock(data_mutex); // 锁定互斥量
            data.push_back(i);                            // 写入数据
            std::cout << "Main thread wrote: " << i << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // 模拟写入延迟
    }

    // 等待一段时间让读取线程完成读取
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // 停止读取线程（在真实应用中，可以使用条件变量或其他机制通知线程停止）
    reader_thread.detach(); // 在本示例中，简单地分离读取线程（实际中应有更好的机制）

    return 0;
}

/*
### 程序说明：

1. **共享数据**：我们使用 `std::vector<int> data` 来存储主线程写入的数据。

2. **互斥量**：使用 `std::mutex data_mutex` 来保护对共享数据的访问，以防止在多个线程之间发生竞争条件。

3. **读取线程**：`reader` 函数是从线程执行的函数，它循环读取数据。在读取数据时，它会锁定互斥量以确保安全访问共享数据。

4. **主线程**：在 `main` 函数中，主线程写入数据，并在每次写入后休眠一段时间以模拟写入延迟。

5. **线程管理**：在这个例子中，我们使用 `detach` 来分离读取线程。在实际应用中，您可能希望使用条件变量或其他机制来优雅地停止线程。

### 注意事项：
- 在真实应用中，您应该有更好的线程终止机制，比如设置一个标志位来让读取线程安全退出。
- 确保在使用互斥量前加锁，释放锁后再访问共享数据。使用 `std::lock_guard` 是自动管理锁的好方法，确保在离开作用域时自动释放锁。
*/