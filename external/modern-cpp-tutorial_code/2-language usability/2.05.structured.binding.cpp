//
// 2.5.structured.binding.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, double, std::string> f() {
  return std::make_tuple(1, 2.3, "456");
}

int main() {
  auto [x, y, z] = f();
  std::cout << x << ", " << y << ", " << z << std::endl;
  return 0;
}

/*
g++ -o 2.05.structured.binding.out 2.05.structured.binding.cpp

新类型std::tuple和构造方法std::make_tuple
*/
