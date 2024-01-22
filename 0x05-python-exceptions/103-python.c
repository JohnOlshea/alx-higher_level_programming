#include <Python.h>

void print_python_list(PyObject *p) {
printf("[*] Python list info\n");
printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

for (Py_ssize_t i = 0; i < PyList_Size(p); ++i) {
printf("Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
if (PyBytes_Check(PyList_GetItem(p, i))) {
printf("[.] bytes object info\n");
printf("  size: %ld\n", PyBytes_GET_SIZE(PyList_GetItem(p, i)));
printf("  trying string: %s\n", PyBytes_AsString(PyList_GetItem(p, i)));
printf("  first %d bytes: ", PyBytes_GET_SIZE(PyList_GetItem(p, i)) < 10 ? PyBytes_GET_SIZE(PyList_GetItem(p, i)) : 10);
for (int j = 0; j < (PyBytes_GET_SIZE(PyList_GetItem(p, i)) < 10 ? PyBytes_GET_SIZE(PyList_GetItem(p, i)) : 10); ++j) {
printf("%02x ", (unsigned char)PyBytes_AsString(PyList_GetItem(p, i))[j]);
}
printf("\n");
}
}
}

void print_python_bytes(PyObject *p) {
if (!PyBytes_Check(p)) {
printf("[.] bytes object info\n");
printf("  [ERROR] Invalid Bytes Object\n");
return;
}

printf("[.] bytes object info\n");
printf("  size: %ld\n", PyBytes_GET_SIZE(p));
printf("  trying string: %s\n", PyBytes_AsString(p));
printf("  first %d bytes: ", PyBytes_GET_SIZE(p) < 10 ? PyBytes_GET_SIZE(p) : 10);
for (int i = 0; i < (PyBytes_GET_SIZE(p) < 10 ? PyBytes_GET_SIZE(p) : 10); ++i) {
printf("%02x ", (unsigned char)PyBytes_AsString(p)[i]);
}
printf("\n");
}

void print_python_float(PyObject *p) {
if (!PyFloat_Check(p)) {
printf("[.] float object info\n");
printf("  [ERROR] Invalid Float Object\n");
return;
}

printf("[.] float object info\n");
printf("  value: %f\n", PyFloat_AsDouble(p));
}

