//
// 5.1.shared.ptr.cpp
// chapter 05 smart pointers and memory management
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i) { (*i)++; }

int main() {
  // auto pointer = new int(10); // illegal, no direct assignment
  // std::shared_ptr construction
  auto pointer = std::make_shared<int>(10);
  auto pointer2 = pointer; // reference count + 1
  auto pointer3 = pointer; // reference count + 1

  foo(pointer);
  std::cout << *pointer << std::endl; // 11
  int *p = pointer.get();             // does not increase reference count

  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

  pointer2.reset();
  std::cout << "reset pointer2:" << std::endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

  pointer3.reset();
  std::cout << "reset pointer3:" << std::endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;
  // std::cout << *pointer << std::endl; // reference count equals 0, illegal
  // access

  // Before leaving the scope, the pointer is destructed and
  // the reference count is reduced to 0
  auto a = std::move(pointer);
  std::cout << *p << *a << std::endl;

  return 0;
}


/*
g++ -o 5.1.shared.ptr.a.out 5.1.shared.ptr.a.cpp 

use_count: 返回引用计数，当引用计数为0时，回收对象

共享指针拥有单个动态对象的可转移非专属所有权
    auto pointer = std::make_shared<int>(10);
    移动语义：auto a = std::move(pointer); --> pointer.use_count == 0, a.use_count == 1
    复制语义：auto a = pointer; --> pointer.use_count == 2, a.use_count == 2

    使用移动语义后，如果执行"*pointer"，将触发"segmentation falut"
*/
