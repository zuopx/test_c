//
// 3.1.lambda.basic.cpp
// chapter 03 runtime enhancement
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <memory>  // std::make_unique
#include <utility> // std::move

void lambda_value_capture() {
    int value = 1;
    auto copy_value = [value] { return value; };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // At this moment, stored_value == 1, and value == 100.
    // Because copy_value has copied when its was created.
}

void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value] { return value; };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // At this moment, stored_value == 100, value == 100.
    // Because copy_value stores reference
}

void lambda_expression_capture() {
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;
}

void lambda_generic() {
    auto generic = [](auto x, auto y) { return x + y; };

    std::cout << generic(1, 2) << std::endl;
    std::cout << generic(1.1, 2.2) << std::endl;
}

int main() {
    lambda_value_capture();
    lambda_reference_capture();
    lambda_expression_capture();
    lambda_generic();
    return 0;
}


/*
g++ -o 3.1.lambda.basic.out 3.1.lambda.basic.cpp

lambda: [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {函数体}

-   [] 空捕获列表
-   [name1, name2, . . . ] 捕获一系列变量
-   [&] 引用捕获, 从函数体内的使用确定引用捕获列表
-   [=] 值捕获, 从函数体内的使用确定值捕获列表

std::make_unique: 分配内存并返回std::unique_ptr，自动管理对象声明周期（离开作用域时自动销毁）
std::move: 将左值转换成右值

在上面的代码中，important 是一个独占指针，是不能够被 “=” 值捕获到，
这时候我们可以将其转移为右值，在表达式中初始化。
*/
