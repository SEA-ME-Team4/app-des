#include "youtubesearch.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QtWebEngine::initialize();

    qmlRegisterType<YouTubeSearch>("com.example", 1, 0, "YouTubeSearch");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/MainLayout.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
