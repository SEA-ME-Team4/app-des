#ifndef YOUTUBEAPI_H
#define YOUTUBEAPI_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>
#include <QtWebEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QNetworkReply>
#include <QSslConfiguration>
#include <QtQml>
#include <QQmlExtensionPlugin>

class YoutubeAPI : public QObject {
    Q_OBJECT
public:
    YoutubeAPI();

    //Q_INVOKABLE: Using macro, can call member function of C++ in QML
    Q_INVOKABLE void searchVideos(const QString& query);

signals:
    void searchResultsReady(const QJsonArray& results);

private slots:
    void handleNetworkData(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
};

#endif
