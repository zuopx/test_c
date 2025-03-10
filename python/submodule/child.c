#include <Python.h>

static PyObject *child_greet(PyObject *self, PyObject *args)
{
    return PyUnicode_FromString("Hello from child module!");
}

// 子模块的定义
static PyMethodDef ChildMethods[] = {
    {"greet", child_greet, METH_VARARGS, "Greet from child module."},
    {NULL, NULL, 0, NULL} // Sentinel
};

// 子模块初始化函数
static PyModuleDef childmodule = {
    PyModuleDef_HEAD_INIT,
    "child",                          // name of module
    "Child module of parent module.", // module documentation
    0,                                // size of per-interpreter state of the module
    ChildMethods};

void init_child(PyObject *parent)
{
    PyObject *child = PyModule_Create(&childmodule);
    if (child == NULL)
    {
        PyErr_Print();
        return;
    }

    Py_XINCREF(child);
    if (PyModule_AddObject(parent, "child", child) == -1)
    {
        Py_DECREF(child);
        PyErr_Print();
    }
}
