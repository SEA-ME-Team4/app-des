cmake_minimum_required(VERSION 3.5)

# Set Project Name
project(input LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

# Set Installation Path (If not set in Upper CMakeLists.txt)
if (!INSTALL_DIR)
    set(INSTALL_DIRECTORY /usr/bin/app-hu)
endif()

# Set Depend Library
set(stub_list "Brake" "Maneuver")
set(proxy_list)


# Build Execution
if (BUILD_EXE)
    # Include Directories
    foreach(stub ${stub_list})
        include_directories(
            src-gen/core/stub/${stub}
            src-gen/core/skel/${stub}
            src-gen/core/common/${stub}
        )
    endforeach()
    foreach(proxy ${proxy_list})
        include_directories(
            src-gen/core/proxy/${proxy}
            src-gen/core/common/${proxy}
        )
    endforeach()

    # Find CommonAPI
    find_package(CommonAPI REQUIRED)
    # Find Python Package
    find_package(PythonLibs REQUIRED)

    include_directories(
        src
        ${COMMONAPI_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS})

    # Build Execution
    add_executable(${PROJECT_NAME}
        src/main.cpp
        src/gamepad.cpp
        src/input.cpp
        src/BrakeStatusStubImpl.cpp
        src/ManeuverStubImpl.cpp)
    target_link_libraries(${PROJECT_NAME}
        ${PYTHON_LIBRARIES}
        CommonAPI)

    # Install Execution
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}/execute
        PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
endif()


# Build Library
if (BUILD_LIB)
    # Find CommonAPI-SomeIP/vsomeip3
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)
    include_directories(
        # RUNTIME
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP_INCLUDE_DIRS})

    # Library Build Fuction (common, stub or proxy)
    function(library_generator type name)
        include_directories(
            # src-gen/someip/common/${name}
            src-gen/someip/${type}/${name})
        # common Library
        # file(GLOB_RECURSE SOMEIP_COMMON_LIB_SRCS src-gen/someip/common/${name}/*.cpp)
        # set(SOMEIP_COMMON_LIB_NAME _${PROJECT_NAME}_${name}someipcommon)
        # string(TOLOWER ${SOMEIP_COMMON_LIB_NAME} SOMEIP_COMMON_LIB_NAME)
        # add_library(${SOMEIP_COMMON_LIB_NAME} SHARED ${SOMEIP_COMMON_LIB_SRCS})
        # target_link_libraries(${SOMEIP_COMMON_LIB_NAME} CommonAPI-SomeIP vsomeip3)
        # install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${SOMEIP_COMMON_LIB_NAME}.so
        # DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}/library
        # PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
        # Type(stub/proxy) Library
        file(GLOB_RECURSE SOMEIP_TYPE_LIB_SRCS src-gen/someip/${type}/${name}/*.cpp)        
        set(SOMEIP_TYPE_LIB_NAME _${PROJECT_NAME}_${name}someip${type})
        string(TOLOWER ${SOMEIP_TYPE_LIB_NAME} SOMEIP_TYPE_LIB_NAME)
        add_library(${SOMEIP_TYPE_LIB_NAME} SHARED ${SOMEIP_TYPE_LIB_SRCS})
        target_link_libraries(${SOMEIP_TYPE_LIB_NAME} CommonAPI-SomeIP vsomeip3)
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${SOMEIP_TYPE_LIB_NAME}.so
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}/library
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


# Build Config
if (BUILD_CONF)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/config/
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}/config
        FILE_PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tools/
         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/tools/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tools/
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE WORLD_EXECUTE)
endif()