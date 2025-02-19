#include <iostream>
#include <boost/type_index.hpp>

template <typename T>
void f(T&& arg) {
    // arg 是一个完美转发的引用，具体类型依赖于传入的类型
    std::cout << "Type of arg: " << boost::typeindex::type_id_with_cvr<decltype(arg)>().pretty_name() << std::endl;
}

int main() {
    int x = 10;

    f(x); // T 是 int&，arg 的类型为 int&
    f(20); // T 是 int，arg 的类型为 int&&

    // 使用引用折叠的例子
    using LValueRef = int&; // 左值引用
    using RValueRef = int&&; // 右值引用

    using Fold1 = LValueRef&; // 折叠为 LValueRef = int&
    using Fold2 = RValueRef&; // 折叠为 LValueRef = int&
    using Fold3 = LValueRef&&; // 折叠为 LValueRef = int&
    using Fold4 = RValueRef&&; // 折叠为 RValueRef = int&&

    std::cout << std::is_same<Fold1, int&>::value << std::endl; // 输出 1 (true)
    std::cout << std::is_same<Fold2, int&>::value << std::endl; // 输出 1 (true)
    std::cout << std::is_same<Fold3, int&>::value << std::endl; // 输出 1 (true)
    std::cout << std::is_same<Fold4, int&&>::value << std::endl; // 输出 1 (true)

    return 0;
}

/*
都是主要用于模板中：
1. **完美转发**: 当你希望将一个参数转发给另一个函数，保持其值类别（左值或右值）时，引用折叠可以帮助你正确处理这些引用。
2. **引用折叠**: 用于类型推导，T& &&，T&& &，T& &会折叠为T&，T&& &&会折叠为T&&。
*/