#include "youtubesearch.h"
#include "gearservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QtWebEngine::initialize();

    qmlRegisterType<YouTubeSearch>("YouTubeSearch", 1, 0, "YouTubeSearch");

    qmlRegisterType<GearService>("GearService", 1, 0, "GearService");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/MainLayout.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
