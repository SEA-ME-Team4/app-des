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
    property string beforeApp: "_Home"

    signal iconReClicked(string applicationId)

    property bool brake: true
    property int speed: vehiclestatus.getSpeed()
    property int distance: vehiclestatus.getDistance()
    property int gear: vehiclestatus.getGear()
    property int init_gear: vehiclestatus.getGear()
    property string ambient: "#00000000"
    property var ambientresponse

    property bool is_P: (gear==0) ? 1 : 0
    property bool is_R: (gear==1) ? 1 : 0
    property bool is_N: (gear==2) ? 1 : 0
    property bool is_D: (gear==3) ? 1 : 0
    property bool is_S: (gear==4) ? 1 : 0
    property bool is_Moving: (init_gear==0 || init_gear==2) ? 0 : 1

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
                        show(applicationId)
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
            opacity : 1
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
    
    // Communicate with Application via Intent
    // Communicate with Application via Intent
    // Communicate with Application via Intent
    // Communicate with Application via Intent
    // Communicate with Application via Intent
    // Communicate with Application via Intent
    // Communicate with Application via Intent

    // Connect with CommonAPI
    VehicleStatus {
        id: vehiclestatus
        onBrakeChanged: {mainlayout.brake = brake}
        onSpeedChanged: {mainlayout.speed = speed}
        onDistanceChanged: {mainlayout.distance = distance}
        onGearChanged: {
            mainlayout.gear = gear
            if (is_D || is_S) {
                if (!is_Moving) {beforeApp = windowsModel.get(windowsModel.count-1).applicationId}
                is_Moving = true
                show(homeApp)
            }
            else if (is_R) {
                if (!is_Moving) {beforeApp = windowsModel.get(windowsModel.count-1).applicationId}
                is_Moving = true
                show(pdcApp)
            }
            else if (is_P || is_N) {
                show(beforeApp)
                is_Moving = false
            }
        }
    }

    // Initialization
    Component.onCompleted: {
        if (is_R) {
            ApplicationManager.application(pdcApp).start()
        }
        else {
            ApplicationManager.application(homeApp).start()
        }
    }

    // Custom Function for Show
    function show(nameApp) {
        if (ApplicationManager.application(nameApp).runState === Am.NotRunning) {
            ApplicationManager.startApplication(nameApp);
        }
        for (var i = 0; i < windowsModel.count; i++) {
            if (windowsModel.get(i).applicationId == nameApp) {
                windowsModel.move(i, windowsModel.count-1, 1)
            }
        }
    }
}
