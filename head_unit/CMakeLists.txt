project(head_unit LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/qml.qrc
    src/youtubesearch.cpp
    src/vehiclestatus.cpp
    src/GearStatusStubImpl.cpp)
target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network Qt5::Multimedia Qt5::WebEngine
    CommonAPI)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_DIRECTORY})

