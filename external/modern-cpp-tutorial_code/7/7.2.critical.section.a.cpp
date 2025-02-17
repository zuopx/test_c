//
// 7.2.critical.section.a.cpp
// chapter 7 parallelism and concurrency
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void critical_section(int change_v) {
  static std::mutex mtx;
  std::lock_guard<std::mutex> lock(mtx);

  // do contention operations
  v = change_v;

  // mtx will be destructed when exit this region
}

int main() {
  std::thread t1(critical_section, 2), t2(critical_section, 3);
  t1.join();
  t2.join();

  std::cout << v << std::endl;
  return 0;
}


/*
g++ -o 7.2.critical.section.a.out 7.2.critical.section.a.cpp
watch -n 1 ./7.2.critical.section.a.out

std::mutex: 互斥量
std::lock_guard: RAII机制对象
    std::lock_guard<std::mutex> lock(mtx): 作用域结束时，会自动释放mtx
*/
