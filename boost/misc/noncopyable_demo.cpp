/*
**禁止复制**：通过继承
`boost::noncopyable`，编译器会自动删除类的复制构造函数和复制赋值运算符。这使得类的对象不能被复制。 在 C++11
及以后的版本中，你可以使用 `delete` 关键字来显式删除复制构造函数和复制赋值运算符，从而获得和 `boost::noncopyable`
类似的效果。

clang-format -i --style=Microsoft noncopyable_demo.cpp
g++ -o noncopyable_demo.out -I/root/project/c/boost_1_85_0 noncopyable_demo.cpp
    error: use of deleted function

编译器报错，无法用noexcept和gtest捕获（EXPECT_DEATH, EXPECT_EXIT, EXPECT_THROW）
*/
#include <boost/noncopyable.hpp>
#include <iostream>
// #include <gtest/gtest.h>

class MyNonCopyable1 : private boost::noncopyable
{
  public:
    MyNonCopyable1()
    {
        std::cout << "MyNonCopyable1 constructed." << std::endl;
    }

    void display() const
    {
        std::cout << "Hello from MyNonCopyable1." << std::endl;
    }
};

class MyNonCopyable2
{
  public:
    MyNonCopyable2()
    {
        std::cout << "MyNonCopyable2 constructed." << std::endl;
    }

    MyNonCopyable2(const MyNonCopyable2 &) = delete;
    MyNonCopyable2 &operator=(const MyNonCopyable2 &) = delete;

    void display() const
    {
        std::cout << "Hello from MyNonCopyable2." << std::endl;
    }
};

// 示例：尝试复制 MyNonCopyable
int main()
{

    MyNonCopyable1 obj1; //     
    MyNonCopyable1 obj2 = obj1;
    MyNonCopyable1 obj3{obj1};

    MyNonCopyable2 obj4;
    MyNonCopyable2 obj5 = obj4;
    MyNonCopyable2 obj6{obj4};

    return 0;
}
