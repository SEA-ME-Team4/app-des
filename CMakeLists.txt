cmake_minimum_required(VERSION 3.5)

project(app-hu LANGUAGES CXX)

set(INSTALL_DIRECTORY /usr/bin/${PROJECT_NAME})
set(VSOMEIP_JSON_DIRECTORY /etc/vsomeip)

add_subdirectory(head_unit)
add_subdirectory(instrument_cluster)
add_subdirectory(sender)
add_subdirectory(exception_handler)

if (BUILD_CONF)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config/runtime/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/config/
        DESTINATION ${VSOMEIP_JSON_DIRECTORY}
        FILE_PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tools/
         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/tools/)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tools/
        DESTINATION ${INSTALL_DIRECTORY}
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE WORLD_EXECUTE)
endif()
