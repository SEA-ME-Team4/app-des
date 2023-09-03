import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtWebEngine 1.8

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
    }

    Button {
        text: "Search"
        width: 100
        height: 50


        onClicked: {
            webEngineView.visible = false;
            youTubeSearch.searchVideos(textField.text)
        }
    }

    Button {
        text: "Back"
        width: 100
        height: 50

        onClicked: {
            webEngineView.visible = false;
        }
    }
}
