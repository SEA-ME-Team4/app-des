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
set(stub__proxylist "Battery" "Brake" "Gear" "Speed" "Maneuver" "Racer" "ExceptionHandler")
set(proxy_list "Battery" "Brake" "Gear" "Speed" "Maneuver" "Racer" "ExceptionHandler")


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
    function(library_generator type name)
        include_directories(
            src-gen/core/common/${name}
            src-gen/core/${type}/${name}
            src-gen/someip/common/${name}
            src-gen/someip/${type}/${name})
        file(GLOB_RECURSE SOMEIP_TYPE_LIB_SRCS src-gen/someip/${type}/${name}/*.cpp)        
        set(SOMEIP_TYPE_LIB_NAME ${name}someip${type})
        string(TOLOWER ${SOMEIP_TYPE_LIB_NAME} SOMEIP_TYPE_LIB_NAME)
        add_library(${SOMEIP_TYPE_LIB_NAME} SHARED ${SOMEIP_TYPE_LIB_SRCS})
        target_link_libraries(${SOMEIP_TYPE_LIB_NAME} CommonAPI-SomeIP vsomeip3)
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${SOMEIP_TYPE_LIB_NAME}.so
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
    endfunction()

    # Build stub Library
    foreach(stub ${stub_list})
        library_generator("stub" ${stub})
    endforeach()

    # Build proxy Library
    foreach(proxy ${proxy_list})
        library_generator("proxy" ${proxy})
    endforeach()
endif()