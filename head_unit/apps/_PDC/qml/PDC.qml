import QtQuick 2.12
import QtApplicationManager.Application 2.0

ApplicationManagerWindow {
    width: 886
    height: 540

    property int distance: 0

    property int splitInitX : 300
    property int priority: 0
    property int splitX : (priority===0) ? splitInitX : ((priority===1) ? 0 : width)
    property int init_interval : 200
    property int move_interval : 200


    Rectangle {
        anchors.fill: parent
        opacity: 0.5
        Behavior on opacity { NumberAnimation { duration: init_interval} }

        Video {
            id: leftlaytout
            x: -splitX
            y: 0
            width: parent.width
            height: parent.height    
            Behavior on x { NumberAnimation { duration: move_interval} }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    priority = (priority==1) ? 0 : 1
                }
            }
        }

        Graphic {
            y: 0
            z: 1
            width: splitX
            height: parent.height
            anchors.right: parent.right
            Behavior on width { NumberAnimation { duration: move_interval} }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                        priority = (priority==2) ? 0 : 2
                }
            }
        }

        Component.onCompleted: {
            opacity = 1
        }
    }

    IntentHandler {
        intentIds: [ "PDC" ]
        onRequestReceived: {
            distance = request.parameters["distance"]
            request.sendReply({ "succeeded" : true })
        }
    }
}
