/*
g++ -o 2.04.initializer.list.out 2.04.initializer.list.cpp

统一的初始化语法（大括号初始化）：Foo foo(1, 2) 等效于 Foo foo{1, 2}

初始化列表std::initializer_list，“飞入寻常百姓家”
*/

#include <initializer_list>
#include <iostream>
#include <vector>

class Foo {
public:
  int value_a;
  int value_b;
  Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list) {
    for (auto it = list.begin();
         it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }
  void foo(std::initializer_list<int> list) {
    for (auto it = list.begin();
         it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }
};

int main() {
  // before C++11
  int arr[3] = {1, 2, 3};
  Foo foo(1, 2);
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // after C++11
  MagicFoo magicFoo = {1, 2, 3, 4, 5};
  magicFoo.foo({6, 7, 8, 9});
  Foo foo2{3, 4};

  std::cout << "arr[0]: " << arr[0] << std::endl;
  std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
  std::cout << "vec: ";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << "magicFoo: ";
  for (auto it = magicFoo.vec.begin();
       it != magicFoo.vec.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << "foo2: " << foo2.value_a << ", " << foo2.value_b << std::endl;

  return 0;
}
