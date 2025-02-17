//
// 9.3.alignment.cpp
// chapter 09 others
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

struct Storage {
  char a;
  int b;
  double c;
  long long d;
};

struct alignas(max_align_t) AlignasStorage {
  char a;
  int b;
  double c;
  long long d;
};

int main() {
  std::cout << alignof(Storage) << std::endl;
  std::cout << alignof(AlignasStorage) << std::endl;
  return 0;
}


/*
g++ -o 9.3.alignment.out 9.3.alignment.cpp
*/
