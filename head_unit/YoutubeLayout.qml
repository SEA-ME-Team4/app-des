import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtWebEngine 1.8

GridLayout {
    width: 886
    height: 503

    property var searchResults
    property alias webEngineView: webEngineView

    Connections {
        target: youTubeSearch
        function onSearchResultsReady(results) {
            searchResults = results;
        }
    }

    ListView {
        id: listView
        Layout.fillWidth: true
        Layout.fillHeight: true
        model: searchResults
        visible: !webEngineView.visible

        delegate: Rectangle {
            width: listView.width
            height: 100
            color: "white"

            Image {
                source: modelData.snippet.thumbnails.default.url
                width: 100
                height: 100
            }

            Text {
                text: modelData.snippet.title
                color: "black"
                x: 110
                width: listView.width - 110
                wrapMode: Text.Wrap
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    var videoId = modelData.id.videoId;
                    webEngineView.url = "https://www.youtube.com/embed/" + videoId;
                    webEngineView.visible = true;
                }
            }
        }
    }

    WebEngineView {
        id: webEngineView
        Layout.fillWidth: true
        Layout.fillHeight: true
        visible: false
    }
}
