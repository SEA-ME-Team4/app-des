#include "piracer.h"
#include <iostream>

Piracer::Piracer() {
    Py_Initialize();
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

double Piracer::get_battery_voltage() {
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