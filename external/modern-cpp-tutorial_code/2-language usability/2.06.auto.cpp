//
// 2.6.auto.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <initializer_list>
#include <iostream>
#include <vector>

class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }
};

int add(auto x, auto y) { // Supported in C++20
  return x + y;
}

int main() {
  MagicFoo magicFoo = {1, 2, 3, 4, 5};
  std::cout << "magicFoo: ";
  for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

  auto i = 5; // type int
  auto j = 6; // type int
  std::cout << add(i, j) << std::endl;

  auto arr = new auto(10); // type int*
  // auto auto_arr2[10] = {arr}; // invalid
  return 0;
}

/*
auto，类似模板，编译期间生成多个函数版本

g++ --std=c++20 -o 2.06.auto.out 2.06.auto.cpp

c++20: auto可用于函数传参

auto不可用于推导数组类型
*/