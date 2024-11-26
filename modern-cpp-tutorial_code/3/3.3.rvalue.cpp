//
// 3.3.rvalue.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <string>

void reference(std::string &str) { std::cout << "lvalue" << std::endl; }
void reference(std::string &&str) { std::cout << "rvalue" << std::endl; }

int main() {
    std::string lv1 = "string,"; // lv1 is a lvalue
    // std::string&& r1 = lv1;           // illegal, rvalue can't ref to lvalue
    std::string &&rv1 =
        std::move(lv1); // legal, std::move can convert lvalue to rvalue
    std::cout << rv1 << std::endl; // string,

    const std::string &lv2 = lv1 + lv1; // legal, const lvalue reference can
                                        // extend temp variable's lifecycle
    // lv2 += "Test";                   // illegal, const ref can't be modified
    std::cout << lv2 << std::endl; // string,string

    std::string &&rv2 = lv1 + lv2; // legal, rvalue ref extend lifecycle
    rv2 += "string";               // legal, non-const reference can be modified
    std::cout << rv2 << std::endl; // string,string,string,

    reference(rv2); // output: lvalue

    return 0;
}


/*
g++ -o 3.3.rvalue.out 3.3.rvalue.cpp

首先reference的重载，形参分别为左值引用和右值引用，那么分别对应的实参为左值和右值

rv1和rv2的类型都是string&&，表示右值引用，也就是指向右值的指针！
为什么指针可以指向右值？为了延长右值的生命周期，减少拷贝、方便移动（所以就创建了这种语法）。

std::string&& rv3 = std::move(lv1);
std::string& lv3 = lv1;
std::cout << &rv3 << std::endl;
std::cout << &lv3 << std::endl;
结果表明，rv3和lv3都指向了同一地址
*/
