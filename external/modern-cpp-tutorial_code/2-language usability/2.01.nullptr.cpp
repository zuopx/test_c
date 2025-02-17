//
// 2.1.nullptr.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <type_traits>

void foo(char *);
void foo(int);

int main() {
  if (std::is_same<decltype(NULL), decltype(0)>::value)
    std::cout << "NULL == 0" << std::endl;
  if (std::is_same<decltype(NULL), decltype((void *)0)>::value)
    std::cout << "NULL == (void *)0" << std::endl;
  if (std::is_same<decltype(NULL), std::nullptr_t>::value)
    std::cout << "NULL == nullptr" << std::endl;

  foo(0); // will call foo(int)
  // foo(NULL);    // doesn't compile
  foo(nullptr); // will call foo(char*)
  return 0;
}

void foo(char *) { std::cout << "foo(char*) is called" << std::endl; }
void foo(int i) { std::cout << "foo(int) is called" << std::endl; }

/*
g++ -o 2.01.nullptr.out 2.01.nullptr.cpp

- `NULL` 可能被定义为 `0` 或 `((void*)0)`，在某些情况下可能会导致类型不明确。
- `nullptr` 是 `std::nullptr_t` 类型的对象，类型安全，能够清晰地表示空指针。

foo(NULL) -> error: call of overloaded ‘foo(NULL)’ is ambiguous
*/
