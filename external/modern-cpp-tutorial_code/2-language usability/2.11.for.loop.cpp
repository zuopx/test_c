//
// 2.11.for.loop.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4};
  if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())
    *itr = 4;
  for (auto element : vec)
    std::cout << element << std::endl; // read only
  for (auto &element : vec) {
    element += 1; // writeable
  }
  for (auto element : vec)
    std::cout << element << std::endl; // read only
}

/*
g++ -o 2.11.for.loop.out 2.11.for.loop.cpp

区间迭代（遍历）
*/
