import QtQuick 2.12
import QtQuick.Controls 2.12
import QtWebEngine 1.8
import QtQuick.Layouts 1.3

import User.YoutubeAPI 1.0
import QtApplicationManager.Application 2.0

ApplicationManagerWindow {
    property int init_interval : 200

    Rectangle {
        width: 886
        height: 540
        opacity: 0.5
        Behavior on opacity { NumberAnimation { duration: init_interval} }
        
        property var youTubeSearch: null

        color: "black"

        YoutubeAPI {
            id: youtubeapi
        }
        
        YoutubeSearch {
            id: youtubesearch
            x:0
            y:0
            width: parent.width
            height: 100
            youTubeSearch: youtubeapi
            webEngineView: youtubeview.webEngineView
            anchors.top: parent.top
        }

        YoutubeView {
            id: youtubeview
            x:0
            y:100
            width: parent.width
            height: 440
            youTubeSearch: youtubeapi
        }

        Component.onCompleted: {
            opacity = 1
        }
    }
}