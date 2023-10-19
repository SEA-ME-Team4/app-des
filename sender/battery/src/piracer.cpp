#include "piracer.h"
#include <iostream>

Piracer::Piracer() {
    Py_InitializeEx(0);
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Piracer::~Piracer() {
    Py_XDECREF(pVoltage);
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}

double Piracer::getVoltage() {
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltage = PyFloat_AsDouble(pVoltage);
    return voltage;
}

void Piracer::set_steering_percent(float steering) {
    PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering);
}

void Piracer::set_throttle_percent(float throttle) {
    PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle);
}

void Piracer::setRacer(int gear, bool brake, float steering, float throttle) {
    throttle = 0.5*throttle
    if (gear==0) {
        steering = 0;
        throttle = 0;
    }
    else if (gear==1) {
        throttle = -throttle;
        if (throttle>0) {
            throttle = 0;
        }
    }
    else if (gear==2) {
        throttle = 0;
    }
    else if (gear==3) {
        if (throttle<0) {
            throttle = 0;
        }
    }
    else if (gear==4) {
        if (throttle<0) {
            throttle = 0;
        }
        throttle = 1.5*throttle;
    }

    (1.0<steering) ? steering = 1.0 : steering = steering;
    (steering<-1.0) ? steering = -1.0 : steering = steering;
    (1.0<throttle) ? throttle = 1.0 : throttle = throttle;
    (throttle<-1.0) ? throttle = -1.0 : throttle = throttle;

    set_steering_percent(steering);
    set_throttle_percent(throttle);
}

void Piracer::emergencyStop() {
    set_steering_percent(0.0);
    set_throttle_percent(0.0);
}