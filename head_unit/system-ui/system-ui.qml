import QtQuick 2.12
import QtQuick.Layouts 1.11
import QtApplicationManager 2.0
import QtApplicationManager.SystemUI 2.0
import QtQuick.VirtualKeyboard 2.0

import User.VehicleStatus 1.0

Rectangle {
    id: mainlayout
    width: 1024
    height: 600
    color: "black"

    property string homeApp: "_Home"
    property string pdcApp: "_PDC"
    property string ambientApp: "Ambient"
    property string youtubeApp: "Youtube"

    signal iconReClicked(string applicationId)

    property bool brake: vehiclestatus.getBrake()
    property int speed: vehiclestatus.getSpeed()
    property int distance: vehiclestatus.getDistance()
    property int gear: vehiclestatus.getGear()

    property bool is_P: (gear==0) ? 1 : 0
    property bool is_R: (gear==1) ? 1 : 0
    property bool is_N: (gear==2) ? 1 : 0
    property bool is_D: (gear==3) ? 1 : 0
    property bool is_S: (gear==4) ? 1 : 0
    property bool is_Moving: (is_S || is_D || is_R) ? 1 : 0

    // VirtualKeyboard
    InputPanel {
        id: inputPanel
        x: 138
        z: 99
        width: 886
        anchors.bottom: parent.bottom
        visible: Qt.inputMethod.visible
    }

    // Gear
    GearLayout {
        id: gearLayout
        width: 138
        height: 600
        anchors.left: parent.left
    }

    // Application List
    Row {
        id: toolbarLayout
        x:138
        y:0
        width: 886
        height: 60
        spacing: 15

        Repeater {
            model: ApplicationManager
            Image {
                source: model.icon
                MouseArea {
                    anchors.fill: parent
                    enabled: is_Moving ? false : true
                    onClicked: {
                        mainlayout.focus = true
                        model.isRunning ? iconReClicked(applicationId) : application.start()
                    }
                }
                width: 60; height: 60
                opacity: is_Moving ? 0.5 : 1
            }
        }
    }

    // Application Area
    Repeater {
        model: ListModel { id: windowsModel }
        WindowItem {
            id: windowItem
            x: 138
            y: 60
            z: model.index
            width: 886
            height: 540
            window: model.window
            opacity : model.index===(windowsModel.count-1) ? 1 : 0.5
            Behavior on opacity { NumberAnimation { duration: 200} }
        }
    }

    // Exception Handling with ApplicationManager
    Connections {
        target: ApplicationManager
        onApplicationRunStateChanged: {
            if (runState === Am.NotRunning) {
                for (var i = 0; i < windowsModel.count; i++) {
                    if (windowsModel.get(i).applicationId === id) {
                        windowsModel.remove(i, 1)
                    }
                }
            }
        }
    }

    // Connect WindowManager with applicationId
    Connections {
        target: WindowManager
        onWindowAdded: {
            windowsModel.append({"window":window, "applicationId":window.application.id});
        }
    }

    // For Rotating windowsModel with custom signal (iconReClicked)
    Connections {
        target: mainlayout
        onIconReClicked: {
            for (var i = 0; i < windowsModel.count; i++) {
                if (windowsModel.get(i).applicationId === applicationId) {
                    windowsModel.move(i, windowsModel.count-1, 1)
                }
            }
        }
    }

    // Initialization
    Component.onCompleted: {
        ApplicationManager.application(homeApp).start()
//        ApplicationManager.application(pdcApp).start()
    }

    // Connect with CommonAPI
    VehicleStatus {
        id: vehiclestatus
        onBrakeChanged: {mainlayout.brake = brake}
        onSpeedChanged: {mainlayout.speed = speed}
        onDistanceChanged: {mainlayout.distance = distance}
        onGearChanged: {
            mainlayout.gear = gear
            if (is_D || is_S) {
                if (ApplicationManager.application(homeApp).runState === Am.NotRunning) {
                    ApplicationManager.startApplication(homeApp);
                }
                for (var i = 0; i < windowsModel.count; i++) {
                    if (windowsModel.get(i).applicationId === homeApp) {
                        windowsModel.move(i, windowsModel.count-1, 1)
                    }
                }
            }
            else if (is_R) {
                if (ApplicationManager.application(pdcApp).runState === Am.NotRunning) {
                    ApplicationManager.startApplication(pdcApp);
                }
                for (var i = 0; i < windowsModel.count; i++) {
                    if (windowsModel.get(i).applicationId == pdcApp) {
                        windowsModel.move(i, windowsModel.count-1, 1)
                    }
                }
            }
        }
    }
}
