import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

GridLayout {
    width: 886
    height: 553

    property color ambientColor

    Rectangle {
        id: colorPalette
        width: parent.width
        height: parent.height

        color: "#000000"

        GridLayout {
            columns: 4
            rows: 4

            width: parent / 2
            height: parent / 2
            anchors.centerIn: parent

            Repeater {
                model: [
                    "red", "orange", "yellow", "green", "blue", "indigo", "violet", "pink",
                    "brown", "purple", "lime", "olive", "cyan", "magenta", "gray", "black",
                ]

                Rectangle {
                    width: colorPalette.width / 5
                    height: colorPalette.height / 5

                    color: modelData

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainlayout.ambientColor = color
                            ambientsLayout.visible = false
                            menuLayout.visible = true
                        }
                    }
                }
            }
        }
    }
}