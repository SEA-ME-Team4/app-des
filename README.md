# Head Unit Application

The head unit Qt application compatible with Yocto Project

## Architecture
![app-hu drawio](https://github.com/SEA-ME-Team4/app-hu/assets/120576021/11a14785-afc8-496c-a43a-125730625d5b)

## Features

### In Communication (CommonAPI)

- Use CommonAPI with vsomeip binding
- Library(.so) and Execution(.exe) can be Built seperatly
- Library is not linked in compile level, so Binding can be easily changed

### In Head Unit

- Gear Selection
- Ambient Lighting
- Youtube API

### In Instrument Cluster

- Vehicle Information (Speed, Battery, Brake, Gear)
- Exception Handling (Status Indicator)

### In Piracer

- Maneuver with Joystick
- Control with Gear and Joystick status

## Reference
1. CommonAPI C++ Core Runtime
https://github.com/COVESA/capicxx-core-runtime
2. CommonAPI C++ SOME/IP Runtime
https://github.com/COVESA/capicxx-someip-runtime
3. vsomeip
https://github.com/COVESA/vsomeip
4. Loading Bindings And Libraries
https://github.com/COVESA/capicxx-core-tools/wiki/Loading-Bindings-And-Libraries