#include <iostream>
using namespace std;

int main()
{
    int a = 1;

    auto add = [a](int x, int y) {return a * x + y;};

    cout << add(1, 2) << endl;
    
    return 0;
}

/*
cpu眼里的lambda表达式：
    在 C++ 中，函数中可以声明类型，这种做法通常被称为“局部类型”（Local Type）或“局部类”（Local Class）声明。
    当你编写 lambda 表达式并编译代码时，编译器会将 lambda 表达式转换为一个匿名的函数对象（即一个类）。
    这个类通常会实现 `operator()`，允许它像普通函数一样被调用。
    捕获变量的机制也会被编译器处理。当 lambda 表达式捕获外部变量时，这些变量会被存储在 lambda 对象的成员变量中。

```
#include <iostream>
using namespace std;

int main()
{
  int a = 1;
    
  class __lambda_8_16
  {
    public: 
    inline  int operator()(int x, int y) const
    {
      return (a * x) + y;
    }
    
    private: 
    int a;
    
    public:
    __lambda_8_16(int & _a)
    : a{_a}
    {}
    
  };
  
  __lambda_8_16 add = __lambda_8_16{a};
  std::cout.operator<<(add.operator()(1, 2)).operator<<(std::endl);
  return 0;
}
```
*/
