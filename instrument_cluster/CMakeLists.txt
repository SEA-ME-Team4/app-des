project(instrument_cluster LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/qml.qrc
    src/vehicleclient.cpp)
target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt5::Core Qt5::Quick Qt5::Gui
  CommonAPI)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})

