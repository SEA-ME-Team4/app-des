# Speed Sender

## Feature

- Provide `Speed` Service by `SpeedStatus` interface
- Not Subscribe any Service
- Socket CAN (Filtering id with CAN_RAW_FILTER)
- Forward and backward cannot be distinguished
- Noise cancellation with Low Pass Filter

## Structure

<p align="center">
  <img src="https://github.com/SEA-ME-Team4/app-hu/assets/120576021/9021c146-3a9c-4d4a-9198-73f48ff442e6">
</p>

## Description

| FileName | Description |
| --- | --- |
| main.cpp | Connect Socket CAN with CommonAPI <br/> Low Pass Filter is adapted in speed data |
| canreceiver.h <br/> canreceiver.cpp | Receive speed data from arduino with CAN ID Filter <br/> Convert CAN message to Integer for CommonAPI   |
| speed.h <br/> speed.cpp | Connect with CommonAPI Runtime and Build Service <br/> Not subscribe any service |
| SpeedStatusStubImpl.hpp <br/> SpeedStatusStubImpl.cpp | Implementation of the generated skeleton for the stub <br/> Inherited from the stub-default implementation |

## Reference

1. [Socket CAN](https://www.kernel.org/doc/html/latest/networking/can.html)
2. [Linux can-utils](https://github.com/linux-can/can-utils/blob/master/include/linux/can.h)
3. [Low Pass Filter](https://en.wikipedia.org/wiki/Low-pass_filter)
