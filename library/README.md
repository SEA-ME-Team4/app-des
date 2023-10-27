# Library

## Feature

- Glue-Code Binding Libarary for CommonAPI Binding (SOME/IP)
- Depends on `CommonAPI`, `CommonAPI-SomeIP`, `vsomeip3`
- Auto Generated code by CommonAPI `Code Generator`
- Create different libraries for `common`, `proxy` and `stub` for each Service
- Compile and Build seperately with execution files
- Libraries are loaded only if they are needed and at the time when they are needed
    - Standard CommonAPI way to connect to D-Bus or SOME/IP
    - Connect Interface to Library by using `commonapi.ini` file
    - Library contains Service, Interface and its IDs
    - Library NOT contains tcp/udp port setting in `.fdepl` file

## Description

| FileName | Description |
| --- | --- |
| src-gen/core | Generated code by core_generator with .fidl file |
| src-gen/someip | Generated code by someip_generator with .fdepl file |

## Reference

1. [Loading Bindings And Libraries](https://github.com/COVESA/capicxx-core-tools/wiki/Loading-Bindings-And-Libraries)
