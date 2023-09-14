cmake_minimum_required(VERSION 3.5)

project(head_unit LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

include_directories(
    src
    src-gen
    ../common_api/capicxx-core-runtime/include
    ../common_api/capicxx-someip-runtime/include
    ../common_api/vsomeip/interface
)

link_directories(
    ../common_api/capicxx-core-runtime/build
    ../common_api/capicxx-someip-runtime/build
    ../common_api/vsomeip/build
)

find_package(Qt5 COMPONENTS Core Quick Gui Network Multimedia WebEngine REQUIRED)

add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/qml.qrc
    src/youtubesearch.cpp
    src/gearservice.cpp
    src/HeadUnitStubImpl.cpp
    src-gen/v1/commonapi/HeadUnitSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/HeadUnitSomeIPDeployment.cpp
)

target_compile_definitions(${CMAKE_PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${CMAKE_PROJECT_NAME}
  PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network Qt5::Multimedia Qt5::WebEngine
  CommonAPI CommonAPI-SomeIP vsomeip3)
