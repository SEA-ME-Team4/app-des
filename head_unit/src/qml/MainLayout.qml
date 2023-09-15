import QtQuick 2.12
import QtQuick.Controls 2.12
import QtWebEngine 1.8
import YouTubeSearch 1.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {

    visible: true
    width: 1024
    height: 600
    color: "#000000"

    property var searchResults: []

    YouTubeSearch {
        id: youTubeSearch
    }

    ButtonGroup { id: buttonGroup }

    GearLayout {
        id: gearLayout
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        buttonGroup: buttonGroup
    }

    ToolbarLayout {
        id: toolbarLayout
        anchors.left: gearLayout.right
        anchors.right: parent.right
        anchors.top: parent.top
    }

    MenuLayout {
        id: menuLayout
        anchors.left: gearLayout.right
        anchors.right: parent.right
        anchors.top: toolbarLayout.bottom
        anchors.bottom: parent.bottom
        visible: true
    }

    ContentsLayout {
        id: contentsLayout
        anchors.left: gearLayout.right
        anchors.right: parent.right
        anchors.top: toolbarLayout.bottom
        anchors.bottom: parent.bottom
        youTubeSearch: youTubeSearch
        visible: false
    }
}
