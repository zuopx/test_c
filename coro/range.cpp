// 当然，这里有一个简化的例子，展示了如何使用 C++20 的协程来生成一个简单的整数序列。
// 这个例子主要展示了 `co_await` 的基本用法，以便让你能快速了解 C++20 协程的基本概念。

// ### 简单的整数生成器

// ### 解释

// 1. **`Generator` 结构体**：
//     - 包含一个 `promise_type` 结构体，该结构体定义了协程的行为。
//     - `get_return_object` 返回一个包含协程句柄的生成器对象。
//     - `initial_suspend` 和 `final_suspend` 控制协程在开始和结束时的行为。
//     - `yield_value` 处理 `co_yield` 关键字，保存当前值并暂停协程。
//     - `return_void` 是协程完成时调用的函数。

// 2. **协程返回对象**：
//     - `Generator` 结构体包含一个协程句柄。
//     - 构造函数和析构函数用于管理协程句柄的生命周期。

// 3. **迭代器**：
//     - 生成器对象提供了一个简单的迭代器接口，使得可以使用范围 `for` 循环来遍历生成的值。
//     - 迭代器在每次递增时恢复协程，检查协程是否完成。

// 4. **`generate_numbers` 协程**：
//     - 这个协程生成从 `start` 到 `end` 的数字，每次 `co_yield` 一个数字。

// 5. **`main` 函数**：
//     - 创建一个生成器对象并使用范围 `for` 循环来遍历生成的数字。

// ### 编译

// 确保使用支持 C++20 标准的编译器，如 GCC 10 或更高版本，或者 Clang 10 或更高版本。编译命令如下：

// ```sh
// g++ -std=c++20 -o my_program main.cpp
// ```

// 如果你使用的是 MSVC 编译器，请确保在项目设置中启用 C++20 标准。

// 通过这个简单的示例，你可以理解 C++20 协程的基本用法，并探索如何利用它来编写简洁且高效的异步代码。

#include <iostream>
#include <coroutine>

struct Generator {
    struct promise_type {
        int current_value;
        auto get_return_object() { return Generator{std::coroutine_handle<promise_type>::from_promise(*this)}; }
        auto initial_suspend() { return std::suspend_always{}; }
        auto final_suspend() noexcept { return std::suspend_always{}; }
        void unhandled_exception() { std::terminate(); }
        auto yield_value(int value) {
            current_value = value;
            return std::suspend_always{};
        }
        void return_void() {}
    };

    std::coroutine_handle<promise_type> handle;

    Generator(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~Generator() { if (handle) handle.destroy(); }

    // 迭代器相关函数
    struct iterator {
        std::coroutine_handle<promise_type> handle;

        iterator(std::coroutine_handle<promise_type> h) : handle(h) {}
        iterator& operator++() { 
            handle.resume(); 
            if (handle.done()) handle = nullptr;
            return *this;
        }
        int operator*() const { return handle.promise().current_value; }
        bool operator!=(std::nullptr_t) const { return handle != nullptr; }
    };

    iterator begin() { 
        handle.resume();
        return iterator{ handle }; 
    }
    std::nullptr_t end() { return nullptr; }
};

Generator generate_numbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        co_yield i;
    }
}

int main() {
    auto numbers = generate_numbers(1, 10);
    for (auto num : numbers) {
        std::cout << num << std::endl;
    }
    return 0;
}
