//
// 10.1.without.concepts.cpp
// chapter 10 cpp20
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <algorithm>
#include <list>

int main() {
  std::list<int> l = {1, 2, 3};
  std::sort(l.begin(), l.end()); // tons of compile error
  return 0;
}


/*
g++ -o 10.1.without.concepts.out 10.1.without.concepts.cpp 
*/
