import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

GridLayout {
    width: 138
    height: 600
    columns: 1
    rows: 6

    property int text_size: 30
    property int button_size: 70
    property real min_opacity: 0.7
    property real access_opacity: 0.75
    property real default_opacity: 1
    property int  opacity_interval: 1000
    property ButtonGroup buttonGroup

    Button {
        id: gear_P
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        checked: true
        ButtonGroup.group: buttonGroup
        Layout.topMargin: 20
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        //enabled: opacity >= access_opacity

        contentItem: Text {
            text: qsTr("P")
            horizontalAlignment: Text.AlignHCenter
            color: gear_P.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_P.opacity
        }

        onClicked: {
            menuLayout.isGearSSelected = false;
//            gear_R.opacity = min_opacity
//            gear_N.opacity = min_opacity
//            gear_D.opacity = min_opacity
//            gear_S.opacity = min_opacity
            vehiclestatus.sendGear(0)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

//    Timer {
//        id: opacityTimer
//        interval: 3000
//        running: false
//        repeat: false
//        onTriggered: {
//            gear_P.opacity = gear_P.checked ? default_opacity : min_opacity;
//            gear_R.opacity = gear_R.checked ? default_opacity : min_opacity;
//            gear_N.opacity = gear_N.checked ? default_opacity : min_opacity;
//            gear_D.opacity = gear_D.checked ? default_opacity : min_opacity;
//            gear_S.opacity = gear_S.checked ? default_opacity : min_opacity;
//        }
//    }

//    function resetOpacity() {
//        gear_P.opacity = default_opacity;
//        gear_R.opacity = default_opacity;
//        gear_N.opacity = default_opacity;
//        gear_D.opacity = default_opacity;
//        gear_S.opacity = default_opacity;
//        opacityTimer.start();
//    }


    Button {
        id: gear_R
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        //enabled: opacity >= access_opacity

        contentItem: Text {
            text: qsTr("R")
            horizontalAlignment: Text.AlignHCenter
            color: gear_R.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_R.opacity
        }

        onClicked: {
            contentsLayout.visible = false;
            menuLayout.visible = true;
            menuLayout.isGearSSelected = false;
//            gear_P.opacity = min_opacity
//            gear_N.opacity = min_opacity
//            gear_D.opacity = min_opacity
//            gear_S.opacity = min_opacity
            vehiclestatus.sendGear(1)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

    Button {
        id: gear_N
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        //enabled: opacity >= access_opacity

        contentItem: Text {
            text: qsTr("N")
            horizontalAlignment: Text.AlignHCenter
            color: gear_N.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_N.opacity
        }
        onClicked: {
            menuLayout.isGearSSelected = false;
//            gear_P.opacity = min_opacity
//            gear_R.opacity = min_opacity
//            gear_D.opacity = min_opacity
//            gear_S.opacity = min_opacity
            vehiclestatus.sendGear(2)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

    Button {
        id: gear_D
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        //enabled: opacity >= access_opacity

        contentItem: Text {
            text: qsTr("D")
            horizontalAlignment: Text.AlignHCenter
            color: gear_D.checked ? "white" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_D.opacity
        }
        onClicked: {
            contentsLayout.visible = false;
            menuLayout.visible = true;
            menuLayout.isGearSSelected = false;
//            gear_P.opacity = min_opacity
//            gear_R.opacity = min_opacity
//            gear_N.opacity = min_opacity
//            gear_S.opacity = min_opacity
            vehiclestatus.sendGear(3)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

    Button {
        id: gear_S
        implicitWidth: button_size
        implicitHeight: button_size
        Layout.alignment: Qt.AlignHCenter
        visible: true
        checkable: true
        ButtonGroup.group: buttonGroup
        opacity: default_opacity
        background: Rectangle {
            color: "transparent"
        }

        //enabled: opacity >= access_opacity

        contentItem: Text {
            text: qsTr("S")
            horizontalAlignment: Text.AlignHCenter
            color: gear_S.checked ? "red" : "#403f3f"
            font.pointSize: text_size
            font.bold: true
            anchors.centerIn: parent
            opacity: gear_S.opacity
        }

        onClicked: {
            contentsLayout.visible = false;
            menuLayout.visible = true;
            menuLayout.isGearSSelected = true;
//            gear_P.opacity = min_opacity
//            gear_R.opacity = min_opacity
//            gear_N.opacity = min_opacity
//            gear_D.opacity = min_opacity
            vehiclestatus.sendGear(4)
        }

        Behavior on opacity {
            NumberAnimation { duration: opacity_interval }
        }
    }

//    Button {
//        implicitWidth: button_size
//        implicitHeight: button_size
//        Layout.alignment: Qt.AlignHCenter
//        visible: true

//        background: Rectangle {
//            color: "transparent"
//        }
//        contentItem: Image {
//            source: "/images/Change_gear.png"
//            anchors.fill: parent
//            fillMode: Image.PreserveAspectFit
//        }

//        onClicked: {
//            resetOpacity();
//        }
//    }
}
