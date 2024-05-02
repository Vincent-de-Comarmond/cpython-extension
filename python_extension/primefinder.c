#define PY_SSIZE_T_CLEAN
#include <python3.12/Python.h>
#include "primefinderfunc.h"

static PyObject *c_primefinderfunction(PyObject *self, PyObject *args)
{
    int desiredPrimes;
    if (!PyArg_ParseTuple(args, "i", &desiredPrimes))
    {
        return NULL;
    }

    long primes[desiredPrimes];
    generatePrimes(desiredPrimes, primes);

    PyObject *list = PyList_New(desiredPrimes);
    for(int i=0; i < desiredPrimes; i++) {
        PyObject* python_int = Py_BuildValue("l", primes[i]);
        PyList_SetItem(list, i, python_int);
    }

    return list;
}


static PyMethodDef module_methods[] = {
    {"find_primes", *c_primefinderfunction, METH_VARARGS, "Find the prime numbers."},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef c_primefinder = {
    PyModuleDef_HEAD_INIT,
    "c_primefinder", // the name of the module in Python
    "",              // The docstring in Python
    -1, /* size of per-interpreter state of the module, or -1 if the module
           keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_c_primefinder(void)
{
    return PyModule_Create(&c_primefinder);
}
