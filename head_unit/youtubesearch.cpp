#include "youtubesearch.h"

YouTubeSearch::YouTubeSearch() {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &YouTubeSearch::handleNetworkData);
}

void YouTubeSearch::searchVideos(const QString& query) {
    videoIdList.clear();
    manager->get(QNetworkRequest(QUrl("https://www.googleapis.com/youtube/v3/search?part=snippet&q=" + query + "&maxResults=5&key=AIzaSyDX1VZe07SA4mOTNCvhZs3hr1xywwKHKwI")));
}

void YouTubeSearch::handleNetworkData(QNetworkReply *reply) {
    disconnect(manager, &QNetworkAccessManager::finished, this, &YouTubeSearch::handleNetworkData);
    connect(manager, &QNetworkAccessManager::finished, this, &YouTubeSearch::handleVideoDetails);

    if(reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        QJsonArray jsonArray = jsonObj["items"].toArray();

        videoCount = 0;
        filteredResults = QJsonArray();

        for (int i = 0; i < jsonArray.count(); ++i) {
           QJsonObject video = jsonArray[i].toObject();
           QString videoId = video["id"].toObject()["videoId"].toString();
           videoIdList.append(videoId);
           manager->get(QNetworkRequest(QUrl("https://www.googleapis.com/youtube/v3/videos?part=status&id=" + videoId + "&key=AIzaSyDX1VZe07SA4mOTNCvhZs3hr1xywwKHKwI")));
        }

//        // Send data to QML
//        emit searchResultsReady(jsonArray);
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}

void YouTubeSearch::handleVideoDetails(QNetworkReply *reply) {
    disconnect(manager, &QNetworkAccessManager::finished, this, &YouTubeSearch::handleVideoDetails);
    connect(manager, &QNetworkAccessManager::finished, this, &YouTubeSearch::handleNetworkData);

    if(reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        QJsonArray jsonArray = jsonObj["items"].toArray();

        if (!jsonArray.isEmpty()) {
            QJsonObject video = jsonArray[0].toObject();
            bool embeddable = video["status"].toObject()["embeddable"].toBool();
            if (embeddable) {
                filteredResults.append(video);
            }
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }

    videoCount++;

    if (videoCount == videoIdList.size()) {
        if (filteredResults.size() >= 5) {
            while(filteredResults.size() > 5) {
                filteredResults.removeAt(filteredResults.size() - 1);
            }
            emit searchResultsReady(filteredResults);
        }
    }

    reply->deleteLater();
}
