//
// 7.4.futures.cpp
// chapter 7 parallelism and concurrency
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <future>
#include <iostream>
#include <thread>

int main() {
  // pack a lambda expression that returns 7 into a std::packaged_task
  std::packaged_task<int()> task([]() { return 7; });
  // get the future of task
  std::future<int> result = task.get_future(); // run task in a thread
  std::thread(std::move(task)).detach();
  std::cout << "waiting...";
  result.wait(); // block until future has arrived
  // output result
  std::cout << "done!" << std::endl
            << "future result is " << result.get() << std::endl;
  return 0;
}


/*
g++ -o 7.4.futures.out 7.4.futures.cpp

std::future: 用于获取进程返回值（必定是异步的），而且也起到阻塞的作用

std::packaged_task<int()> task([]() { return 7; });
std::thread(std::move(task)).detach();
1. **`std::packaged_task<int()>`**:
  - 这里创建了一个 `std::packaged_task` 对象，类型为 `int()`，这意味着它可以包装一个不带参数并返回 `int` 的可调用对象。
  - 通过传递一个 lambda 表达式 `[]() { return 7; }`，你创建了一个简单的任务，该任务在执行时返回 `7`。
2. **`std::thread(std::move(task))`**:
  - 你使用 `std::move` 将 `task` 移动到新的 `std::thread` 对象中。`std::packaged_task` 是可移动的，但不可拷贝的，因此必须使用 `std::move` 来将其转移到线程中。
  - 这里会将 `task` 的所有权移交给新创建的线程。
3. **`.detach()`**:
  - `detach()` 方法将线程与主线程分离，使其在后台独立运行。一旦线程被分离，它将继续执行，即使主线程结束，分离的线程仍会继续运行。
  - 注意，分离的线程一旦开始执行，就无法再通过 `std::thread` 对象与之交互。
*/
