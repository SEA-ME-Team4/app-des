project(libsomeip LANGUAGES CXX)

find_package(CommonAPI-SomeIP REQUIRED)
find_package(vsomeip3 REQUIRED)

include_directories(
    src-gen/vehicle/someip/common
    src-gen/vehicle/someip/proxy
    src-gen/vehicle/someip/stub
    src-gen/handler/someip/common
    src-gen/handler/someip/proxy
    src-gen/handler/someip/stub
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${VSOMEIP_INCLUDE_DIRS})

# VEHICLE LIBRARY
file(GLOB_RECURSE VEHICLE_SOMEIP_COMMON_LIB_SRCS src-gen/vehicle/someip/common/*.cpp)
add_library(vehiclesomeipcommon SHARED ${VEHICLE_SOMEIP_COMMON_LIB_SRCS})
target_link_libraries(vehiclesomeipcommon CommonAPI-SomeIP vsomeip3)
set_target_properties(vehiclesomeipcommon PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

file(GLOB_RECURSE VEHICLE_SOMEIP_PROXY_LIB_SRCS src-gen/vehicle/someip/proxy/*.cpp)
add_library(vehiclesomeipproxy SHARED ${VEHICLE_SOMEIP_PROXY_LIB_SRCS})
target_link_libraries(vehiclesomeipproxy CommonAPI-SomeIP vsomeip3)
set_target_properties(vehiclesomeipproxy PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

file(GLOB_RECURSE VEHICLE_SOMEIP_STUB_LIB_SRCS src-gen/vehicle/someip/stub/*.cpp)
add_library(vehiclesomeipstub SHARED ${VEHICLE_SOMEIP_STUB_LIB_SRCS})
target_link_libraries(vehiclesomeipstub CommonAPI-SomeIP vsomeip3)
set_target_properties(vehiclesomeipstub PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

# HANDLER LIBRARY
file(GLOB_RECURSE HANDLER_SOMEIP_COMMON_LIB_SRCS src-gen/handler/someip/common/*.cpp)
add_library(handlersomeipcommon SHARED ${HANDLER_SOMEIP_COMMON_LIB_SRCS})
target_link_libraries(handlersomeipcommon CommonAPI-SomeIP vsomeip3)
set_target_properties(handlersomeipcommon PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

file(GLOB_RECURSE HANDLER_SOMEIP_PROXY_LIB_SRCS src-gen/handler/someip/proxy/*.cpp)
add_library(handlersomeipproxy SHARED ${HANDLER_SOMEIP_PROXY_LIB_SRCS})
target_link_libraries(handlersomeipproxy CommonAPI-SomeIP vsomeip3)
set_target_properties(handlersomeipproxy PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

file(GLOB_RECURSE HANDLER_SOMEIP_STUB_LIB_SRCS src-gen/handler/someip/stub/*.cpp)
add_library(handlersomeipstub SHARED ${HANDLER_SOMEIP_STUB_LIB_SRCS})
target_link_libraries(handlersomeipstub CommonAPI-SomeIP vsomeip3)
set_target_properties(handlersomeipstub PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})