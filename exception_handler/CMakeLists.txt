cmake_minimum_required(VERSION 3.5)

project(exception_handler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/handler.cpp
    src/ToApplicationStubImpl.cpp)
target_link_libraries(${PROJECT_NAME}
    ${PYTHON_LIBRARIES}
    CommonAPI handlerskel)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${PROJECT_NAME})
