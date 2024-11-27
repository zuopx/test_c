//
// 7.1.thread.basic.cpp
// chapter 7 parallelism and concurrency
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <thread>

int main() {
  std::thread t([]() { std::cout << std::this_thread::get_id() << " hello world." << std::endl; });
  t.join();
  return 0;
}


/*
g++ -o 7.1.thread.basic.out 7.1.thread.basic.cpp

get_id: 返回线程id
t.join(): `block` the calling thread until t finishes execution.
*/
