# Input Sender

## Feature

- Provide `Input` Service with `Brake`, `Throttle`, `Steering` attribute and  `GearSelect` event
- Subscribe `Gear` Services
- Bind Python in C++ with `piracer.gamepads` package
- Continuously detect status of joystick by `/dev/input/js0`
- If joystick is unplugged or not connected, send `Emergency Stop` sign to piracer
- Can be used as extra Input for `GearSelection`

## Structure

<p align="center">
  <img src="https://github.com/SEA-ME-Team4/app-hu/assets/120576021/fd54b149-8bc2-48ab-99b4-d2f391ad8143">
</p>

## Description

| FileName | Description |
| --- | --- |
| main.cpp | Check Intitial status of jostick by gamepad.getStatus() <br/> Send Emergency Stop when connection is lost while running |
| IncludePython.h | Header for include Python.h |
| gamepad.h <br/> gamepad.cpp | Get joystick input using button, analog_stick_left/right function in piracer.gamepads <br/> Continuously check joystick connection with /dev/input/js0 |
| input.h <br/> input.cpp | Connect with CommonAPI Runtime and Build Service and Proxy <br/> Provide multiple attribute and event in one interface |
| InputStatusStubImpl.hpp <br/> InputStatusStubImpl.cpp | Implementation of the generated skeleton for the stub <br/> Inherited from the stub-default implementation |

## Reference

- [Python Piracer Package](https://pypi.org/project/piracer-py/)
- [Extending and Embedding the Python Interpreter](https://docs.python.org/ko/3/extending/index.html)
