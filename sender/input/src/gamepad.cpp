#include "gamepad.h"
#include <iostream>

Gamepad::Gamepad() {
    Py_InitializeEx(0);
    
    pModule = PyImport_ImportModule("piracer.gamepads");
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");
    pInstance = PyObject_CallObject(pClass, NULL);

    status = false;
    changable = false;
    racer_gear = 0;
    gamepad_gear = 0;
}

Gamepad::~Gamepad() {
    if (status) {
        Py_XDECREF(pInputXY);
        Py_XDECREF(pInput);
        Py_XDECREF(pReadData);
    }
    
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}

bool Gamepad::read_data() {
    pReadData = PyObject_CallMethod(pInstance, "read_data", NULL);
    if (pReadData==NULL && getStatus()==false) {return false;}

    pInput = PyObject_GetAttrString(pReadData, "analog_stick_left");
    pInputXY = PyObject_GetAttrString(pInput, "x");
    gamepad_inputLX = -(float)PyFloat_AsDouble(pInputXY);

    pInput = PyObject_GetAttrString(pReadData, "analog_stick_right");
    pInputXY = PyObject_GetAttrString(pInput, "y");
    gamepad_inputRY = (float)PyFloat_AsDouble(pInputXY);

    (gamepad_inputRY<0) ? gamepad_brake = true : gamepad_brake =  false;

    pInput = PyObject_GetAttrString(pReadData, "button_y");
    gamepad_button_y = PyObject_IsTrue(pInput);
    pInput = PyObject_GetAttrString(pReadData, "button_x");
    gamepad_button_x = PyObject_IsTrue(pInput);
    pInput = PyObject_GetAttrString(pReadData, "button_b");
    gamepad_button_b = PyObject_IsTrue(pInput);
    pInput = PyObject_GetAttrString(pReadData, "button_a");
    gamepad_button_a = PyObject_IsTrue(pInput);
    pInput = PyObject_GetAttrString(pReadData, "button_r3");
    gamepad_button_r3 = PyObject_IsTrue(pInput);
    
    gearChanged = true;
    changable = (gamepad_gear!=0)||(gamepad_brake)||(racer_gear);

    if (gamepad_button_y && gamepad_brake) {gamepad_gear = 0;}
    else if (changable) {
        if (gamepad_button_x) {gamepad_gear = 1;}
        else if (gamepad_button_b) {gamepad_gear = 2;}
        else if (gamepad_button_a) {gamepad_gear = 3;}
        else if (gamepad_gear==3 && gamepad_button_r3) {gamepad_gear = 4;}
        else if (gamepad_gear==4 && !gamepad_button_r3) {gamepad_gear = 3;}
        else {gearChanged = false;}
    }
    else {gearChanged = false;}

    return true;
}

bool Gamepad::getStatus() {
    const char* inputPath = "/dev/input/js0";
    if (access(inputPath, F_OK)==0) {return true;}
    else {return false;}
}

void Gamepad::setInitStatus(bool status) {
    this->status = status;
}

void Gamepad::setRacerGear(int gear) {
    this->racer_gear = gear;
}

void Gamepad::setGear(int gear) {
    this->gamepad_gear = gear;
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

int Gamepad::getGear() {
    return gamepad_gear;
}

bool Gamepad::onGearChanged() {
    if (gearChanged) {return true;}
    else {return false;}
}
