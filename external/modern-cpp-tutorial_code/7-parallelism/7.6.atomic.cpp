//
// 7.6.atomic.cpp
// chapter 7 parallelism and concurrency
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> count = {0};

int main() {
  std::thread t1([]() { count.fetch_add(1); });
  std::thread t2([]() {
    count++;    // identical to fetch_add
    count += 1; // identical to fetch_add
  });
  t1.join();
  t2.join();
  std::cout << count << std::endl;
  return 0;
}


/*
g++ -o 7.6.atomic.out 7.6.atomic.cpp

原子类型，提供原子操作，本质上也是锁，但是是CPU指令级别的锁（std::mutex是操作系统级别的锁）
*/
