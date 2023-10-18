#include "youtubesearch.h"
#include "vehiclestatus.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard")); 
 
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QtWebEngine::initialize();

    QGuiApplication app(argc, argv);

    qmlRegisterType<YouTubeSearch>("YouTubeSearch", 1, 0, "YouTubeSearch");

    qmlRegisterType<VehicleStatus>("VehicleStatus", 1, 0, "VehicleStatus");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
