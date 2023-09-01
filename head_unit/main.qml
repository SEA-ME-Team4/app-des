import QtQuick 2.12
import QtQuick.Controls 2.5
import QtWebEngine 1.8
import com.example 1.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    property var searchResults: []

    YouTubeSearch {
        id: youTubeSearch
    }

    Connections {
        target: youTubeSearch
        function onSearchResultsReady(results) {
            searchResults = results
        }
    }

    ColumnLayout {
        anchors.fill: parent

        StackLayout {
            id: stackLayout
            Layout.fillWidth: true
            Layout.fillHeight: true

            ListView {
                id: listView
                width: parent.width
                height: parent.height

                model: searchResults

                delegate: Item {
                    width: listView.width
                    height: 100

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            webEngineView.url = "https://www.youtube.com/embed/" + modelData.id.videoId
                            stackLayout.currentIndex = 1
                        }

                        RowLayout {
                            width: parent.width
                            height: 100

                            Image {
                                source: modelData.snippet.thumbnails.default.url
                                width: 100
                                height: 100
                            }

                            Text {
                                text: modelData.snippet.title
                                wrapMode: Text.Wrap
                                Layout.fillWidth: true
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                }
            }

            WebEngineView {
                id: webEngineView
                width: parent.width
                height: parent.height - 50
            }
        }

        TextField {
            id: textField
            width: parent.width - 100
            height: 50
            placeholderText: "Search YouTube"
            Layout.fillWidth: true
        }

        Button {
            text: "Search"
            width: 100
            height: 50

            onClicked: {
                youTubeSearch.searchVideos(textField.text)
                stackLayout.currentIndex = 0
            }
        }
    }
}
