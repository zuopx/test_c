//
// 3.5.move.semantics.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
class A {
  public:
    int *pointer;
    A() : pointer(new int(1)) {
        std::cout << pointer << " construct " << this << std::endl;
    }
    A(A &a) : pointer(new int(*a.pointer)) {
        std::cout << pointer << " copy " << this << std::endl;
    } // meaningless object copy
    A(A &&a) : pointer(a.pointer) {
        a.pointer = nullptr;
        std::cout << pointer << " move " << this  << std::endl;
    }
    ~A() {
        std::cout << pointer << " destruct " << this  << std::endl;
        delete pointer;
    }
};
// avoid compiler optimization
A return_rvalue(bool test) {
    A a, b;
    if (test)
        return a; // equal to static_cast<A&&>(a);
    else
        return b; // equal to static_cast<A&&>(b);
}
int main() {
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;
    return 0;
}


/*
g++ -o 3.5.move.semantics.out 3.5.move.semantics.cpp

A obj = return_rvalue(false)
对于return_rvalue的返回值，编译器将根据A是否定义移动构造函数，分别返回左值和右值；进而触发A不同的构造函数；
通常，在拷贝构造函数中，实现深拷贝；在移动构造函数中，实现浅拷贝；
无论是深拷贝还是浅拷贝，obj和a、b都对应不同的内存地址(this)

无移动构造函数：
A return_rvalue(bool test)
{
  A a = A();
  A b = A();
  if(test) {
    return A(a);
  } else {
    return A(b);
  }  
}

有移动构造函数：
A return_rvalue(bool test)
{
  A a = A();
  A b = A();
  if(test) {
    return A(static_cast<A &&>(a));
  } else {
    return A(static_cast<A &&>(b));
  } 
}
*/
