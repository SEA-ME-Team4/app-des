project(exception_handler LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/handler.cpp
    src/ToApplicationStubImpl.cpp)
target_link_libraries(${PROJECT_NAME}
    ${PYTHON_LIBRARIES}
    CommonAPI handlerskel)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})
