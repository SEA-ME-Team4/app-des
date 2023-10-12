#ifndef YOUTUBESEARCH_H
#define YOUTUBESEARCH_H

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

class YouTubeSearch : public QObject {
    Q_OBJECT
public:
    YouTubeSearch();

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
