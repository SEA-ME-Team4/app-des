import QtQuick 2.12
import QtQuick.Controls 2.12
import QtWebEngine 1.8
import YouTubeSearch 1.0
import QtQuick.Layouts 1.3
import VehicleStatus 1.0
import "."


Rectangle {
    id: mainlayout
    visible: true
    width: 1024
    height: 600
    color: "#000000"

    property var searchResults: []

    property bool brake: vehiclestatus.getBrake()
    property int speed: vehiclestatus.getSpeed()
    property int distance: vehiclestatus.getDistance()
    property int gear: vehiclestatus.getGear()

    property bool is_P: (gear==0) ? 1 : 0
    property bool is_R: (gear==1) ? 1 : 0
    property bool is_N: (gear==2) ? 1 : 0
    property bool is_D: (gear==3) ? 1 : 0
    property bool is_S: (gear==4) ? 1 : 0

    YouTubeSearch {
        id: youTubeSearch
    }

    ButtonGroup { id: buttonGroup }

    GearLayout {
        id: gearLayout
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        buttonGroup: buttonGroup
    }

    ToolbarLayout {
        id: toolbarLayout
        anchors.left: gearLayout.right
        anchors.right: parent.right
        anchors.top: parent.top
    }

    MenuLayout {
        id: menuLayout
        anchors.left: gearLayout.right
        anchors.right: parent.right
        anchors.top: toolbarLayout.bottom
        anchors.bottom: parent.bottom
        visible: true
    }

    ContentsLayout {
        id: contentsLayout
        anchors.left: gearLayout.right
        anchors.right: parent.right
        anchors.top: toolbarLayout.bottom
        anchors.bottom: parent.bottom
        youTubeSearch: youTubeSearch
        visible: false
    }

    AmbientsLayout {
        id: ambientsLayout
        anchors.left: gearLayout.right
        anchors.right: parent.right
        anchors.top: toolbarLayout.bottom
        anchors.bottom: parent.bottom
        visible: false
    }

    VehicleStatus {
        id: vehiclestatus
        onBrakeChanged: {mainlayout.brake = brake}
        onSpeedChanged: {mainlayout.speed = speed}
        onDistanceChanged: {mainlayout.distance = distance}
        onGearChanged: {mainlayout.gear = gear}
    }
}
