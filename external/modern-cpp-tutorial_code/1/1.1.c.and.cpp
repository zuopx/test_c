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


/*
c和cpp共存时，分开编译再链接

gcc -c -o foo.o foo.c
g++ -o 1.1.c.and.out 1.1.c.and.cpp foo.o
*/
