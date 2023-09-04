import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtWebEngine 1.8

GridLayout {
    columns: 3
    width: 886
    height: 50

    signal searchDefaultRequested()

    Button {
        text: "Home"
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
        }
    }

    Button {
        text: "Youtube"
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
            searchDefaultRequested()
        }
    }

    TextField {
        id: textField
        width: 500
        height: 50
        placeholderText: "Search YouTube"
        placeholderTextColor: "#000000"
        Layout.fillWidth: true
    }
}
