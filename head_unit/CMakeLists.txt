cmake_minimum_required(VERSION 3.5)

project(head_unit LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(Qt5 COMPONENTS Core Quick Gui Network Multimedia WebEngine REQUIRED)
find_package(CommonAPI REQUIRED CONFIG NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(CommonAPI-SomeIP REQUIRED)
find_package(vsomeip3 REQUIRED)

include_directories(
    src
    src-gen
    ${COMMONAPI_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${VSOMEIP_INCLUDE_DIRS}
)

# link_directories(
#     ../common_api/capicxx-core-runtime/build
#     ../common_api/capicxx-someip-runtime/build
#     ../common_api/vsomeip/build
# )

add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/qml.qrc
    src/youtubesearch.cpp
    src/vehiclestatus.cpp
    src/GearStatusStubImpl.cpp
    src-gen/v1/commonapi/GearStatusSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/GearStatusSomeIPDeployment.cpp
    src-gen/v1/commonapi/GearToHandlerSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/GearToHandlerSomeIPDeployment.cpp
    src-gen/v1/commonapi/BrakeStatusSomeIPProxy.cpp
    src-gen/v1/commonapi/BrakeStatusSomeIPDeployment.cpp
    src-gen/v1/commonapi/ToApplicationSomeIPProxy.cpp
    src-gen/v1/commonapi/ToApplicationSomeIPDeployment.cpp
)

target_compile_definitions(${CMAKE_PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${CMAKE_PROJECT_NAME}
  PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network Qt5::Multimedia Qt5::WebEngine
  CommonAPI CommonAPI-SomeIP vsomeip3)
