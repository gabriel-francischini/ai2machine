#include "Python.h"
#include "structmember.h"
#include "machine.h"

typedef struct {
    PyObject_HEAD
    int ram;
    int registers;
    Machine *machine;
} PyMachine;

static void
PyMachine_dealloc(PyMachine* self)
{   
    if(self->machine)
        delete self->machine;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
PyMachine_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PyMachine *self;

    self = (PyMachine *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->ram = 0;
        self->registers = 0;
        self->machine = NULL;
    }

    return (PyObject *)self;
}

static int
PyMachine_init(PyMachine *self, PyObject *args)
{
    if (! PyArg_ParseTuple(args, "ii",
                           &self->ram, &self->registers))
        return -1;

    self->machine = new Machine(self->ram, self->registers);
    return 0;
}

static PyMemberDef PyMachine_members[] = {
    {"ram", T_INT, offsetof(PyMachine, ram), 0,
     "pymachine ram"},
    {"registers", T_INT, offsetof(PyMachine, registers), 0,
     "pymachine registers"},
    {NULL}  /* Sentinel */
};

static PyObject *
PyMachine_getRam(PyMachine *self, void *closure)
{
    return Py_BuildValue("i", self->ram);
}

static PyObject *
PyMachine_getRegisters(PyMachine *self, void *closure)
{
    return Py_BuildValue("i", self->registers);
}

static PyGetSetDef PyMachine_getseters[] = {
    {"ram",
     (getter)PyMachine_getRam, NULL,
     "get ram amount",
     NULL},
    {"registers",
     (getter)PyMachine_getRegisters, NULL,
     "get registers amount",
     NULL},
    {NULL}  /* Sentinel */
};

static PyObject *
PyMachine_name(PyMachine* self)
{
    return PyUnicode_FromFormat("%d %d", self->ram, self->registers);
}

static PyMethodDef PyMachine_methods[] = {
    {"name", (PyCFunction)PyMachine_name, METH_NOARGS,
     "Return the name, combining the ram and registers amount"
    },
    {NULL}  /* Sentinel */
};

static PyTypeObject PyMachineType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pymachine.PyMachine",             /* tp_name */
    sizeof(PyMachine),             /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)PyMachine_dealloc, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
        Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "PyMachine objects",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    PyMachine_methods,             /* tp_methods */
    PyMachine_members,             /* tp_members */
    PyMachine_getseters,           /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PyMachine_init,      /* tp_init */
    0,                         /* tp_alloc */
    PyMachine_new,                 /* tp_new */
};

static PyModuleDef pymachinemodule = {
    PyModuleDef_HEAD_INIT,
    "pymachine",
    "Example module that creates an extension type.",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_pymachine(void)
{
    PyObject* m;

    if (PyType_Ready(&PyMachineType) < 0)
        return NULL;

    m = PyModule_Create(&pymachinemodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&PyMachineType);
    PyModule_AddObject(m, "PyMachine", (PyObject *)&PyMachineType);
    return m;
}