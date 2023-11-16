cmake_minimum_required(VERSION 3.5)

project(head_unit LANGUAGES CXX)

# Set Installation Path (If not set in Upper CMakeLists.txt)
if (!INSTALL_DIR)
    set(INSTALL_DIRECTORY /usr/bin/app-hu)
endif()

# Build Execution
if (BUILD_EXE)
    # Install System-UI
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/system-ui/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/system-ui/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/system-ui/
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}/system-ui/)
endif()

# Build Application
if (BUILD_APP)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/apps/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/apps/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/apps/
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}/apps)
endif()

# Build Library
if (BUILD_LIB)
    add_subdirectory(library)
endif()

# Build Configuration
if (BUILD_CONF)
    # Install Shell Script
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tools/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/tools/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tools/
        DESTINATION ${INSTALL_DIRECTORY}/${PROJECT_NAME}
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)
endif()