//
// 2.18.non.type.template.auto.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

template <auto value> void foo() {
  std::cout << value << std::endl;
  return;
}

int main() {
  foo<10>(); // value is deduced as type int
}

/*
g++ -o 2.18.non.type.template.auto.out 2.18.non.type.template.auto.cpp

template<>
void foo<10>()
{
  std::cout.operator<<(10).operator<<(std::endl);
  return;
}
*/
