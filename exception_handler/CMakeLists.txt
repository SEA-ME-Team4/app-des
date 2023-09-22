cmake_minimum_required(VERSION 3.5)

project(sender LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(CommonAPI REQUIRED CONFIG NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(CommonAPI-SomeIP REQUIRED)
find_package(vsomeip3 REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
    src
    src-gen
    ${PYTHON_INCLUDE_DIRS}
    ${COMMONAPI_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${VSOMEIP_INCLUDE_DIRS}
)

# link_directories(
#     ../common_api/capicxx-core-runtime/build
#     ../common_api/capicxx-someip-runtime/build
#     ../common_api/vsomeip/build
# )

add_executable(handler
    src/main.cpp
    src/handler.cpp
    src-gen/v1/commonapi/ToHandlerSomeIPProxy.cpp
    src-gen/v1/commonapi/ToHandlerSomeIPDeployment.cpp
    src/ToApplicationStubImpl.cpp
    src-gen/v1/commonapi/ToApplicationSomeIPStubAdapter.cpp
    src-gen/v1/commonapi/ToApplicationSomeIPDeployment.cpp
)
target_link_libraries(handler
    ${PYTHON_LIBRARIES}
    CommonAPI CommonAPI-SomeIP vsomeip3)