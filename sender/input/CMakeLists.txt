project(sender LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

include_directories(
    src  
    ${PYTHON_INCLUDE_DIRS})

add_executable(input
    src/main.cpp
    src/gamepad.cpp
    src/input.cpp
    src/BrakeStatusStubImpl.cpp
    src/ManeuverStubImpl.cpp)
target_link_libraries(input
    ${PYTHON_LIBRARIES}
    CommonAPI)
set_target_properties(input PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})