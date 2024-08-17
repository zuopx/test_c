// 当然！下面是一个简单的 "Hello, World!" 示例，演示了如何使用 C++20 协程。
// 在这个示例中，我们将创建一个简单的协程，它将打印 "Hello" 和 "World"，并在两个输出之间暂停。

// ### 示例代码

// ### 解释

// 1. **HelloWorldCoro 结构体**：
//     - 包含一个 `promise_type` 结构体，该结构体定义了协程的行为。
//     - `get_return_object` 返回一个包含协程句柄的 `HelloWorldCoro` 对象。
//     - `initial_suspend` 和 `final_suspend` 控制协程在开始和结束时的行为。
//     - `yield_value` 处理 `co_yield` 关键字，保存当前值并暂停协程。
//     - `return_void` 是协程完成时调用的函数。

// 2. **协程返回对象**：
//     - `HelloWorldCoro` 结构体包含一个协程句柄。
//     - 构造函数和析构函数用于管理协程句柄的生命周期。
//     - `resume` 方法用于恢复协程，并检查协程是否完成。
//     - `current_value` 方法用于获取当前保存的值。

// 3. **hello_world 协程**：
//     - 这个协程依次生成 "Hello" 和 "World"。

// 4. **main 函数**：
//     - 创建一个 `HelloWorldCoro` 对象并循环恢复协程，打印每次 `co_yield` 的值。

// ### 编译

// 确保使用支持 C++20 标准的编译器，如 GCC 10 或更高版本，或者 Clang 10 或更高版本。编译命令如下：

// ```sh
// g++ -std=c++20 -o hello_world hello_world.cpp
// ```

// 如果你使用的是 MSVC 编译器，请确保在项目设置中启用 C++20 标准。

#include <iostream>
#include <coroutine>
#include <string>

struct HelloWorldCoro {
    struct promise_type {
        auto get_return_object() { return HelloWorldCoro{std::coroutine_handle<promise_type>::from_promise(*this)}; }
        auto initial_suspend() { return std::suspend_always{}; }
        auto final_suspend() noexcept { return std::suspend_always{}; }
        void unhandled_exception() { std::terminate(); }
        void return_void() {}
        auto yield_value(const std::string& value) {
            current_value = value;
            return std::suspend_always{};
        }

        std::string current_value;
    };

    std::coroutine_handle<promise_type> handle;

    HelloWorldCoro(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~HelloWorldCoro() { if (handle) handle.destroy(); }

    bool resume() {
        if (handle.done()) return false;
        handle.resume();
        return !handle.done();
    }

    std::string current_value() {
        return handle.promise().current_value;
    }
};

HelloWorldCoro hello_world() {
    co_yield "Hello";
    co_yield "World";
}  // return a coro object by HelloWorldCoro.promise_type.get_return_object

int main() {
    auto coro = hello_world();
    while (coro.resume()) {
        std::cout << coro.current_value() << " ";
    }
    std::cout << std::endl;
    return 0;
}
