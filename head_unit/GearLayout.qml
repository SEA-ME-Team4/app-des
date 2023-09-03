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
        id: button
        implicitWidth: 100
        implicitHeight: 100
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
            color: button.checked ? "white" : "grey"
            font.pointSize: button.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
    }

    Button {
        id: button1
        implicitWidth: 100
        implicitHeight: 100
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
            color: button1.checked ? "white" : "grey"
            font.pointSize: button1.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
    }

    Button {
        id: button2
        implicitWidth: 100
        implicitHeight: 100
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
            color: button2.checked ? "white" : "grey"
            font.pointSize: button2.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
    }

    Button {
        id: button3
        implicitWidth: 100
        implicitHeight: 100
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
            color: button3.checked ? "white" : "grey"
            font.pointSize: button3.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
    }

    Button {
        id: button4
        implicitWidth: 100
        implicitHeight: 100
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        background: Rectangle {
            color: "transparent"
        }

        contentItem: Text {
            text: qsTr("  S")
            color: button4.checked ? "red" : "grey"
            font.pointSize: button4.checked ? 24 : 20
            font.bold: true
            anchors.centerIn: parent
        }
    }
}
