#include <iostream>
#include <utility> // for std::forward

// 一个示例函数，接受左值或右值
void process(int& x) {
    std::cout << "Lvalue: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "Rvalue: " << x << std::endl;
}

// 完美转发的函数模板
template <typename T>
void forwardToProcess(T&& arg) {
    // 使用 std::forward 完美转发
    // process(arg)  // 左值
    // process(std::move(arg))  // 右值
    process(std::forward<T>(arg));  // 完美转发
}

int main() {
    int a = 10;
    forwardToProcess(a);         // 传递左值
    forwardToProcess(20);        // 传递右值

    return 0;
}
