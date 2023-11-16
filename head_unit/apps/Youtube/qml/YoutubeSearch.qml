import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.VirtualKeyboard 2.0


GridLayout {
    columns: 3
    width: 886
    height: 50

    property var youTubeSearch
    property var webEngineView

    TextField {
        id: textField
        width: 500
        height: 50
        placeholderText: "Search YouTube"
        placeholderTextColor: "#000000"
        Layout.fillWidth: true
        focus: true
        anchors.top: parent.top
    }

    Button {
        implicitWidth: 30
        implicitHeight: 30
        anchors.verticalCenter: textField.verticalCenter

        contentItem: Image {
            source: "images/search_glass.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }

        background: Rectangle {
               color: "white"
               radius: width * 0.5
           }

        onClicked: {
            webEngineView.url = "about:blank";
            webEngineView.visible = false;
            youTubeSearch.searchVideos(textField.text)
        }
    }

    Button {
        implicitWidth: 30
        implicitHeight: 30
        anchors.verticalCenter: textField.verticalCenter

        contentItem: Image {
            source: "images/X.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }

        background: Rectangle {
               color: "white"
               radius: width * 0.5
           }

        onClicked: {
            webEngineView.url = "about:blank";
            webEngineView.visible = false;
        }
    }
}
