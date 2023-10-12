#include "youtubesearch.h"

YouTubeSearch::YouTubeSearch() {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &YouTubeSearch::handleNetworkData);
}

void YouTubeSearch::searchVideos(const QString& query) {
    QNetworkRequest request(QUrl("https://www.googleapis.com/youtube/v3/search?part=snippet&q=" + query + "&maxResults=5&key=AIzaSyC2CGURgrCoILPCAUa2OGE_fuK3AyYYBa4"));

    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(conf);

    manager->get(request);
}

void YouTubeSearch::handleNetworkData(QNetworkReply *reply) {
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        QJsonArray jsonArray = jsonObj["items"].toArray();


        // Send data to QML
        emit searchResultsReady(jsonArray);
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}
