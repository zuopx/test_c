//
// 5.2.unique.ptr.cpp
// chapter 05 start pointers and memory management
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <memory>

struct Foo {
  Foo() { std::cout << "Foo::Foo" << std::endl; }
  ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
  void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) { std::cout << "f(const Foo&)" << std::endl; }

int main() {
  std::unique_ptr<Foo> p1(std::make_unique<Foo>());

  // p1 is not empty, prints
  if (p1)
    p1->foo();
  {
    std::unique_ptr<Foo> p2(std::move(p1));

    // p2 is not empty, prints
    f(*p2);

    // p2 is not empty, prints
    if (p2)
      p2->foo();

    // p1 is empty, no prints
    if (p1)
      p1->foo();

    p1 = std::move(p2);

    // p2 is empty, no prints
    if (p2)
      p2->foo();
    std::cout << "p2 was destroyed" << std::endl;
  }
  // p1 is not empty, prints
  if (p1)
    p1->foo();

  // Foo instance will be destroyed when leaving the scope
}


/*
g++ -o 5.2.unique.ptr.out 5.2.unique.ptr.cpp

std::uinque_ptr: 可转移专属所有权智能指针，可根据其所有权状态隐式转换为布尔值
    auto p2 = p1: illegal, unique_ptr(const unique_ptr&) = delete;
    auto p2 = std::move(p1): legal
*/
