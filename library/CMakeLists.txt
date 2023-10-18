cmake_minimum_required(VERSION 3.5)

project(library LANGUAGES CXX)

set(INSTALL_DIRECTORY /usr/bin/${PROJECT_NAME})
set(VSOMEIP_JSON_DIRECTORY /etc/vsomeip)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

# Set Installation Path (If not set in Upper CMakeLists.txt)
if (!INSTALL_DIR)
    set(INSTALL_DIRECTORY /usr/bin/app-hu)
endif()

# Set Depend Library
set(proxy_stub_list "Battery" "Brake" "Gear" "Speed" "Maneuver" "Racer" "ExceptionHandler")

# Build Library
if (BUILD_LIB)
    # Find CommonAPI / CommonAPI-SomeIP / vsomeip3
    find_package(CommonAPI REQUIRED)
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)
    include_directories(
        # RUNTIME
        ${COMMONAPI_INCLUDE_DIRS}
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP_INCLUDE_DIRS})

    # Library Build Fuction (stub and proxy)
    function(proxy_stub_include interface)
        include_directories(
            src-gen/core/common/${interface}
            src-gen/core/proxy/${interface}
            src-gen/core/stub/${interface}
            src-gen/someip/common/${interface}
            src-gen/someip/proxy/${interface}
            src-gen/someip/stub/${interface})
    endfunction()

    function(library_generator type name)
        file(GLOB_RECURSE SOMEIP_TYPE_LIB_SRCS src-gen/someip/${type}/${name}/*.cpp)        
        set(SOMEIP_TYPE_LIB_NAME ${name}someip${type})
        string(TOLOWER ${SOMEIP_TYPE_LIB_NAME} SOMEIP_TYPE_LIB_NAME)
        add_library(${SOMEIP_TYPE_LIB_NAME} SHARED ${SOMEIP_TYPE_LIB_SRCS})
        target_link_libraries(${SOMEIP_TYPE_LIB_NAME} CommonAPI-SomeIP vsomeip3)
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${SOMEIP_TYPE_LIB_NAME}.so
            DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}
            PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
    endfunction()

    # Build proxy and stub Library (.so)
    foreach(interface ${proxy_stub_list})
        proxy_stub_include(${interface})
        library_generator("stub" ${interface})
        library_generator("proxy" ${interface})
    endforeach()
endif()