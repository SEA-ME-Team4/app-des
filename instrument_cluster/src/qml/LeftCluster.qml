import QtQuick 2.0

Rectangle{
    id: leftcluster
    color: "black"

    property int update_interval: 20
    property color textcolor: "#f7f2f2"
    property int y_offset: 16
    property int left_angle_offset: -160
    property int real_left_angle: Math.abs(parent.speed/5) + left_angle_offset
    property int left_angle: (real_left_angle>20) ? 20 : real_left_angle

    Rectangle {
        x: 0
        y: 0

        Text {
            x: 129
            y: 278
            color: "white"
            text: "0"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 83
            y: 254
            color: "white"
            text: "100"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 52
            y: 218
            color: "white"
            text: "200"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 36
            y: 173
            color: "white"
            text: "300"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 36
            y: 125
            color: "white"
            text: "400"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 52
            y: 80
            color: "white"
            text: "500"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 83
            y: 43
            color: "white"
            text: "600"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 121
            y: 19
            color: "white"
            text: "700"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 168
            y: 11
            color: "white"
            text: "800"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
        Text {
            x: 215
            y: 19
            color: "white"
            text: "900"
            font.bold: false
            font.family: "Sarabun"
            font.pixelSize: 13
        }
    }

    Image {
        id: leftshadow
        x: -60
        y: -83
        width: 480
        height: 480
        source: "/images/shadow.png"
        fillMode: Image.PreserveAspectFit
        transform: [
            Rotation {
                origin.x: leftshadow.width/2
                origin.y: leftshadow.height/2
                angle: leftcluster.left_angle
                Behavior on angle { RotationAnimation { duration: leftcluster.update_interval} }
            }
        ]
    }

    Text {
        x: 166  //156
        y: 131  //131
        color: leftcluster.textcolor
        text: Math.abs(parent.parent.speed)
        font.pixelSize: 45
        font.family: "Sarabun"
        font.bold: false
        width: leftcluster.width
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        x: 190
        y: 276
        color: "gray"
        text: "mm/s"
        font.pixelSize: 13
        font.family: "Sarabun"
        font.bold: false
    }


    Image {
        id: leftneedle
        x: 152
        y: -16
        fillMode: Image.PreserveAspectFit
        source: "/images/needle-standard-sport.png"
        transform: [
            Rotation {
                origin.x: leftneedle.width/2
                origin.y: leftcluster_image.height/2 + leftcluster.y_offset
                angle: leftcluster.left_angle
                Behavior on angle { RotationAnimation { duration: leftcluster.update_interval} }
            }
        ]
    }

    Image {
        id: lefthightlight
        x: 120
        y: -16
        fillMode: Image.PreserveAspectFit
        source: "/images/highlight-standard-sport.png"
        transform: [
            Rotation {
                origin.x: lefthightlight.width/2
                origin.y: leftcluster_image.height/2 + leftcluster.y_offset
                angle: leftcluster.left_angle
                Behavior on angle { RotationAnimation { duration: leftcluster.update_interval} }
            }
        ]
    }

    Image {
        id: leftcluster_image
        x: 0
        y: 0
        fillMode: Image.PreserveAspectFit
        source: "/images/left.png"
    }

}
