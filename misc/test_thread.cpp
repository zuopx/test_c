#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>

// 共享资源
std::mutex mtx;
int shared_counter = 0;

// 基础线程函数
void thread_task(int *id)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread " << *id << " started\n";
}

// 带异常处理的线程函数
void risky_task(int x)
{
    try
    {
        if (x % 2 == 0)
        {
            throw std::runtime_error("Even number error!");
        }
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Processed " << x << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in thread: " << e.what() << std::endl;
    }
}

int main()
{
    const int NUM_THREADS = 5;
    std::vector<std::thread> workers;

    // 1. 基础线程创建
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        workers.emplace_back(thread_task, &i);
    }

    // 等待所有线程完成
    for (auto &t : workers)
    {
        if (t.joinable())
            t.join();
    }
    workers.clear();

    std::cout << "\n--- Advanced Example ---\n";

    // 2. Lambda表达式 + 引用传递
    auto lambda_task = [](int &count) {
        for (int i = 0; i < 3; ++i)
        {
            std::lock_guard<std::mutex> lock(mtx);
            ++count;
            std::cout << "Count: " << count << std::endl;
        }
    };

    int lambda_counter = 0;
    std::thread t1(lambda_task, std::ref(lambda_counter));  // 传递引用参数时必须使用 std::ref
    std::thread t2(lambda_task, std::ref(lambda_counter));

    t1.join();
    t2.join();
    std::cout << "Final count: " << lambda_counter << "\n";

    // 3. 异常处理演示
    std::vector<std::thread> error_workers;
    for (int i = 1; i <= 3; ++i)
    {
        error_workers.emplace_back(risky_task, i);
    }

    for (auto &t : error_workers)
    {
        if (t.joinable())
            t.join();
    }

    // 4. 资源竞争演示
    std::thread race1([] {
        for (int i = 0; i < 10000; ++i)
        {
            std::lock_guard<std::mutex> lock(mtx);
            ++shared_counter;
        }
    });

    std::thread race2([] {
        for (int i = 0; i < 10000; ++i)
        {
            std::lock_guard<std::mutex> lock(mtx);
            ++shared_counter;
        }
    });

    race1.join();
    race2.join();
    std::cout << "\nSafe counter: " << shared_counter << std::endl;

    return 0;
}
