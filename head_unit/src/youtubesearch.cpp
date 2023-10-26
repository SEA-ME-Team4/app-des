#include "youtubesearch.h"

YouTubeSearch::YouTubeSearch() {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &YouTubeSearch::handleNetworkData);
}

void YouTubeSearch::searchVideos(const QString& query) {
    QNetworkRequest request(QUrl("https://www.googleapis.com/youtube/v3/search?part=snippet&q=" + query + 
    "&maxResults=5&key=AIzaSyDWJEkT-hgHx05l4ZdvaurDrwSoqiCPS7A"));

    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    QFile certFile("/etc/ssl/certs/youtube.pem");
    
    if(certFile.open(QIODevice::ReadOnly)) {
        QSslCertificate cert(&certFile, QSsl::Pem);
        conf.setCaCertificates(QList<QSslCertificate>() << cert);
    }
    
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
