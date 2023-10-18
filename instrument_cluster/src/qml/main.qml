import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: instrumentcluster
    visible: true
    width: 400
    height: 1280
//    width: 1280
//    height: 400
    color: "black"

    InstrumentCluster {
        anchors.horizontalCenter:parent.horizontalCenter
        anchors.verticalCenter:parent.verticalCenter
        transform: [
            Rotation {
                origin.x: 640
                origin.y: 200
                angle: 270
//                angle: 0
                }
            ]
    }
}
