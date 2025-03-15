#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "[DEBUG] " << __FILE__ << ":" << __LINE__ << " in " << __FUNCTION__ << " [" << __DATE__ << " "
              << __TIME__ << "] - " << __cplusplus << std::endl;
    return 0;
}

/*
- `__FILE__`：当前源文件的名称（字符串常量）。
- `__LINE__`：当前行号。
- `__FUNCTION__`：当前函数的名称（在 C++11 及更高版本中可以使用 `__func__`）。
- `__PRETTY_FUNCTION__`：当前函数的完整签名（仅在某些编译器中可用，如 GCC 和 Clang）。
- `__DATE__`：包含当前日期的字符串（例如 "Sep 24 2023"）。
- `__TIME__`：包含当前时间的字符串（例如 "14:30:00"）。
- `__cplusplus`：表示 C++ 的版本号（例如，C++11 的值是 201103L）。

percy@home:~/project/c/test_c/misc$ g++ -g -o test_log.out test_log.cpp
percy@home:~/project/c/test_c/misc$ ./test_log.out
[DEBUG] test_log.cpp:5 in main [Mar 15 2025 15:35:47] - 201703
percy@home:~/project/c/test_c/misc$ g++ -g -o test_log.out test_log.cpp -std=c++20
percy@home:~/project/c/test_c/misc$ ./test_log.out
[DEBUG] test_log.cpp:5 in main [Mar 15 2025 15:36:03] - 202002
*/
