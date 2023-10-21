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
    property real access_opacity: 0.75
    property real default_opacity: 1
    property int  opacity_interval: 100
    property ButtonGroup buttonGroup
    property bool gearChange: (menuLayout.currentGear !== "P") || (menuLayout.currentGear === "P" && mainlayout.brake)

    Button {
        id: gear_P
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        checked: true
        ButtonGroup.group: buttonGroup
        Layout.topMargin: 20
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: mainlayout.brake

        contentItem: Text {
            text: qsTr("P")
            horizontalAlignment: Text.AlignHCenter
            color: gear_P.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_P.opacity
        }

        onClicked: {
            menuLayout.currentGear = "P";
            gear_P.opacity = default_opacity
            gear_R.opacity = min_opacity
            gear_N.opacity = min_opacity
            gear_D.opacity = min_opacity
            gear_S.opacity = min_opacity
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
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("R")
            horizontalAlignment: Text.AlignHCenter
            color: gear_R.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_R.opacity
        }

        onClicked: {
            contentsLayout.visible = false;
            menuLayout.visible = true;
            menuLayout.currentGear = "R";
            gear_P.opacity = min_opacity
            gear_R.opacity = default_opacity
            gear_N.opacity = min_opacity
            gear_D.opacity = min_opacity
            gear_S.opacity = min_opacity
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
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("N")
            horizontalAlignment: Text.AlignHCenter
            color: gear_N.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_N.opacity
        }
        onClicked: {
            menuLayout.currentGear = "N";
            gear_P.opacity = min_opacity
            gear_R.opacity = min_opacity
            gear_N.opacity = default_opacity
            gear_D.opacity = min_opacity
            gear_S.opacity = min_opacity
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
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("D")
            horizontalAlignment: Text.AlignHCenter
            color: gear_D.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_D.opacity
        }
        onClicked: {
            contentsLayout.visible = false;
            menuLayout.visible = true;
            menuLayout.currentGear = "D";
            gear_P.opacity = min_opacity
            gear_R.opacity = min_opacity
            gear_N.opacity = min_opacity
            gear_D.opacity = default_opacity
            gear_S.opacity = min_opacity
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
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        enabled: gearChange

        contentItem: Text {
            text: qsTr("S")
            horizontalAlignment: Text.AlignHCenter
            color: gear_S.checked ? "red" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_S.opacity
        }

        onClicked: {
            contentsLayout.visible = false;
            menuLayout.visible = true;
            menuLayout.currentGear = "S";
            gear_P.opacity = min_opacity
            gear_R.opacity = min_opacity
            gear_N.opacity = min_opacity
            gear_D.opacity = min_opacity
            gear_S.opacity = default_opacity
            vehiclestatus.sendGear(4)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }
}
