#ifndef HANDLERSIGNAL_H
#define HANDLERSIGNAL_H

#include <QObject>
#include <QSqlDatabase>
#include <QObject>
#include <QVariant>
#include <QtSql>
#include <QMap>
#include <QtLocation/QtLocation>

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

#endif // HANDLERSIGNAL_H
