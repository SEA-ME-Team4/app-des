# Battery Sender

## Feature

- Provide `Battery` Service by `BatteryStatus` interface
- Not Subscribe any Service
- Bind Python in C++ with `piracer.vehicles` package
- Adapt Filter with `std::deque` and `max_element` to prevent shrink when driving motor
- Convert Voltage to Battery Percentage

## Structure

<p align="center">
  <img src="https://github.com/SEA-ME-Team4/app-hu/assets/120576021/341940bb-e17b-4ea5-be3d-21f9491c69fb">
</p>

## Description

| FileName | Description |
| --- | --- |
| main.cpp | Convert battery voltage to percentage <br/> Maximum Filter is adapted in battery data with std::deque and max_element |
| IncludePython.h | Header for include Python.h |
| piracer.h <br/> piracer.cpp | Get battery voltage using get_battery_voltage function in piracer.vehicles <br/> getVoltage() returns raw battery voltage |
| battery.h <br/> battery.cpp | Connect with CommonAPI Runtime and Build Service <br/> Not subscribe any service |
| BatteryStatusStubImpl.hpp <br/> BatteryStatusStubImpl.cpp | Implementation of the generated skeleton for the stub <br/> Inherited from the stub-default implementation |

## Reference

- [std::deque](https://en.cppreference.com/w/cpp/container/deque)
- [std::max_element](https://en.cppreference.com/w/cpp/algorithm/max_element)
- [Python Piracer Package](https://pypi.org/project/piracer-py/)
- [Extending and Embedding the Python Interpreter](https://docs.python.org/ko/3/extending/index.html)
