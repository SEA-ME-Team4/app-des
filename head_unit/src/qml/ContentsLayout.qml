import QtQuick 2.12
import QtQuick.Controls 2.12
import QtWebEngine 1.8
import YouTubeSearch 1.0
import QtQuick.Layouts 1.3

GridLayout {
    width: 886
    height: 553
    columns: 1

    property var youTubeSearch: null

    YouTubeSearch {
        id: youTubeSearchInternal
    }

    SearchLayout {
        id: searchLayout
        width: parent.width
        height: parent.height * 0.25
        youTubeSearch: youTubeSearchInternal
        webEngineView: youtubeLayout.webEngineView
    }

    YoutubeLayout {
        id: youtubeLayout
        width: parent.width
        height: parent.height * 0.75
        youTubeSearch: youTubeSearchInternal
    }
}
