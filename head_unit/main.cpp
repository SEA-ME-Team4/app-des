#include "youtubesearch.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QtWebEngine::initialize();

    QGuiApplication app(argc, argv);

    qmlRegisterType<YouTubeSearch>("com.example", 1, 0, "YouTubeSearch");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
