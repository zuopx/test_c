//
// 2.13.alias.template.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U> class MagicType {
public:
  T dark;
  U magic;
};

// illegal
// template<typename T>
// typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;

typedef int (*process)(void *);
using NewProcess = int (*)(void *);
template <typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
  // FakeDarkMagic<bool> me;
  TrueDarkMagic<bool> you;
}

/*
g++ -o 2.13.alias.template.out 2.13.alias.template.cpp

- typedef作用于类型，模板不是类型，模板是产生类型
- using 比 typedef 更直观
*/
