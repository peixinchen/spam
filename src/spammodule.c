#include <Python.h>


static PyObject *   SpamError;


static PyObject *
spam_nothing_done(PyObject *self, PyObject *args)
{
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *    command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command)) {
        return NULL;
    }

    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }

    return PyLong_FromLong(sts);
}


static PyMethodDef  SpamMethods[] = {
    {"system", spam_system, METH_VARARGS, "Execute a shell command."},
    {"nothing_done", spam_nothing_done, METH_VARARGS, "Nothing done."},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
initspam(void)
{
    PyObject *  m;
    
    m = Py_InitModule("spam", SpamMethods);
    if (m == NULL) {
        return;
    }

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
}

/*
int
main(int argc, char* argv[])
{
    Py_SetProgramName(argv[0]);

    Py_Initialize();

    initspam();

    return 0;
}
*/
