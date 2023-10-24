#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Piracer
{
public:
    Piracer();
    ~Piracer();
    double getVoltage();

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
};