#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Gamepad
{
public:
    Gamepad();
    ~Gamepad();
    bool read_data();
    bool brake_status();
    double gamepad_inputLX, gamepad_inputRY;

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pInput, *pInputL, *pInputR, *pInputLX, *pInputRY;
};