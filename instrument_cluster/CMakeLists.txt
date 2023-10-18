cmake_minimum_required(VERSION 3.5)

project(instrument_cluster LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

# Set Installation Path (If not set in Upper CMakeLists.txt)
if (!INSTALL_DIR)
    set(INSTALL_DIRECTORY /usr/bin/app-hu)
endif()

# Set Depend Library
set(stub_list)
set(proxy_list "Battery" "Brake" "Gear" "Speed" "ExceptionHandler")


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
    # Find Qt Application
    find_package(Qt5 COMPONENTS Core Quick Gui REQUIRED)

    include_directories(
        src
        ${COMMONAPI_INCLUDE_DIRS})

    # Build Execution
    add_executable(${PROJECT_NAME}
        src/main.cpp
        src/qml.qrc
        src/vehicleclient.cpp)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt5::Core Qt5::Quick Qt5::Gui
        CommonAPI)

    # Install Execution
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}/execute
        PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
    
    # Install Shell Script
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tools/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/tools/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tools/
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE WORLD_EXECUTE)
endif()