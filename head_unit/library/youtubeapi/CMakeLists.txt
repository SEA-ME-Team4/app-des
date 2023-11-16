cmake_minimum_required(VERSION 3.5)

project(YoutubeAPI LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

# Find Qt Application
find_package(Qt5 COMPONENTS Core Quick Qml Gui Network Multimedia WebEngine VirtualKeyboard REQUIRED)

include_directories(
    src)

# Build Execution
add_library(${PROJECT_NAME}
    SHARED
    src/plugin.cpp
    src/youtubeapi.cpp)
target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core Qt5::Quick Qt5::Qml Qt5::Gui Qt5::Network Qt5::Multimedia Qt5::WebEngine Qt5::VirtualKeyboard)

set(PLUGIN_PATH ${Qt5_DIR}/../../qt5/qml/User/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION ${PLUGIN_PATH}
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
install(FILES qmldir DESTINATION ${PLUGIN_PATH}
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
