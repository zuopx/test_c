//
// 2.3.if.switch.cpp
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

  // after c++17, can be simplefied by using `auto`
  const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
  if (itr != vec.end()) {
    *itr = 3;
  }

  if (const std::vector<int>::iterator itr =
          std::find(vec.begin(), vec.end(), 3);
      itr != vec.end()) {
    *itr = 4;
  }

  // should output: 1, 4, 3, 4. can be simplefied using `auto`
  for (std::vector<int>::iterator element = vec.begin(); element != vec.end();
       ++element)
    std::cout << *element << std::endl;
}

/*
g++ -o 2.03.if.switch.out 2.03.if.switch.cpp

借鉴go语言，在if和switch表达式中，先求值，再断言
if (auto a = xxx; a != nullpt) {...}
*/