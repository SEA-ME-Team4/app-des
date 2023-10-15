import QtQuick 2.12
import QtQuick.Controls 2.12
import QtWebEngine 1.8
import YouTubeSearch 1.0
import QtQuick.Layouts 1.3
import VehicleStatus 1.0
import "."


ApplicationWindow {
    id: mainlayout
    visible: true
    width: 1024
    height: 600
    color: "#000000"

    property var searchResults: []

    property bool brakestatus: false

    property bool speed_timeout: true
    property bool battery_timeout: true
    property bool input_timeout: true
    property bool racer_timeout: true
    property bool gear_timeout: true

    property color ambientColor: "black"

    Rectangle {
        id: bottom_border
        width: parent.width
        height: 5
        anchors.bottom: parent.bottom
        color: ambientColor
    }

    Rectangle {
        id: right_border
        width: 5
        height: parent.height
        anchors.right: parent.right
        color: ambientColor
    }

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
        onBrakeChanged: {mainlayout.brakestatus = brake}
        onSpeedStatus: {mainlayout.speed_timeout = status}
        onBatteryStatus: {mainlayout.battery_timeout = status}
        onInputStatus: {mainlayout.input_timeout = status}
        onRacerStatus: {mainlayout.racer_timeout = status}
        onGearStatus: {mainlayout.gear_timeout = status}
    }

}
