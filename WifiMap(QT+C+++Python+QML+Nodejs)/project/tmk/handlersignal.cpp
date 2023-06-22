#include "handlersignal.h"

HandlerSignals::HandlerSignals(QObject *parent) : QObject(parent)
{

}
void HandlerSignals::bdClear() {
    QString systcomand = "python3 /home/ubuntu/wifidblite/bd.py 2";
    system(qPrintable(systcomand));
}
void HandlerSignals::bdClearnot() {
    QString systcomand = "python3 /home/ubuntu/wifidblite/bd.py 1";
    system(qPrintable(systcomand));
}

void HandlerSignals::cppSlot(QString latitude, QString longitude) {
    QString systcomand = "python3 /home/ubuntu/prog.py "+latitude+' '+longitude;
    system(qPrintable(systcomand));
}
void HandlerSignals::bdSlot(){
    QSqlQuery query;
    query.exec("SELECT ssid, bssid, latitude, longitude,bssidby,countdig,datesearch FROM wifiuser WHERE accuracy = '1'");

    while (query.next()) {

        QString ssid = query.value(0).toString();
        QString bssid = query.value(1).toString();
        double latit = query.value(2).toDouble();
        double longit = query.value(3).toDouble();
        QString bssidby = query.value(4).toString();
        int countdig = query.value(5).toInt();
        QDateTime datesearch = query.value(6).toDateTime();
        if (bssidby == "2") {
                bssidby = "access point";
                emit setText(ssid,bssid,latit,longit,bssidby,countdig,datesearch);
        } else {
            emit setTextClient(ssid,bssid,latit,longit,bssidby,countdig,datesearch);
        }
    }
}
void HandlerSignals::bdDot() {
    QSqlQuery query;
    query.exec("SELECT ssid, bssid, latitude, longitude,bssidby,countdig,datesearch FROM wifiuser;");

    while (query.next()) {

        QString ssid = query.value(0).toString();
        QString bssid = query.value(1).toString();
        double latit = query.value(2).toDouble();
        double longit = query.value(3).toDouble();
        QString bssidby = query.value(4).toString();
        int countdig = query.value(5).toInt();
        QDateTime datesearch = query.value(6).toDateTime();
        if (bssidby == "2") {
                bssidby = "access point";
                emit setDot(ssid,bssid,latit,longit,bssidby,countdig,datesearch);
        } else {
            if (bssidby == "1")
                bssidby = "search";
            emit setDotClient(ssid,bssid,latit,longit,bssidby,countdig,datesearch);
        }
    }
}
void HandlerSignals::bdAll() {
    QSqlQuery query;
    query.exec("SELECT ssid, bssid, latitude, longitude,bssidby,countdig,datesearch FROM wifiuser;");

    while (query.next()) {

        QString ssid = query.value(0).toString();
        QString bssid = query.value(1).toString();
        double latit = query.value(2).toDouble();
        double longit = query.value(3).toDouble();
        QString bssidby = query.value(4).toString();
        int countdig = query.value(5).toInt();
        QDateTime datesearch = query.value(6).toDateTime();
        if (bssidby == "2") {
                bssidby = "access point";
                emit setText(ssid,bssid,latit,longit,bssidby,countdig,datesearch);
        } else {
            if (bssidby == "1")
                bssidby = "search";
            emit setTextClient(ssid,bssid,latit,longit,bssidby,countdig,datesearch);
        }
    }
}
void HandlerSignals::bdTD() {
    QSqlQuery query;
    query.exec("SELECT ssid, bssid, latitude, longitude,bssidby,countdig,datesearch FROM wifiuser WHERE bssidby = '2';");

    while (query.next()) {

        QString ssid = query.value(0).toString();
        QString bssid = query.value(1).toString();
        double latit = query.value(2).toDouble();
        double longit = query.value(3).toDouble();
        QString bssidby = query.value(4).toString();
        int countdig = query.value(5).toInt();
        QDateTime datesearch = query.value(6).toDateTime();
        if (bssidby == "2") {
                bssidby = "access point";}
                emit setText(ssid,bssid,latit,longit,bssidby,countdig,datesearch);

    }
}
void HandlerSignals::bdCL() {
    QSqlQuery query;
    query.exec("SELECT ssid, bssid, latitude, longitude,bssidby,countdig,datesearch FROM wifiuser WHERE bssidby != '2';");

    while (query.next()) {

        QString ssid = query.value(0).toString();
        QString bssid = query.value(1).toString();
        double latit = query.value(2).toDouble();
        double longit = query.value(3).toDouble();
        QString bssidby = query.value(4).toString();
        int countdig = query.value(5).toInt();
        QDateTime datesearch = query.value(6).toDateTime();
        if (bssidby == "1") {
                bssidby = "search";}
                emit setTextClient(ssid,bssid,latit,longit,bssidby,countdig,datesearch);

    }
}

