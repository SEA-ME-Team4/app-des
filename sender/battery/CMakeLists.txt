project(sender LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

include_directories(
    src
    ${PYTHON_INCLUDE_DIRS})

add_executable(battery
    src/piracer.cpp
    src/main.cpp
    src/battery.cpp
    src/BatteryStatusStubImpl.cpp)
target_link_libraries(battery
    ${PYTHON_LIBRARIES}
    CommonAPI)
set_target_properties(battery PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})