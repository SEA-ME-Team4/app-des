#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Piracer
{
public:
    Piracer();
    ~Piracer();
    double getVoltage();
    void setRacer(int gear, bool brake, float steering, float throttle);
    void emergencyStop();

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
    void set_steering_percent(float steering);
    void set_throttle_percent(float throttle);
};