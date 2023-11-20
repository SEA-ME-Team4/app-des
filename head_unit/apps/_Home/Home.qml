import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtApplicationManager.Application 2.0

ApplicationManagerWindow {
    width: 886
    height: 540

    property bool brake: false
    property int speed: 0
    property int gear: 0
    property color ambient: "#000000"

    property bool is_P: (gear==0) ? 1 : 0
    property bool is_R: (gear==1) ? 1 : 0
    property bool is_N: (gear==2) ? 1 : 0
    property bool is_D: (gear==3) ? 1 : 0
    property bool is_S: (gear==4) ? 1 : 0

    property real default_opacity: 1
    property real min_opacity: 0
    property int  opacity_interval: 500

    Rectangle {
        id: menuImages
        width: parent.width
        height: parent.height
        color: "black"
        Image {
            id: field
            visible: true
            source: "images/field.png"
            anchors.centerIn: parent
            width: menuImages.width * 0.8
            height: width / sourceSize.width * sourceSize.height
        }

//        ColorOverlay {
//            anchors.fill: field
//            source: field
//            color: ambientsLayout.ambientColor
//        }

        Image {
            id: car_highlights
            source: "images/car-highlights.png"
            visible: true
            anchors.centerIn: parent
            width: menuImages.width * 0.8
            height: width / sourceSize.width * sourceSize.height
            opacity: (is_P || brake) ? default_opacity : min_opacity

            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: rearlight
            source: "images/rearlight.png"
            visible: true
            anchors.right: field.right
            anchors.bottom: field.bottom
            width: menuImages.width * 0.8
            height: width / sourceSize.width * sourceSize.height
            opacity: (is_R) ? default_opacity : min_opacity

            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: arrow
            source: "images/arrow-0.png"
            visible: true
            anchors.centerIn: field
            width: menuImages.width * 0.03
            height: width / sourceSize.width * sourceSize.height
            opacity: ((is_D || is_S) && !brake) ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }


        Image {
            id: left_brake
            source: "images/red-border-left.png"
            visible: true
            x: 300
            y: 190
            width: menuImages.width * 0.1
            height: width / sourceSize.width * sourceSize.height
            opacity: brake ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: right_brake
            source: "images/red-border-right.png"
            visible: true
            x: 490
            y: 190
            width: menuImages.width * 0.1
            height: width / sourceSize.width * sourceSize.height
            opacity: brake ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: white_left1
            source: "images/white-line-left.png"
            visible: true
            x: 300
            y: 380
            width: menuImages.width * 0.05
            height: width / sourceSize.width * sourceSize.height
            opacity: (!brake && speed > 0 && (is_D || is_S)) ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: white_left2
            source: "images/white-line-left.png"
            visible: true
            x: 330
            y: 300
            width: menuImages.width * 0.05
            height: width / sourceSize.width * sourceSize.height
            opacity: (!brake &&speed > 0 && (is_D || is_S)) ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: white_left3
            source: "images/white-line-left.png"
            visible: true
            x: 360
            y: 220
            width: menuImages.width * 0.05
            height: width / sourceSize.width * sourceSize.height
            opacity: (!brake &&speed > 0 && (is_D || is_S)) ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: white_right1
            source: "images/white-line-right.png"
            visible: true
            x: 530
            y: 380
            width: menuImages.width * 0.05
            height: width / sourceSize.width * sourceSize.height
            opacity: (!brake &&speed > 0 && (is_D || is_S)) ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: white_right2
            source: "images/white-line-right.png"
            visible: true
            x: 500
            y: 300
            width: menuImages.width * 0.05
            height: width / sourceSize.width * sourceSize.height
            opacity: (!brake &&speed > 0 && (is_D || is_S)) ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }

        Image {
            id: white_right3
            source: "images/white-line-right.png"
            visible: true
            x: 470
            y: 220
            width: menuImages.width * 0.05
            height: width / sourceSize.width * sourceSize.height
            opacity: (!brake &&speed > 0 && (is_D || is_S)) ? default_opacity : min_opacity


            Behavior on opacity {
                NumberAnimation { duration: opacity_interval }
            }
        }
    }

    IntentHandler {
        intentIds: [ "Brake", "Speed", "Gear" ]
        onRequestReceived: {
            if (request.intentId === "Brake") {brake = request.parameters["Brake"]}                
            if (request.intentId === "Speed") {speed = request.parameters["Speed"]}
            if (request.intentId === "Gear") {gear = request.parameters["Gear"]}
            if (request.intentId === "Ambient") {ambient = request.parameters["Ambient"]}
            request.sendReply({ "succeeded" : true })
        }
    }
}
