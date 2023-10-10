cmake_minimum_required(VERSION 3.5)

project(sender LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonLibs REQUIRED)

include_directories(
    src  
    ${PYTHON_INCLUDE_DIRS})

add_executable(speed
    src/speed/main.cpp
    src/speed/speed.cpp
    src/speed/canreceiver.cpp
    src/speed/SpeedStatusStubImpl.cpp)
target_link_libraries(speed
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(speed PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})

add_executable(battery
    src/piracer.cpp
    src/battery/main.cpp
    src/battery/battery.cpp
    src/battery/BatteryStatusStubImpl.cpp)
target_link_libraries(battery
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(battery PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})

add_executable(input
    src/input/main.cpp
    src/input/gamepad.cpp
    src/input/input.cpp
    src/input/BrakeStatusStubImpl.cpp
    src/input/ManeuverStubImpl.cpp)
target_link_libraries(input
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(input PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})

add_executable(racer
    src/piracer.cpp
    src/racer/main.cpp
    src/racer/racerclient.cpp)
target_link_libraries(racer
    ${PYTHON_LIBRARIES}
    CommonAPI vehicleskel handlerskel)
set_target_properties(racer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})
