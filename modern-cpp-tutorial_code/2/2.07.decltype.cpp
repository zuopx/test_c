//
// 2.7.decltype.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <type_traits>

int main() {
  auto x = 1;
  auto y = 2;
  decltype(x + y) z = 3;
  if (std::is_same<decltype(x), int>::value)
    std::cout << "type x == int" << std::endl;
  if (std::is_same<decltype(x), float>::value)
    std::cout << "type z == float" << std::endl;
  if (std::is_same<decltype(x), decltype(z)>::value)
    std::cout << "type z == type x" << std::endl;
  return 0;
}

/*
g++ -o 2.07.decltype.out 2.07.decltype.cpp

- **标准性**：`decltype` 是 C++11 的标准部分，任何符合 C++11 标准的编译器都支持它。`typeof` 是 GCC 和 Clang 的扩展，不是 C++ 标准的一部分。
- **功能**：`decltype` 可以用于更复杂的表达式，并且与函数返回类型、模板类型推导等场景更兼容。`typeof` 更简单，通常只能用于变量。
*/