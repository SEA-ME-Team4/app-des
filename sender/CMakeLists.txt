cmake_minimum_required(VERSION 3.5)

project(sender LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(CommonAPI REQUIRED CONFIG NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(CommonAPI-SomeIP REQUIRED)
find_package(vsomeip3 REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
    src
    src-gen
    ${PYTHON_INCLUDE_DIRS}
    ${COMMONAPI_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${VSOMEIP_INCLUDE_DIRS}
)

# link_directories(
#     ../common_api/capicxx-core-runtime/build
#     ../common_api/capicxx-someip-runtime/build
#     ../common_api/vsomeip/build
# )

add_executable(speed
    src/speed/canreceiver.cpp
    src/speed/speed.cpp
    src/speed/SpeedStatusStubImpl.cpp
    src-gen/v1/commonapi/SpeedStatusSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/SpeedStatusSomeIPDeployment.cpp
)
target_link_libraries(speed
    ${PYTHON_LIBRARIES}
    CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(battery
    src/piracer.cpp
    src/battery/battery.cpp
    src/battery/BatteryStatusStubImpl.cpp
    src-gen/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/BatteryStatusSomeIPDeployment.cpp
)
target_link_libraries(battery
    ${PYTHON_LIBRARIES}
    CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(handler
    src/handler/gamepad.cpp
    src/handler/handler.cpp
    src/handler/BrakeStatusStubImpl.cpp
    src/handler/ManeuverStubImpl.cpp
    src-gen/v1/commonapi/BrakeStatusSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/BrakeStatusSomeIPDeployment.cpp
    src-gen/v1/commonapi/ManeuverSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/ManeuverSomeIPDeployment.cpp
)
target_link_libraries(handler
    ${PYTHON_LIBRARIES}
    CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(racer
    src/piracer.cpp
    src/racer/racer.cpp
    src/racer/racerclient.cpp
    src-gen/v1/commonapi/GearStatusSomeIPProxy.cpp
    src-gen/v1/commonapi/GearStatusSomeIPDeployment.cpp
    src-gen/v1/commonapi/BrakeStatusSomeIPProxy.cpp
    src-gen/v1/commonapi/BrakeStatusSomeIPDeployment.cpp
    src-gen/v1/commonapi/ManeuverSomeIPProxy.cpp
    src-gen/v1/commonapi/ManeuverSomeIPDeployment.cpp
)
target_link_libraries(racer
    ${PYTHON_LIBRARIES}
    CommonAPI CommonAPI-SomeIP vsomeip3)