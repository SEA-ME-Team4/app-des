import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtWebEngine 1.8

GridLayout {
    columns: 5
    width: 886
    height: 50

    Button {
        id: home
        implicitWidth: 50
        implicitHeight: 50
        background: Rectangle {
            color: "transparent"
        }
        contentItem: Image {
            source: "/images/home_button.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }

        onClicked: {
            contentsLayout.visible = false
            menuLayout.visible = true
            ambientsLayout.visible = false
        }
    }

    Button {
        id: youtube
        implicitWidth: 50
        implicitHeight: 50
        background: Rectangle{
            color: "transparent"
        }
        contentItem: Image {
            source: "/images/youtube_button.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }

        onClicked: {
            contentsLayout.visible = true
            menuLayout.visible = false
            ambientsLayout.visible = false
        }
    }

    Button {
        id: ambients
        implicitWidth: 50
        implicitHeight: 50
        background: Rectangle {
            color: "transparent"
        }
        contentItem: Image {
            source: "/images/colors_picker.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }

        onClicked: {
            contentsLayout.visible = false
            menuLayout.visible = true
            ambientsLayout.visible = true
        }
    }

    Rectangle {
        id: empty
        width: 600
        height: 50
        color: "#000000"
    }

    Text {
        id: clockText
        width: 150
        height: 50
        color: "#ffffff"
        Layout.alignment: Qt.AlignRight
        font.bold: true
        font.pointSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        Component.onCompleted: {
            updateClock();
            clockTimer.start();
        }

        function updateClock() {
            var now = new Date();
            var hours = now.getHours();
            var minutes = now.getMinutes();

            if (hours < 10) { hours = "0" + hours; }
            if (minutes < 10) { minutes = "0" + minutes; }

            clockText.text = hours + ":" + minutes + " ";
        }
    }

    Timer {
        id: clockTimer
        interval: 1000
        running: true
        repeat: true
        onTriggered: clockText.updateClock()
    }

}
