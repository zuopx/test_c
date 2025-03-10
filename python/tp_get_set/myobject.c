#include <Python.h>

typedef struct
{
    PyObject_HEAD int value;
} MyObject;

static PyObject *MyObject_getattro(MyObject *self, PyObject *name)
{
    if (PyUnicode_CompareWithASCIIString(name, "value") == 0)
    {
        return PyLong_FromLong(self->value);
    }
    PyErr_SetString(PyExc_AttributeError, "Attribute not found");
    return NULL;
}

static int MyObject_setattro(MyObject *self, PyObject *name, PyObject *value)
{
    if (PyUnicode_CompareWithASCIIString(name, "value") == 0)
    {
        if (!PyLong_Check(value))
        {
            PyErr_SetString(PyExc_TypeError, "The 'value' attribute must be an integer");
            return -1;
        }
        int *p = NULL;
        self->value = *p;
        // self->value = PyLong_AsLong(value);
        return 0;
    }
    PyErr_SetString(PyExc_AttributeError, "Attribute not found");
    return -1;
}

static PyTypeObject MyObjectType = {
    PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "example.MyObject",  // 您可以在结构体的初始化中选择性地初始化特定的成员，而不必按顺序提供所有成员的值。
    .tp_basicsize = sizeof(MyObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_init = NULL,
    .tp_new = PyType_GenericNew,
    .tp_getattro = (getattrofunc)MyObject_getattro,
    .tp_setattro = (setattrofunc)MyObject_setattro,
};

static PyModuleDef examplemodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "example",
    .m_doc = "Example module that creates a custom object.",
    .m_size = -1,
};

PyMODINIT_FUNC PyInit_myobject(void)
{
    PyObject *m;
    if (PyType_Ready(&MyObjectType) < 0)
        return NULL;

    m = PyModule_Create(&examplemodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&MyObjectType);
    PyModule_AddObject(m, "MyObject", (PyObject *)&MyObjectType);
    return m;
}


/*
PyUnicode_AsUTF8

PyLong_AsLong
*/
