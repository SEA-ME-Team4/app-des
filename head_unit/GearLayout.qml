import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

GridLayout {
    width: 138
    height: 600
    columns: 1
    rows: 5

    property ButtonGroup buttonGroup

    Button {
        id: gear_P
        implicitWidth: 100
        implicitHeight: 100
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        font.pointSize: checked ? 24 : 20
        font.bold: true
        background: Rectangle {
            color: "transparent"
        }

        contentItem: Text {
            text: qsTr("  P")
            color: gear_P.checked ? "white" : "grey"
            font.pointSize: gear_P.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
        onClicked: {
           menuLayout.isGearSSelected = false;
        }
    }

    Button {
        id: gear_R
        implicitWidth: 100
        implicitHeight: 100
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        font.pointSize: checked ? 24 : 20
        font.bold: true
        background: Rectangle {
            color: "transparent"
        }

        contentItem: Text {
            text: qsTr("  R")
            color: gear_R.checked ? "white" : "grey"
            font.pointSize: gear_R.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
        onClicked: {
           contentsLayout.visible = false;
           menuLayout.visible = true;
            menuLayout.isGearSSelected = false;
        }
    }

    Button {
        id: gear_N
        implicitWidth: 100
        implicitHeight: 100
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        font.pointSize: checked ? 24 : 20
        font.bold: true
        background: Rectangle {
            color: "transparent"
        }

        contentItem: Text {
            text: qsTr("  N")
            color: gear_N.checked ? "white" : "grey"
            font.pointSize: gear_N.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
        onClicked: {
           menuLayout.isGearSSelected = false;
        }
    }

    Button {
        id: gear_D
        implicitWidth: 100
        implicitHeight: 100
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        font.pointSize: checked ? 24 : 20
        font.bold: true
        background: Rectangle {
            color: "transparent"
        }

        contentItem: Text {
            text: qsTr("  D")
            color: gear_D.checked ? "white" : "grey"
            font.pointSize: gear_D.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
        onClicked: {
           contentsLayout.visible = false;
           menuLayout.visible = true;
           menuLayout.isGearSSelected = false;
        }
    }

    Button {
        id: gear_S
        implicitWidth: 100
        implicitHeight: 100
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        background: Rectangle {
            color: "transparent"
        }

        contentItem: Text {
            text: qsTr("  S")
            color: gear_S.checked ? "red" : "grey"
            font.pointSize: gear_S.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
        onClicked: {
           contentsLayout.visible = false;
           menuLayout.visible = true;
           menuLayout.isGearSSelected = true;
        }
    }
}
