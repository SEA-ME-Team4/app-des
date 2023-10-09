cmake_minimum_required(VERSION 3.5)

project(TEAM4_DES03 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(MY_PROJECT_NAME library)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

set(OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/output)

find_package(CommonAPI REQUIRED CONFIG NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(CommonAPI-SomeIP REQUIRED)
find_package(vsomeip3 REQUIRED)
find_package(Qt5 COMPONENTS Core Quick Gui Network Multimedia WebEngine REQUIRED)

include_directories(
    src-gen/vehicle/core/common
    src-gen/vehicle/core/proxy
    src-gen/vehicle/core/stub
    src-gen/vehicle/core/skel
    src-gen/vehicle/someip/common
    src-gen/vehicle/someip/proxy
    src-gen/vehicle/someip/stub
    src-gen/handler/core/common
    src-gen/handler/core/proxy
    src-gen/handler/core/stub
    src-gen/handler/core/skel
    src-gen/handler/someip/common
    src-gen/handler/someip/proxy
    src-gen/handler/someip/stub  
    ${COMMONAPI_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${VSOMEIP_INCLUDE_DIRS}
)

# VEHICLE LIBRARY
FILE(GLOB_RECURSE VEHICLE_SKEL_LIB_SRCS src-gen/vehicle/core/skel/*)
add_library(vehicleskel SHARED ${VEHICLE_SKEL_LIB_SRCS})
target_link_libraries(vehicleskel)
set_target_properties(vehicleskel PROPERTIES LINKER_LANGUAGE CXX LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

FILE(GLOB_RECURSE VEHICLE_SOMEIP_COMMON_LIB_SRCS src-gen/vehicle/someip/common/*.cpp)
add_library(vehiclesomeipcommon SHARED ${VEHICLE_SOMEIP_COMMON_LIB_SRCS})
target_link_libraries(vehiclesomeipcommon CommonAPI-SomeIP vsomeip3)
set_target_properties(vehiclesomeipcommon PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

FILE(GLOB_RECURSE VEHICLE_SOMEIP_PROXY_LIB_SRCS src-gen/vehicle/someip/proxy/*.cpp)
add_library(vehiclesomeipproxy SHARED ${VEHICLE_SOMEIP_PROXY_LIB_SRCS})
target_link_libraries(vehiclesomeipproxy CommonAPI-SomeIP vsomeip3)
set_target_properties(vehiclesomeipproxy PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

FILE(GLOB_RECURSE VEHICLE_SOMEIP_STUB_LIB_SRCS src-gen/vehicle/someip/stub/*.cpp)
add_library(vehiclesomeipstub SHARED ${VEHICLE_SOMEIP_STUB_LIB_SRCS})
target_link_libraries(vehiclesomeipstub CommonAPI-SomeIP vsomeip3)
set_target_properties(vehiclesomeipstub PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

# HANDLER LIBRARY
FILE(GLOB_RECURSE HANDLER_SKEL_LIB_SRCS src-gen/handler/core/skel/*)
add_library(handlerskel SHARED ${HANDLER_SKEL_LIB_SRCS})
target_link_libraries(handlerskel)
set_target_properties(handlerskel PROPERTIES LINKER_LANGUAGE CXX LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

FILE(GLOB_RECURSE HANDLER_SOMEIP_COMMON_LIB_SRCS src-gen/handler/someip/common/*.cpp)
add_library(handlersomeipcommon SHARED ${HANDLER_SOMEIP_COMMON_LIB_SRCS})
target_link_libraries(handlersomeipcommon CommonAPI-SomeIP vsomeip3)
set_target_properties(handlersomeipcommon PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

FILE(GLOB_RECURSE HANDLER_SOMEIP_PROXY_LIB_SRCS src-gen/handler/someip/proxy/*.cpp)
add_library(handlersomeipproxy SHARED ${HANDLER_SOMEIP_PROXY_LIB_SRCS})
target_link_libraries(handlersomeipproxy CommonAPI-SomeIP vsomeip3)
set_target_properties(handlersomeipproxy PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

FILE(GLOB_RECURSE HANDLER_SOMEIP_STUB_LIB_SRCS src-gen/handler/someip/stub/*.cpp)
add_library(handlersomeipstub SHARED ${HANDLER_SOMEIP_STUB_LIB_SRCS})
target_link_libraries(handlersomeipstub CommonAPI-SomeIP vsomeip3)
set_target_properties(handlersomeipstub PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${MY_PROJECT_NAME})

add_subdirectory(head_unit)
add_subdirectory(instrument_cluster)
add_subdirectory(sender)
add_subdirectory(exception_handler)

file(COPY ${CMAKE_SOURCE_DIR}/commonapi.ini 
     DESTINATION ${OUTPUT_DIRECTORY})

file(COPY ${CMAKE_SOURCE_DIR}/vsomeip.json 
     DESTINATION ${OUTPUT_DIRECTORY})