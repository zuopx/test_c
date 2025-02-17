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
`extern "C"` 是一个用于实现 C 和 C++ 之间链接兼容性的特性。
它确保 C++ 编译器不会对 C 函数进行名称修饰（name mangling），从而允许在 C++ 中调用 C 函数。
（add函数用gcc编译，遵循的是c函数命名；如果g++要使用add函数，就要阻断对add的名称修饰）

c和cpp共存时，分开编译再链接
  gcc -c -o foo.o foo.c
  g++ -o 1.1.c.and.out 1.1.c.and.cpp foo.o

如果不加`extern "C"`，g++编译报错：
  /usr/bin/ld: /tmp/ccaGOq6t.o: in function `main':
  1.1.c.and.cpp:(.text+0x60): undefined reference to `add(int, int)'
*/
