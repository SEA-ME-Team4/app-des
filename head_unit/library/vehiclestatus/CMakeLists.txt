cmake_minimum_required(VERSION 3.5)

project(VehicleStatus LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

# Set Depend Library
set(stub_list "GearSelector")
set(proxy_list "Input" "Speed" "Gear" "Distance" "AEB")

# Include Directories
foreach(stub ${stub_list})
    include_directories(
        src-gen/core/stub/${stub}
        src-gen/core/skel/${stub}
        src-gen/core/common/${stub}
    )
endforeach()
foreach(proxy ${proxy_list})
    include_directories(
        src-gen/core/proxy/${proxy}
        src-gen/core/common/${proxy}
    )
endforeach()

# Find CommonAPI
find_package(CommonAPI REQUIRED)
# Find Qt Application
find_package(Qt5 COMPONENTS Core Quick Qml REQUIRED)

include_directories(
    src
    ${COMMONAPI_INCLUDE_DIRS})

# Build Execution
add_library(${PROJECT_NAME}
    SHARED
    src/plugin.cpp
    src/vehiclestatus.cpp
    src/GearSelectorStubImpl.cpp)
target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core Qt5::Quick Qt5::Qml 
    CommonAPI)

set(PLUGIN_PATH /lib/qml/User/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION ${PLUGIN_PATH}
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

install(FILES qmldir DESTINATION ${PLUGIN_PATH}
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

