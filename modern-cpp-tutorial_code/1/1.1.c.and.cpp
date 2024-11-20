//
// 1.1.cpp
//
// chapter 1 introduction
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include "foo.h"
#include <functional>
#include <iostream>

int main() {
  // use lambda expression
  [out = std::ref(std::cout << "Result from C code: " << add(1, 2))]() {
    out.get() << ".\n";
  }();
  return 0;
}
