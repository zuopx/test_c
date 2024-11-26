//
// 3.4.historical.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

int main() {
    // int &a = std::move(1); // illegal, non-const lvalue reference cannot ref
    // rvalue
    int a = 1;
    const int &b = std::move(a); // legal, const lvalue reference can
    int &&c = std::move(a);

    // same
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    std::cout << &c << std::endl;
}


/*
g++ -o 3.4.historical.out 3.4.historical.cpp

为什么，常量引用允许指向右值？历史原因
*/
