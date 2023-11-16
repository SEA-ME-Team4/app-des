import QtQuick 2.12
import QtApplicationManager.Application 2.0

ApplicationManagerWindow {
    property int init_interval : 200
    Rectangle {
        anchors.fill: parent
        opacity: 0.5
        Behavior on opacity { NumberAnimation { duration: init_interval} }
        color: "red"

        Text {
            anchors.centerIn: parent
            text: "Ambient"
            font.pointSize: 50
        }
        Component.onCompleted: {
            opacity = 1
        }
    }
}
