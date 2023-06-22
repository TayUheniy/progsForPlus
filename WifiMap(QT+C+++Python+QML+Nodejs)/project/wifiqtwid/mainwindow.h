#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsObject>
#include <QtQuickWidgets/QQuickWidget>
#include <QQmlContext>
#include <QObject>
#include <QVariant>
#include <QtSql/QSqlDatabase>
#include <QtSql>
#include <QMap>
#include <QtLocation/QtLocation>

/*class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


 private:
    QQuickWidget *ui;
    QQuickItem* Root;
};*/

class HandlerSignals : public QObject{
    Q_OBJECT
public: HandlerSignals(QObject *parent =0);
signals:
        void setText(QString ssid, QString bssid,double latit, double longit,QString bssidby, int countdig, QDateTime datesearch);
        void setTextClient(QString ssid, QString bssid,double latit, double longit,QString bssidby, int countdig, QDateTime datesearch);
        void setDot(QString ssid, QString bssid,double latit, double longit,QString bssidby, int countdig, QDateTime datesearch);
        void setDotClient(QString ssid, QString bssid,double latit, double longit,QString bssidby, int countdig, QDateTime datesearch);
public slots:
    void cppSlot(QString latitude, QString longitude);
    void bdSlot();
    void bdClear();
    void bdClearnot();
    void bdDot();
    void bdAll();
    void bdTD();
    void bdCL();
};

#endif // MAINWINDOW_H
