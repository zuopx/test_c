// 当然！下面是一个示例，演示如何使用 C++ 迭代器遍历一个简单的字符串，并打印 "Hello, World!"。

// 我们将使用 C++ 标准库中的迭代器来遍历字符串并打印字符。

// ### 示例代码
// ### 解释

// 1. **初始化字符串**：
//     - 我们声明并初始化一个 `std::string` 类型的变量 `message`，其内容为 "Hello, World!".

// 2. **使用迭代器遍历字符串**：
//     - `message.begin()` 返回指向字符串第一个字符的迭代器。
//     - `message.end()` 返回指向字符串末尾（终止位置）的迭代器。
//     - 使用 `for` 循环和迭代器来遍历字符串中的每个字符。
//     - `*it` 解引用迭代器，获取当前字符，并将其打印到标准输出。
//     - 迭代器 `++it` 指向下一个字符。

// 3. **打印换行**：
//     - 在循环结束后，打印一个换行符。

#include <iostream>
#include <string>

int main() {
    std::string message = "Hello, World!";

    // 使用迭代器遍历字符串
    for (auto it = message.begin(); it != message.end(); ++it) {
        std::cout << *it;
    }

    std::cout << std::endl;

    return 0;
}
