#include "gamepad.h"
#include <iostream>

Gamepad::Gamepad() {
    Py_InitializeEx(0);
    
    pModule = PyImport_ImportModule("piracer.gamepads");
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");
    pInstance = PyObject_CallObject(pClass, NULL);

    status = false;
}

Gamepad::~Gamepad() {
    if (status) {
        Py_XDECREF(pInputLX);
        Py_XDECREF(pInputRY);
        Py_XDECREF(pInputL);
        Py_XDECREF(pInputR);
        Py_XDECREF(pInput);
    }
    
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}

bool Gamepad::read_data() {
    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);
    if (pInput==NULL && getStatus()==false) {return false;}

    pInputL = PyObject_GetAttrString(pInput, "analog_stick_left");
    pInputLX = PyObject_GetAttrString(pInputL, "x");
    gamepad_inputLX = -(float)PyFloat_AsDouble(pInputLX);

    pInputR = PyObject_GetAttrString(pInput, "analog_stick_right");
    pInputRY = PyObject_GetAttrString(pInputR, "y");
    gamepad_inputRY = (float)PyFloat_AsDouble(pInputRY);

    (gamepad_inputRY<0) ? gamepad_brake = true : gamepad_brake =  false;
    return true;
}

bool Gamepad::getStatus() {
    const char* inputPath = "/dev/input/js0";
    if (access(inputPath, F_OK)==0) {
        return true;
    }
    else {
        return false;
    }
}

void Gamepad::setInitStatus(bool status) {
    this->status = status;
}

bool Gamepad::getBrake() {
    return gamepad_brake;
}

float Gamepad::getSteering() {
    return gamepad_inputLX;
}

float Gamepad::getThrottle() {
    return gamepad_inputRY;
}