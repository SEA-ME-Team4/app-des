#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Piracer
{
public:
    Piracer();
    ~Piracer();
    double get_battery_voltage();
    void set_steering_percent(float steering);
    void set_throttle_percent(float throttle);

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
};