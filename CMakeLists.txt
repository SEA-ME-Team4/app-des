cmake_minimum_required(VERSION 3.5)

project(app-hu LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

set(OUTPUT_FOLDER_NAME output)
set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_FOLDER_NAME})
set(LIBRARY_FOLDER_NAME library)
set(LIBRARY_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_FOLDER_NAME}/${LIBRARY_FOLDER_NAME})

set(EXECUTE_FOLDER_NAME execute)
set(EXECUTE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_FOLDER_NAME}/${EXECUTE_FOLDER_NAME})

find_package(CommonAPI REQUIRED)
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
file(GLOB_RECURSE VEHICLE_SKEL_LIB_SRCS src-gen/vehicle/core/skel/*)
add_library(vehicleskel SHARED ${VEHICLE_SKEL_LIB_SRCS})
target_link_libraries(vehicleskel)
set_target_properties(vehicleskel PROPERTIES LINKER_LANGUAGE CXX LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

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
FILE(GLOB_RECURSE HANDLER_SKEL_LIB_SRCS src-gen/handler/core/skel/*)
add_library(handlerskel SHARED ${HANDLER_SKEL_LIB_SRCS})
target_link_libraries(handlerskel)
set_target_properties(handlerskel PROPERTIES LINKER_LANGUAGE CXX LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

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

add_subdirectory(head_unit)
add_subdirectory(instrument_cluster)
add_subdirectory(sender)
add_subdirectory(exception_handler)

set(COMMONAPI_CONFIG_FOLDER_NAME config/commonapi/)
set(CONFIG_DIR ${CMAKE_SOURCE_DIR}/${COMMONAPI_CONFIG_FOLDER_NAME})
file(COPY ${CONFIG_DIR}
     DESTINATION ${OUTPUT_DIRECTORY}/${COMMONAPI_CONFIG_FOLDER_NAME})


set(SHELL_FOLDER_NAME tools/)
set(SHELL_DIR ${CMAKE_SOURCE_DIR}/${SHELL_FOLDER_NAME})
file(COPY ${SHELL_DIR}
     DESTINATION ${OUTPUT_DIRECTORY}/${SHELL_FOLDER_NAME})

# INSTALLATION (CHANGE INSTALL_DIRECTORY)
set(INSTALL_DIRECTORY /usr/bin/${PROJECT_NAME})

install(DIRECTORY ${LIBRARY_DIRECTORY}
     DESTINATION ${INSTALL_DIRECTORY}
     FILE_PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

install(DIRECTORY ${EXECUTE_DIRECTORY}
     DESTINATION ${INSTALL_DIRECTORY}
     FILE_PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)

install(DIRECTORY ${OUTPUT_DIRECTORY}/${COMMONAPI_CONFIG_FOLDER_NAME}
     DESTINATION ${INSTALL_DIRECTORY}
     FILE_PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

install(DIRECTORY ${OUTPUT_DIRECTORY}/${SHELL_FOLDER_NAME}
     DESTINATION ${INSTALL_DIRECTORY}
     FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ)