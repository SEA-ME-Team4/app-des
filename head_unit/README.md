# Head Unit

## Feature

- Provide  `GearSelector` Service with `GearSelect` event
- Subscribe `Speed`, `Input`, `Gear` Services
- Ambient Lighting
- Gear Selection (Safety Lock in Parking Gear with Brake Condition)
- YouTube Player (hidden when in Drive and Reverse Gear)
- GearSelector Switch (changing primary gear input between head unit and joystick)

## Structure

<p align="center">
  <img src="https://github.com/SEA-ME-Team4/app-hu/assets/120576021/68c2b601-d3a6-436c-a9a4-f8ac84e28245">
</p>

## Description

### Graphic (QML)

| FileName | Description |
| --- | --- |
| main.qml | For scale HeadUnit to fit our Display (1024 x 600, 7inch) |
| AmbientsLayout.qml | Use Shadereffect to show color picker and selcet image color what user want  |
| ContentsLayout.qml | Include “YoutubeLayout.qml” and “SearchLayout.qml” |
| GearLayout.qml | Select Gear and send to piracer with vehiclestatus.sendGear() |
| MainLayout.qml | Default Layout that include every Layouts |
| MenuLayout.qml | Display Brake Light, Reverse Light and Drive Light with Gear, Input, Speed Service |
| SearchLayout.qml | Virtualkeyboard with send a seach word to “YoutubeLayout.qml” |
| ToolbarLayout.qml | Home, Youtube, Ambientlights icon with digital clock |
| YoutubeLayout.qml | Show search results and media what user decide to play |

### Communication (C++)

| FileName | Description |
| --- | --- |
| main.cpp | Load Communication to Graphic by qmlRegisterType and show Graphic |
| vehiclestatus.h <br/> vehiclestatus.cpp | Connect with CommonAPI Runtime and Build Service and Proxies <br/> Detect changes by subscribe & Trigger events to QML |
| GearSelectorStubImpl.hpp <br/> GearSelectorStubImpl.cpp | Implementation of the generated skeleton for the stub <br/> Inherited from the stub-default implementation |
| src-gen/core | Generated Code by CommonAPI Code Generator based on interface definitions (.fidl) |
| youtube.h <br/> youtube.cpp | Request to youtube results depends on search words <br/> When outcome is ready, send data to qml |

## Reference

- [YouTube API](https://developers.google.com/youtube)
