#include "gamepad.h"
#include <iostream>

Gamepad::Gamepad() {
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.gamepads");
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Gamepad::~Gamepad() {
    Py_XDECREF(pInputLX);
    Py_XDECREF(pInputRY);
    Py_XDECREF(pInputL);
    Py_XDECREF(pInputR);
    Py_XDECREF(pInput);
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}

bool Gamepad::read_data() {
    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);

    pInputL = PyObject_GetAttrString(pInput, "analog_stick_left");
    pInputLX = PyObject_GetAttrString(pInputL, "x");
    gamepad_inputLX = PyFloat_AsDouble(pInputLX);

    pInputR = PyObject_GetAttrString(pInput, "analog_stick_right");
    pInputRY = PyObject_GetAttrString(pInputR, "y");
    gamepad_inputRY = -PyFloat_AsDouble(pInputRY);
    
    return true;
}

bool Gamepad::brake_status() {
    if (gamepad_inputRY<0) {
        return true;
    }
    else {
        return false;
    }
}