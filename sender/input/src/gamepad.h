#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Gamepad
{
public:
    Gamepad();
    ~Gamepad();

    void setInitStatus(bool status);
    void setGear(int gear);
    bool getStatus();

    bool read_data();
    bool getBrake();
    float getSteering();
    float getThrottle();
    int getGear();


private:
    bool status;
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pReadData, *pInput, *pInputXY;
    float gamepad_inputLX, gamepad_inputRY;
    bool gamepad_brake;
    bool gamepad_button_y, gamepad_button_x, gamepad_button_b, gamepad_button_a, gamepad_button_r3; 
    int gamepad_gear;
    bool changable;
};