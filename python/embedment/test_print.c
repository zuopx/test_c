/*
gcc -o test_print.out -g test_print.c -I/usr/include/python3.11 -lpython3.11
*/

#include <Python.h>

int main()
{
    Py_Initialize();                                   // 初始化Python环境
    PyRun_SimpleString("print('Hello from Python!')"); // 执行Python代码
    Py_Finalize();                                     // 释放资源
    return 0;
}
