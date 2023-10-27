# Exception Handler

## Feature

- Provide `ExceptionHandling` Service by `ToApplication` interface
- Subscribe `Speed`, `Battery`, `Gear`, `Maneuver`, `GearSelector` Services
- Check Error with `std::chrono::steady_clock` and `Proxy->isAvailable()`

## Structure

<p align="center">
  <img src="https://github.com/SEA-ME-Team4/app-hu/assets/120576021/1db03e01-20b3-40ee-8c85-295543dfdb5e">
</p>

## Description

### Exception Handling Algorithm

- Initialization (in Constructor)
    - Set every `valueStatus` to false
    - Initialize every `valueStatusTimer` with `std::chrono::steady_clock::now()`
- handlerProcess function
    - Compare whether `valueStatusTimer` exceed `VALUE_INTERVAL_MAX`
    - Then, check status of service by `Proxy->isAvailable()`
        - If Error detected, send `errorEvent` with service name
        - If not, re-Initialize `valueStatusTimer` of that service
    - If service is Reconnected, Handler can detect it and also send `okay_event`

### Communication (C++)

| FileName | Description |
| --- | --- |
| main.cpp | Use the while statement to avoid termination <br/> Call handlerProcess with usleep |
| handler.h <br/> handler.cpp | Connect with CommonAPI Runtime and Build Service and Proxies <br/> Exception Handling with std::chrono::steady_clock |
| ToApplicationStubImpl.hpp <br/> ToApplicationStubImpl.cpp | Implementation of the generated skeleton for the stub <br/> Inherited from the stub-default implementation |

## Reference

- [std::chrono::steady_clock](https://en.cppreference.com/w/cpp/chrono/steady_clock)
