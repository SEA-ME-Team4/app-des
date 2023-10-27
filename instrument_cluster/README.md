# Instrument Cluster

## Feature

- Not Provide Any Service
- Subscribe `Speed`, `Battery`, `Gear`, `Brake`, `ExceptionHandling` Services
- User can Detect Error by Status Indicator
- Independent availability check of connection with `ExceptionHandler`

## Structure

![InstrumentCluster drawio](https://github.com/SEA-ME-Team4/app-hu/assets/120576021/d5972534-e14a-49e3-bc36-9d27ad03406e)

## Description

### Graphic (QML)

| FileName | Description |
| --- | --- |
| main.qml | For rotate InstrumentCluster to fit our Display (1280 x 400, 7.9inch) |
| InstrumentCluster.qml | Contain all properties, Parent of these below |
| LeftCluster.qml | Display Speed with onSpeedChanged signal |
| RightCluster.qml | Display Battery with onGearChanged signal |
| GearSelection.qml | Display Gear with onGearChanged signal |
| CenterCar.qml | Display Brake Light, Reverse Light and Drive Light by Gear, Brake, Speed signal |
| StatusIndicator.qml | Display Error by Exception Handling Service with onErrorStatus signal |

### Communication (C++)

| FileName | Description |
| --- | --- |
| main.cpp | Load Communication to Graphic by qmlRegisterType and show Graphic |
| vehicleclient.h <br/> vehicleclient.cpp | Connect with CommonAPI Runtime and Build Proxies <br/> Detect changes by subscribe & Trigger events to QML <br/> Independent availability check of ExceptionHandler with QTimer |
| src-gen/core | Generated Code by CommonAPI Code Generator based on interface definitions (.fidl) |

## Reference
- [SEA:ME Team4, DES_Instrument-Cluster](https://github.com/SEA-ME-Team4/DES_Instrument-Cluster)
- [Qt Quick Ultralite Automotive Cluster Demo (Image Source)](https://doc.qt.io/QtForMCUs-2.5/quickultralite-automotive-example.html)
- [Indicator Image (Icon Source)](https://www.flaticon.com/kr/free-icons/)
