//
// 5.3.weak.ptr.cpp
// chapter 05 start pointers and memory management
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <memory>

class A;
class B;

class A {
public:
  std::weak_ptr<B> pointer;
  ~A() { std::cout << "A was destroyed" << std::endl; }
};
class B {
public:
  std::weak_ptr<A> pointer;
  ~B() { std::cout << "B was destroyed" << std::endl; }
};
int main() {
  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->pointer = b;
  b->pointer = a;

  return 0;
}


/*
g++ -o 5.3.weak.ptr.out 5.3.weak.ptr.cpp

weak_ptr是给shared_ptr打补丁的，shared_ptr无法处理循环引用。
weak_ptr.lock(): Returns a `std::shared_ptr` to the managed object if it still exists 会增加引用，需手动释放
weak_ptr.expired(): Returns `true` if the managed object has been destroyed.

usage:
- **Observer Pattern**: Use `std::weak_ptr` to keep track of observers without preventing their destruction.
- **Caching**: Use it to cache resources without preventing them from being freed when they are no longer needed.
- **Avoiding Cycles**: In graph-like data structures, to avoid cycles that prevent memory from being freed.
*/
