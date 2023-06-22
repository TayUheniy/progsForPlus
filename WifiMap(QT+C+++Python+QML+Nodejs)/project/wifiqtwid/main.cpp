#include "mainwindow.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("wifidb");
    db.setUserName("postgres");
    db.setPassword("postgres");
    db.setPort(5432);
    db.open();
    QQmlApplicationEngine engine;
    engine.load(QUrl("/home/ubuntu/project/wifiqtwid/mapping.qml"));
    HandlerSignals *handlerSignals = new HandlerSignals();
    //handlerSignals->bdSlot();
    //QObject* root = engine.rootObjects()[0];
    engine.rootContext()->setContextProperty("HandlerSlot",handlerSignals);

    //HandlerSignals *handlerSignals = new HandlerSignals(root);
    //QObject::connect(root, SIGNAL(qmlSignal()),handlerSignals,SLOT(cppSlot()));
    //QObject::connect(root, SIGNAL(bdSignal()),handlerSignals,SLOT(bdSlot()));
    //MainWindow w;
    //w.show();
    return a.exec();
}
