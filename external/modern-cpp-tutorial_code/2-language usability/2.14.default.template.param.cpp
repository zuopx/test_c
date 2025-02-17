//
// 2.4.default.template.param.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

template <typename T = int, typename U = int>
auto add(T x, U y) -> decltype(x + y) {
  return x + y;
}

int main() { std::cout << add(1, 2) << std::endl; }

/*
g++ -o 2.14.default.template.param.out 2.14.default.template.param.cpp

模板用于代码生成，可视为一门语言，所以有默认参数并不奇怪，只要编译器支持即可
*/
