/*
gcc -o test_import.out -g test_import.c -I/usr/include/python3.11 -lpython3.11

可同时对c,python代码进行断点；采用默认的attach调试配置。
*/
#include <stdio.h>
#include <Python.h>

int main(int argc, char *argv[])
{
    Py_Initialize(); // 初始化Python环境
    PyRun_SimpleString("import sys; sys.path.append('.')");
    getchar();

    // 导入Python模块并调用函数
    PyObject *pModule = PyImport_ImportModule("mymodule");
    PyObject *pFunc = PyObject_GetAttrString(pModule, "myfunc_noargs");
    PyObject *pResult = PyObject_CallObject(pFunc, NULL);
    long result = PyLong_AsLong(pResult);
    printf("myfunc_noargs return value: %ld\n", result);

    PyRun_SimpleString("print('Hello from Python!')"); // 执行Python代码
    Py_Finalize();                                     // 释放资源
    return 0;
}
