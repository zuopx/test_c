/*模版的报错信息很长

g++ -o too_many_traceback_info.out too_many_traceback_info.cpp 2> traceback.txt

将产生200多行报错信息，其中大部分是在做重载决议，例如：
/usr/include/c++/12/ostream:166:23: note:   no known conversion for argument 1 from ‘A’ to ‘long int’
  166 |       operator<<(long __n)
      |                  ~~~~~^~~
*/

#include <iostream>
using namespace std;

struct A {};

int main() {
    std::cout << A{} << std::endl;  // error: no match for ‘operator<<’
    return 0;
}
