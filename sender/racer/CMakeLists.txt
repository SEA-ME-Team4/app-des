project(racer LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

include_directories(
    src
    ${PYTHON_INCLUDE_DIRS})

add_executable(racer
    src/piracer.cpp
    src/main.cpp
    src/racerclient.cpp
    src/RacerToHandlerStubImpl.cpp)
target_link_libraries(racer
    ${PYTHON_LIBRARIES}
    CommonAPI)
set_target_properties(racer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})
