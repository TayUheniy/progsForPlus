#include <QQmlApplicationEngine>
#include <QGuiApplication>

#include "handlersignal.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("wifidb");
    db.setUserName("postgres");
    db.setPassword("postgres");
    db.setPort(5432);
    db.open();

    HandlerSignals *handlerSignals = new HandlerSignals();
    engine.rootContext()->setContextProperty("HandlerSlot",handlerSignals);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
