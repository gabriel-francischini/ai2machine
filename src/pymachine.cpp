#include "Python.h"
#include "structmember.h"
#include "machine.h"

class pymachine:public Machine{
    using Machine::Machine;

    public:
        PyObject *interrupt_callback;

        virtual int interrupt(int interrupt_code, int parameter){
            if(this->interrupt_callback != NULL && PyCallable_Check(this->interrupt_callback)){
                PyObject *arglist;
                arglist = Py_BuildValue("(ii)", interrupt_code, parameter);
                PyObject *new_object = PyObject_CallObject(this->interrupt_callback, arglist);
                if(new_object == NULL)
                    PyErr_Clear();
                else
                    Py_DECREF(new_object);
                Py_DECREF(arglist);
            }
            return INTERRUPT_SIGNAL;
        }
};

typedef struct {
    PyObject_HEAD
    int ram;
    int registers;
    pymachine *machine;
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
                           &self->registers, &self->ram))
        return -1;

    self->machine = new pymachine(self->ram, self->registers);
    self->machine->interrupt_callback = NULL;
    return 0;
}

static PyMemberDef PyMachine_members[] = {
    /*{"ram", T_INT, offsetof(PyMachine, ram), 0,
     "pymachine ram"},
    {"registers", T_INT, offsetof(PyMachine, registers), 0,
     "pymachine registers"},*/
    {NULL}  /* Sentinel */
};

static PyObject *
PyMachine_getRamSize(PyMachine *self, void *closure)
{
    if(self->machine)
        return Py_BuildValue("i", self->machine->memory_limit()+1);
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return NULL;       
    }
}

static PyObject *
PyMachine_getRam(PyMachine *self, void *closure)
{
    if(self->machine){
        PyObject *unit_int = PyLong_FromLong(1);        
        Py_ssize_t unit_int_size = PyLong_AsSsize_t(unit_int);
        int ram_size = (self->machine->memory_limit()+1);


        if(unit_int == NULL)
            return NULL;

        PyObject *result_tuple = PyTuple_New(unit_int_size * ram_size);

        if(result_tuple == NULL){
            Py_DECREF(unit_int);
            return NULL;
        }
        
        for(int i=0;i < ram_size; i++){
            if( PyTuple_SetItem(result_tuple, i, PyLong_FromLong(self->machine->getMemory()[i])) != 0){
                PyErr_SetString(PyExc_MemoryError, "Couldn't build up ram representation properly");
                Py_DECREF(result_tuple);
                Py_DECREF(unit_int);
                return NULL;      
            }
        }

        Py_DECREF(unit_int);
        return result_tuple;
    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return NULL;       
    }
}

static int PyMachine_setRam(PyMachine *self, PyObject *tuple, void *closure)
{
    if(self->machine){
        if(!PyTuple_Check(tuple)){
            PyErr_SetString(PyExc_TypeError, "Argument must be a tuple");
            return -1;    
        }

        int tuple_size = PyTuple_Size(tuple);
        int limit;

        if(tuple_size > (self->machine->memory_limit()+1))
            limit = self->machine->memory_limit()+1;
        else
            limit = tuple_size;

        for(int i=0; i<limit; i++){
            PyObject *current_value = PyTuple_GetItem(tuple, i);
            if(current_value == NULL){
                PyErr_SetString(PyExc_IndexError, "Couldn't access tuple properly");
                return -1;
            }
            
            if(!PyLong_Check(current_value)){
                PyErr_SetString(PyExc_TypeError, "All values must be integers. Machine will be left in a broken/mixed-up memory state");
                return -1;
            }

            self->machine->memory[i] = PyLong_AsLong(current_value);

        }

        return 0;

    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return -1;       
    }
}

static PyObject *
PyMachine_getRegistersAmount(PyMachine *self, void *closure)
{
    if(self->machine)
        return Py_BuildValue("i", self->machine->registers_limit()+1);
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return NULL;       
    }
}

static PyObject *
PyMachine_getRegisters(PyMachine *self, void *closure)
{
    if(self->machine){
        PyObject *unit_int = PyLong_FromLong(1);        
        Py_ssize_t unit_int_size = PyLong_AsSsize_t(unit_int);
        int registers_amount = (self->machine->registers_limit()+1);


        if(unit_int == NULL)
            return NULL;

        // New refcount
        PyObject *result_tuple = PyTuple_New(unit_int_size * registers_amount);

        if(result_tuple == NULL){
            Py_DECREF(unit_int);
            return NULL;
        }
        
        for(int i=0;i < registers_amount; i++){
            if( PyTuple_SetItem(result_tuple, i, PyLong_FromLong(self->machine->getRegisters()[i])) != 0){
                PyErr_SetString(PyExc_MemoryError, "Couldn't build up registers representation properly");
                Py_DECREF(result_tuple);
                Py_DECREF(unit_int);
                return NULL;      
            }
        }

        Py_DECREF(unit_int);

        // Returns new refcount
        return result_tuple;
    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return NULL;       
    }
}

static int PyMachine_setRegisters(PyMachine *self, PyObject *tuple, void *closure)
{
    if(self->machine){
        if(!PyTuple_Check(tuple)){
            PyErr_SetString(PyExc_TypeError, "Argument must be a tuple");
            return -1;    
        }

        int tuple_size = PyTuple_Size(tuple);
        int limit;

        if(tuple_size > (self->machine->registers_limit()+1))
            limit = self->machine->registers_limit()+1;
        else
            limit = tuple_size;

        for(int i=0; i<limit; i++){
            PyObject *current_value = PyTuple_GetItem(tuple, i);
            if(current_value == NULL){
                PyErr_SetString(PyExc_IndexError, "Couldn't access tuple properly");
                return -1;
            }
            
            if(!PyLong_Check(current_value)){
                PyErr_SetString(PyExc_TypeError, "All values must be integers. Machine will be left in a broken/mixed-up memory state");
                return -1;
            }

            self->machine->registers[i] = PyLong_AsLong(current_value);

        }

        return 0;

    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return -1;       
    }
}

static PyObject *
PyMachine_getCallback(PyMachine *self, void *closure)
{
    if(self->machine){
        if(self->machine->interrupt_callback != NULL){
            Py_INCREF(self->machine->interrupt_callback);
            return self->machine->interrupt_callback;
        }
        else{
            Py_INCREF(Py_None);
            return Py_None; 
        }
    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return NULL;       
    }
}

static int PyMachine_setCallback(PyMachine *self, PyObject *arg, void *closure)
{
    if(self->machine != NULL){
        PyObject *function = NULL;

        if (PyArg_Parse(arg, "O:set_callback", &function)) {
            if (!PyCallable_Check(function)) {
                PyErr_SetString(PyExc_TypeError, "Callback function must be callable");
                return -1;
            }
            Py_INCREF(function);
            Py_XDECREF(self->machine->interrupt_callback);
            self->machine->interrupt_callback = function;
            return 0;
        }
        else{
            PyErr_SetString(PyExc_TypeError, "Argument must be a function");
            return -1;    
        } 
    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return -1;       
    }
}

static PyGetSetDef PyMachine_getseters[] = {
    {"ram_size",
     (getter)PyMachine_getRamSize, NULL,
     "Size of the machine's ram (integer)",
     NULL},
    {"ram",
     (getter)PyMachine_getRam, (setter) PyMachine_setRam,
     "Ram of the machine where instructions/code and data are fetched and stored (tuple)",
     NULL},
    {"registers",
     (getter)PyMachine_getRegisters, (setter) PyMachine_setRegisters,
     "Registers of the machine where current in-use data are stored (tuple)",
     NULL},
    {"registers_amount",
     (getter)PyMachine_getRegistersAmount, NULL,
     "Quatity of registers available on the machine (integer)",
     NULL},
         {"syscall",
     (getter)PyMachine_getCallback, (setter)PyMachine_setCallback,
     "Callback",
     NULL},
    {NULL}  /* Sentinel */
};

static PyObject *
PyMachine_getTicket(PyMachine* self, PyObject *args)
{
    if(self->machine != NULL){
        int tickets = 0;
        if (! PyArg_ParseTuple(args, "i",
                           &tickets))
            return NULL;

        return PyLong_FromLong(self->machine->getTicket(tickets));
    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return NULL;       
    }
}

static PyObject *
PyMachine_clear(PyMachine* self)
{
    if(self->machine != NULL){
        self->machine->clearMemory();
        Py_INCREF(Py_None);
        return Py_None;
    }
    else {
        PyErr_SetString(PyExc_AttributeError, "The machine needs to be initialized");
        return NULL;       
    }
}

static PyMethodDef PyMachine_methods[] = {
    {"getTicket", (PyCFunction)PyMachine_getTicket,  METH_VARARGS,
     "Execute a number of machine instructions/steps"
    },
    {"clear", (PyCFunction)PyMachine_clear,  METH_NOARGS,
     "Set all registers and memories cells to zero"
    },
    {NULL}  /* Sentinel */
};

static PyTypeObject PyMachineType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pymachine.Machine",             /* tp_name */
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
    "A Machine object is a microprocessor-like simulation structure.\n\tIt has a ram memory and a number of registers.\n\tThese can be modified any moment by the machine itself or by accessing Machine.ram or Machine.registers values.\n\tThis implementation also use `tickets` (one ticket per instruction) to do intructions.\n\n\tThis class is a wrapper for a underlaying C++ machinery.",           /* tp_doc */
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
    PyModule_AddObject(m, "Machine", (PyObject *)&PyMachineType);
    return m;
}