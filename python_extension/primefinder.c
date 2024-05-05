#define PY_SSIZE_T_CLEAN // Python asks us to add this macro before any imports
#include <python3.12/Python.h> // BEWARE - this may vary on your system
#include "primefinderfunc.h" // out prime finder function


/**
 This is the conversion of C code something Python can understand.
 The type is therefore a PyObject (everything in Python that is in C is a PyObject

 @param PyObject *self: Pointer to object in memory in C. Presumably this if because
                        Python is an object-orientated language and each object needs to be able
                        to reference itself. Hence the need for it's memory address.
 @param PyObject *args: Any arguments coming from Python which have to get passed into the function
 @return PyObject: The result in C converted to a Python Object
 */
static PyObject *c_primefinderfunction(PyObject *self, PyObject *args)
{
    // Convert the Python Objects to C so we can use the C code we've written
    int desiredPrimes;
    if (!PyArg_ParseTuple(args, "i", &desiredPrimes))
    {
        return NULL;
    }

    // Execute the C code we want
    long primes[desiredPrimes];
    generatePrimes(desiredPrimes, primes);

    // Convert the C result to a Python Object
    PyObject *list = PyList_New(desiredPrimes);
    for(int i=0; i < desiredPrimes; i++) {
        PyObject* python_int = Py_BuildValue("l", primes[i]);
        PyList_SetItem(list, i, python_int);
    }

    // Return the memory address of the Python Object as the result
    return list;
}


static PyMethodDef module_methods[] = {
    {   "find_primes", // Name of the function in C
        *c_primefinderfunction, /* Name of the function that converts the Python to C, executs the C
                                and converts the result back to Python
                              */
        METH_VARARGS, /* This is a flag telling the interpreter the calling convention
                      to be used for the C function */
        "Find the prime numbers." // Python docstring
    },
    {NULL, NULL, 0, NULL} // This line tells the code that there are no other methods to export
};


static struct PyModuleDef c_primefinder = {
    PyModuleDef_HEAD_INIT, // Initialize this module
    "c_primefinder", // the name of the module in Python
    "",              // The docstring of the module in Python
    -1, /* size of per-interpreter state of the module, or -1 if the module
           keeps state in global variables. */
    module_methods   // Array of all Python methods provided by this module
};

/**
   How to initialize the module. I.e. create the following modules in Python
 */
PyMODINIT_FUNC PyInit_c_primefinder(void)
{
    return PyModule_Create(&c_primefinder);
}
