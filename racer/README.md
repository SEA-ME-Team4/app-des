# Racer

## Feature

- Provide `Gear` Service by `GearStatus` interface
- Subscribe `GearSelector`,  `Input` Services
- Bind Python in C++ with `piracer.vehicles` package
- Implementing individual exception handling for `Input`
- `Emergency Stop` when communication failure detected
- Gear Selection Handling (no conflict) between `Head Unit` and `Input(joystick)`

## Structure

<p align="center">
  <img src="https://github.com/SEA-ME-Team4/app-hu/assets/120576021/13dd803b-14ff-47f7-afff-8b127e0e1d81">
</p>

## Description

| FileName | Description |
| --- | --- |
| main.cpp | Fetch information from racerclient and set data to piracer <br/> Trigger Emergency Stop when communication failure detected |
| IncludePython.h | Header for include Python.h |
| piracer.h <br/> piracer.cpp | Set throttle and steering using set_steering/throttle_percent function in piracer.vehicles <br/> Work differentely based on Gear status |
| racerclient.h <br/> racerclient.cpp | Connect with CommonAPI Runtime and Build Service and Proxy <br/> Gamepad and Vehicle is detached (communicate by vsomeip) <br/> Gear Selection Handling between head unit and joystick |
| GearStatusStubImpl.hpp <br/> GearStatusStubImpl.cpp | Implementation of the generated skeleton for the stub <br/> Inherited from the stub-default implementation |

## Reference

- [Python Piracer Package](https://pypi.org/project/piracer-py/)
- [Extending and Embedding the Python Interpreter](https://docs.python.org/ko/3/extending/index.html)
