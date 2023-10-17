cmake_minimum_required(VERSION 3.5)

project(app-hu LANGUAGES CXX)

set(INSTALL_DIRECTORY /usr/bin/${PROJECT_NAME})
# set(INSTALL_DIRECTORY /home/mczb/cmtest)

add_subdirectory(head_unit)
add_subdirectory(instrument_cluster)
add_subdirectory(sender)
add_subdirectory(exception_handler)