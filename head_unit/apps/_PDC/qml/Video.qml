import QtQuick 2.12
import QtMultimedia 5.12

Rectangle {
    Camera {
        id: camera
    }

    Rectangle {
        x: -parent.x/2
        width: parent.width
        height: parent.height
        color: "black"
        VideoOutput {
            source: camera
            anchors.fill: parent
        }
    }
}
