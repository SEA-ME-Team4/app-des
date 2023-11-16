import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0


GridLayout {
    width: parent.width
    height: parent.height
    columns: 1
    rows: 6

    property int text_size: 25
    property int button_size: 70
    property real min_opacity: 0.7
    property real default_opacity: 1
    property int  opacity_interval: 100
    property bool gearHear: true
    property ButtonGroup buttonGroup

    property bool gearChange: (gearHear && ((!mainlayout.is_P) || (mainlayout.is_P && mainlayout.brake))) ? true : false

    Button {
        id: gamepad
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        ButtonGroup.group: buttonGroup

        background: null
        checkable: true
        checked: false

        Image {
            id: game
            anchors.fill: parent
            source: "images/gamepad.png"
            fillMode: Image.PreserveAspectFit
        }

        onClicked: {
            vehiclestatus.sendGear(6)
            if (gearHear==true) {
                gearHear = false
            }
            else {
                gearHear = true
            }
        }
        
        ColorOverlay {
            anchors.fill: game
            source: game
            color: gearHear ? "red" : "#ffffff"
        }
    }

    Button {
        id: gear_P
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        ButtonGroup.group: buttonGroup
        opacity: (mainlayout.is_P) ? default_opacity : min_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: (mainlayout.brake && gearHear) ? true : false

        contentItem: Text {
            text: qsTr("P")
            horizontalAlignment: Text.AlignHCenter
            color: (mainlayout.is_P) ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_P.opacity
        }

        onClicked: {
            vehiclestatus.sendGear(0)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

    Button {
        id: gear_R
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        ButtonGroup.group: buttonGroup
        opacity: (mainlayout.is_R) ? default_opacity : min_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("R")
            horizontalAlignment: Text.AlignHCenter
            color: (mainlayout.is_R) ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_R.opacity
        }

        onClicked: {
            vehiclestatus.sendGear(1)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

    Button {
        id: gear_N
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        ButtonGroup.group: buttonGroup
        opacity: (mainlayout.is_N) ? default_opacity : min_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("N")
            horizontalAlignment: Text.AlignHCenter
            color: (mainlayout.is_N) ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_N.opacity
        }

        onClicked: {
            vehiclestatus.sendGear(2)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

    Button {
        id: gear_D
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        ButtonGroup.group: buttonGroup
        opacity: (mainlayout.is_D) ? default_opacity : min_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("D")
            horizontalAlignment: Text.AlignHCenter
            color: (mainlayout.is_D) ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_D.opacity
        }

        onClicked: {
            vehiclestatus.sendGear(3)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

    Button {
        id: gear_S
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        ButtonGroup.group: buttonGroup
        opacity: (mainlayout.is_S) ? default_opacity : min_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("S")
            horizontalAlignment: Text.AlignHCenter
            color: (mainlayout.is_S) ? "red" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_S.opacity
        }

        onClicked: {
            vehiclestatus.sendGear(4)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }
}