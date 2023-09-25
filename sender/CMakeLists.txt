cmake_minimum_required(VERSION 3.5)

project(sender LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_executable(speed
    src/speed/canreceiver.cpp
    src/speed/speed.cpp
    src/speed/SpeedStatusStubImpl.cpp)
target_link_libraries(speed
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(speed PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${PROJECT_NAME})

add_executable(battery
    src/piracer.cpp
    src/battery/battery.cpp
    src/battery/BatteryStatusStubImpl.cpp)
target_link_libraries(battery
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(battery PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${PROJECT_NAME})

add_executable(input
    src/input/gamepad.cpp
    src/input/input.cpp
    src/input/BrakeStatusStubImpl.cpp
    src/input/ManeuverStubImpl.cpp)
target_link_libraries(input
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(input PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${PROJECT_NAME})

add_executable(racer
    src/piracer.cpp
    src/racer/racer.cpp
    src/racer/racerclient.cpp)
target_link_libraries(racer
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(racer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${PROJECT_NAME})
