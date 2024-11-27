//
// 7.6.bad.example.cpp
// chapter 7 parallelism and concurrency
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <thread>

int main() {
  int a = 0;
  volatile int flag = 0;

  std::thread t1([&]() {
    while (flag != 1)
      ;

    int b = a;
    std::cout << "b = " << b << std::endl;
  });

  std::thread t2([&]() {
    a = 5;
    flag = 1;
  });

  t1.join();
  t2.join();
  return 0;
}


/*
g++ -o 7.6.bad.example.out 7.6.bad.example.cpp

volatile int flag = 0;
volatile保证了，编译器不会把 `while (flag != 1)` 优化成 `while (false)`

std::thread t2([&]() {
  a = 5;
  flag = 1;
});
虽然在源码上两条赋值语句有明确的先后顺序，但由于编译器的优化（或调整），其先后顺序是可能翻转了。
*/
