import QtQuick 2.12
import QtQuick.Controls 2.15
import QtWebEngine 1.8
import com.example 1.0
import QtQuick.Layouts 1.3

GridLayout {
    //id: contentsLayout
    width: 886
    height: 553
    columns: 1

    property var youTubeSearch
    property var searchResults

    YoutubeLayout {
        id: youtubeLayout
        width: contentsLayout.width
        height: contentsLayout.height * 0.75
        searchResults: contentsLayout.searchResults
    }

    SearchLayout {
        id: searchLayout
        width: contentsLayout.width
        height: contentsLayout.height * 0.25
        youTubeSearch: contentsLayout.youTubeSearch
        webEngineView: youtubeLayout.webEngineView
    }
}
