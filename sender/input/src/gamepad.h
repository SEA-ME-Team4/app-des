#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Gamepad
{
public:
    Gamepad();
    ~Gamepad();

    bool getStatus();
    void setInitStatus(bool status);

    bool read_data();
    bool getBrake();
    float getSteering();
    float getThrottle();

private:
    bool status;
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pInput, *pInputL, *pInputR, *pInputLX, *pInputRY;
    float gamepad_inputLX, gamepad_inputRY;
    bool gamepad_brake;
};