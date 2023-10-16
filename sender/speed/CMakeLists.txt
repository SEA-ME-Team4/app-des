project(speed LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

include_directories(
    src  
    ${PYTHON_INCLUDE_DIRS})

add_executable(speed
    src/main.cpp
    src/speed.cpp
    src/canreceiver.cpp
    src/SpeedStatusStubImpl.cpp)
target_link_libraries(speed
    ${PYTHON_LIBRARIES}
    CommonAPI)
set_target_properties(speed PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})