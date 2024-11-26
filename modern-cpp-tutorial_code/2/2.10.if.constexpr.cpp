//
// 2.10.if.constexpr.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

template <typename T> auto print_type_info(const T &t) {
  if constexpr (std::is_integral<T>::value) {
    return t + 1;
  } else {
    return t + 0.001;
  }
}

// at compiling time
// int print_type_info(const int& t) {
//     return t + 1;
// }
// double print_type_info(const double& t) {
//     return t + 0.001;
// }

int main() {
  std::cout << print_type_info(5) << std::endl;
  std::cout << print_type_info(3.14) << std::endl;
}

/*
g++ -o 2.10.if.constexpr.out 2.10.if.constexpr.cpp

将constexpr用于分支语句，可在编译阶段就完成分支判断；上面的模板函数会展开为：
int print_type_info(const int& t) {
  return t + 1;
}
double print_type_info(const double& t) {
  return t + 0.001;
}
*/
