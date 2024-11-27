//
// 3.6.perfect.forward.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <utility>

void reference(int &v)
{
    std::cout << "lvalue reference" << std::endl;
}
void reference(int &&v)
{
    std::cout << "rvalue reference" << std::endl;
}

template <typename T> void pass(T &&v)
{
    std::cout << "          normal param passing: ";
    reference(v);
    std::cout << "       std::move param passing: ";
    reference(std::move(v));
    std::cout << "    std::forward param passing: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> param passing: ";
    reference(static_cast<T &&>(v));
}

int main()
{
    std::cout << "rvalue pass:" << std::endl;
    pass(1);

    std::cout << "lvalue pass:" << std::endl;
    int l = 1;
    pass(l);

    return 0;
}


/*
g++ -o 3.7.perfect.forward.out 3.7.perfect.forward.cpp 

output:
    rvalue pass:
            normal param passing: lvalue reference
        std::move param passing: rvalue reference
        std::forward param passing: rvalue reference
    static_cast<T&&> param passing: rvalue reference
    lvalue pass:
            normal param passing: lvalue reference
        std::move param passing: rvalue reference
        std::forward param passing: lvalue reference
    static_cast<T&&> param passing: lvalue reference


首先，对于重载的reference，形参分别为左值引用和右值引用（也就是表示实参为左值和右值）
其次，对于模板形参T&&，仅当模板实参为右值时，模板参数才被真正推导为右值引用T&&；否则为左值引用T&
最后，引用折叠，对于T&&，假设T为int&，那么T&&=int&

所以（展开详情见3.7.insights.cpp）
pass(1) -> T:int -> pass(int&&)
pass(l) -> T:int& -> pass(int&)
*/
