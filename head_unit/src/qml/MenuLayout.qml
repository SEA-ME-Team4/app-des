import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtWebEngine 1.8
import QtGraphicalEffects 1.0

GridLayout {
    width: 886
    height: 553

    property bool isGearSSelected: false
    property bool isAmbient: false  
    property color ambientColor: "#000000"

    Item {
        id: menuImages
        Layout.fillWidth: true
        Layout.fillHeight: true

        Image {
            id: field
            visible: true
            source: "/images/field.png"
            anchors.centerIn: parent
            width: isGearSSelected ? menuImages.width * 0.2 : menuImages.width * 0.8 
            height: width / sourceSize.width * sourceSize.height
        }

        Image {
            id: car_highlights
            source: "/images/car-highlights.png"
            anchors.centerIn: parent
            width: isGearSSelected ? menuImages.width * 0.8 : menuImages.width * 0.8
            height: width / sourceSize.width * sourceSize.height
        }

        ColorOverlay {
            anchors.fill: field
            source: field
            color: ambientsLayout.ambientColor
        }
    }
}
