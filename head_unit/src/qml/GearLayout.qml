import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

GridLayout {
    width: 138
    height: 600
    columns: 1
    rows: 6

    property int text_size: 30
    property int button_size: 70
    property real min_opacity: 0.7
    property real default_opacity: 1
    property int  opacity_interval: 100
    property ButtonGroup buttonGroup

    property bool gearChange: ((!mainlayout.is_P) || (mainlayout.is_P && mainlayout.brake)) ? true : false

    Button {
        id: gear_P
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        ButtonGroup.group: buttonGroup
        Layout.topMargin: 20
        opacity: (mainlayout.is_P) ? default_opacity : min_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: mainlayout.brake

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
