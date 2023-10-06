cmake_minimum_required(VERSION 3.5)

project(instrument_cluster LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

# find_package(Qt5 COMPONENTS Core Quick Gui REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/qml.qrc
    src/vehicleclient.cpp
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt5::Core Qt5::Quick Qt5::Gui
  CommonAPI)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

