#include <Python.h>
#include "child.h"

// 父模块的函数
static PyObject *parent_hello(PyObject *self, PyObject *args)
{
    return PyUnicode_FromString("Hello from parent module!");
}

// 父模块的定义
static PyMethodDef ParentMethods[] = {
    {"hello", parent_hello, METH_VARARGS, "Greet from the parent module."},
    {NULL, NULL, 0, NULL} // Sentinel
};

// 模块定义
static struct PyModuleDef parentmodule = {
    PyModuleDef_HEAD_INIT,
    "parent",                           // name of module
    "Parent module for demonstration.", // module documentation
    0,                                  // size of per-interpreter state of the module
    ParentMethods};

// 模块初始化函数
PyMODINIT_FUNC PyInit_parent(void)
{
    PyObject *m = PyModule_Create(&parentmodule);
    if (m == NULL)
        return NULL;

    init_child(m);

    return m;
}
