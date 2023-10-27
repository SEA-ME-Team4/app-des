# Head Unit Application

The head unit Qt application compatible with Yocto Project

## Features

### In Communication (CommonAPI)

- Use CommonAPI with vsomeip binding
- Library(.so) and Execution(.exe) can be Built seperatly
- Library is not linked in Compile level, linked in Runtime level by configuration file (.ini)
- Binding can be easily changed (SOME/IP ↔ D-Bus)

### In Head Unit

- Gear Selection (Primary)
- Ambient Lighting
- Youtube API
- Speed & Brake responsive design

### In Instrument Cluster

- Vehicle Information (Speed, Battery, Brake, Gear)
- Status Indicator (Exception Handler)

### In Piracer

- Support Python Piracer package Functions in C++ by Python Interpreter embedding
- Control based on Gear condition and Joystick status
- Use GearSelect input from Head Unit(Primary) & Joystick(Extra)
- GearStatus is Serviced in Piracer

## Architecture

<p align="center">
  <img src="https://github.com/SEA-ME-Team4/app-hu/assets/120576021/703187ac-73b8-4028-b188-6a80643bfd1f">
</p>

## Reference

- [CommonAPI C++](https://covesa.github.io/capicxx-core-tools/)
- [CommonAPI C++ Core Runtime](https://github.com/COVESA/capicxx-core-runtime)
- [CommonAPI C++ SOME/IP Runtime](https://github.com/COVESA/capicxx-someip-runtime)
- [vsomeip](https://github.com/COVESA/vsomeip)
- [Qt5](https://doc.qt.io/qt-5.15/)
