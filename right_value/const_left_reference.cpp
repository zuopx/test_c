/*

int &a = std::move(1); // 不合法，非常量左引用无法引用右值
const int &b = std::move(1); // 合法, 常量左引用允许引用右值

g++ -o const_left_reference.out const_left_reference.cpp
*/
#include <iostream>
using namespace std;

void increase(int &v) { ++v; }

void test_1() {
  double s = 1;
  increase(s);  // error: cannot bind non-const lvalue reference of type ‘int&’ to a value of type ‘double’

  cout << s << endl;
}

void test_2() {
  int s = 1;
  increase(s);

  cout << s << endl;
}

int main() {
  test_1();
  test_2();

  return 0;
}
