// C++20引入了协程（coroutines）这一强大的语言特性，使得异步编程和生成器（generators）的实现更加简洁。
// 协程的核心概念包括 `co_await`、`co_yield` 和 `co_return`。

// 下面是一个详细的示例，展示如何使用这些关键字来实现简单的生成器和异步任务。

// ### 示例：异步任务

// 接下来，我们来看一个简单的异步任务示例，它使用 `co_await` 和 `co_return`。

// ### 解释

// - **`promise_type`**：定义了任务的承诺类型。
// - **`Awaitable`**：定义了一个可等待对象，它在 `await_suspend` 中模拟了一个异步操作。
// - **`co_await`**：等待异步操作完成。
// - **`co_return`**：返回任务

#include <coroutine>
#include <iostream>
#include <thread>
#include <chrono>

struct Task {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        auto get_return_object() {
            return Task{handle_type::from_promise(*this)};
        }
        auto initial_suspend() {
            return std::suspend_always{};
        }
        auto final_suspend() noexcept {
            return std::suspend_always{};
        }
        void return_void() {}
        void unhandled_exception() {
            std::exit(1);
        }
    };

    handle_type coro;

    Task(handle_type h) : coro(h) {}
    ~Task() {
        if (coro) coro.destroy();
    }

    void resume() {
        coro.resume();
    }
};

struct Awaitable {
    bool await_ready() {
        return false;
    }
    void await_suspend(std::coroutine_handle<> h) {
        std::thread([h]() {
            std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟异步操作
            h.resume();
        }).detach();
    }
    void await_resume() {}
};

Task async_task() {
    std::cout << "Task started." << std::endl;
    co_await Awaitable{};
    std::cout << "Task resumed after await." << std::endl;
    co_return;
}

int main() {
    auto task = async_task();
    std::cout << "Main function continues." << std::endl;
    task.resume();
    std::this_thread::sleep_for(std::chrono::seconds(3)); // 让主线程等待足够长的时间以便看到异步任务完成
    std::cout << "Main function ends." << std::endl;
    return 0;
}
