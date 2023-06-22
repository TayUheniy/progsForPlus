import QtQuick 2.0
import QtPositioning 5.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtQml 2.12
import QtQuick.Controls.Styles 1.4

ApplicationWindow {

    visible: true
    width: 1200
    height: 700


    Rectangle {
        width: 1200
        height: 800
       visible:true

        Plugin {
            id: osmMapPlugin
            name: "osm"
            PluginParameter {
                name: "osm.mapping.custom.host"
                value: "http://localhost/hot/"
            }
            PluginParameter {
                name: "osm.mapping.providersrepository.disabled"
                value: true
            }
        }


        ListModel{
            id: mapModel
        }
        ListModel{
            id: mapModel2
        }
        ListModel{
            id: mapModel3
        }
        ListModel{
            id: mapModel4
        }


        Map{
            id: map
        anchors.fill: parent
        plugin: osmMapPlugin
        activeMapType: supportedMapTypes[supportedMapTypes.length-1]
        center: QtPositioning.coordinate(55.75,37.63)
        zoomLevel: 12
        MapItemView {
            model: mapModel
            delegate: MapQuickItem {
                id:mapet
                coordinate: {
                    QtPositioning.coordinate(lat,lon)
                }
                anchorPoint.x: image.width * 0.5
                anchorPoint.y: image.height*0.7
                sourceItem:
                   Image {
                           id:image
                         width:30;height:30
                         fillMode: Image.PreserveAspectFit
                         source: "/home/ubuntu/marks/one.png"
                         MouseArea {
                              id: mousear
                              anchors.fill: image
                              hoverEnabled: True
                              propagateComposedEvents: true
                              onClicked:   {txt.text = "ssid: "+s+"\nbssid: "+b+"\nlatitude: "+lat+"\nlongitude: "+lon+"\nconnected to: "+bs+"\nmeasurements: "+c+"\ndatesearch: "+d}
                            }
                       }
                 }
            }
        MapItemView {
            model: mapModel2
            delegate: MapQuickItem {
                id:mapet3
                coordinate: {
                    QtPositioning.coordinate(lat,lon)
                }
                anchorPoint.x: image3.width * 0.5
                anchorPoint.y: image3.height*0.7
                sourceItem:
                     Image {
                            id:image3
                         width:30;height:30
                         fillMode: Image.PreserveAspectFit
                         source: "/home/ubuntu/marks/three.png"
                         MouseArea {
                              id: mousear3
                              anchors.fill: image3
                              hoverEnabled: True
                              propagateComposedEvents: true
                              onClicked:   {txt.text = "ssid: "+s+"\nbssid: "+b+"\nlatitude: "+lat+"\nlongitude: "+lon+"\nconnected to: "+bs+"\nmeasurements: "+c+"\ndatesearch: "+d}
                            }
                       }
                 }
            }

        MapItemView {
            model: mapModel3
            delegate: MapQuickItem {
                id:mapet5
                coordinate: {
                    QtPositioning.coordinate(lat,lon)
                }
                anchorPoint.x: image5.width * 1
                anchorPoint.y: image5.height*1
                sourceItem:

                    Rectangle{
                         id: image5
                         width:2;height:2
                         color: "red";

                         MouseArea {
                              id: mousear5
                              anchors.fill: image5
                              hoverEnabled: True
                              propagateComposedEvents: true
                              onClicked:   {txt.text = "ssid: "+s+"\nbssid: "+b+"\nlatitude: "+lat+"\nlongitude: "+lon+"\nconnected to: "+bs+"\nmeasurements: "+c+"\ndatesearch: "+d}
                            }
                       }
                 }
            }
        MapItemView {
            model: mapModel4
            delegate: MapQuickItem {
                id:mapet4
                coordinate: {
                    QtPositioning.coordinate(lat,lon)
                }
                anchorPoint.x: image4.width * 1
                anchorPoint.y: image4.height*1
                sourceItem:

                    Rectangle{
                         width:2;height:2
                         color: "blue";
                         id: image4

                         MouseArea {
                              id: mousear4
                              anchors.fill: image4
                              hoverEnabled: True
                              propagateComposedEvents: true
                              onClicked:   {txt.text = "ssid: "+s+"\nbssid: "+b+"\nlatitude: "+lat+"\nlongitude: "+lon+"\nconnected to: "+bs+"\nmeasurements: "+c+"\ndatesearch: "+d}
                            }
                       }
                 }
            }

        MapQuickItem {
                id:mapet2
                coordinate: {
                    QtPositioning.coordinate(55.75,37.63)
                }
                anchorPoint.x: image2.width * 0.5
                anchorPoint.y: image2.height*0.9
                sourceItem:
                     Image {
                         id: image2
                         width:40;height:40
                         fillMode: Image.PreserveAspectFit
                         source: "/home/ubuntu/marks/two.png"
                       }
                 }

        MouseArea {
             id: mousear2
             anchors.fill: map
             hoverEnabled: True
             propagateComposedEvents: true
             onDoubleClicked:  {mapet2.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y));
                 txt2.text = "Positions\nlatitude: "+mapet2.coordinate.latitude+"\nlongitude: "+mapet2.coordinate.longitude;}
           }
        }


        Rectangle{
            width: 400
            height:130
            id:hov
            color: "white"
            visible: true;
            Text {
                id:txt
                text :"ssid:\nbssid:\nlatitude:\nlongitude:\nconnected to:\nmeasurements:\ndatesearch:\n"
                visible: true;
            }
        }
        Rectangle{
            width: 150
            x:1050
            y:0
            height:150
            id:hov2
            color: "white"
            visible: true;
            Text {
                id:txt2
                text :"Positions\nlatitude: "+mapet2.coordinate.latitude+"\nlongitude: "+mapet2.coordinate.longitude;
                visible: true;
            }
        }
        Button {
         background: Rectangle{color:"greenyellow"}
         id: button
         x:410
         y:0
         width: 180
         height: 30
         text: "Запуск поиска"
         onClicked: {HandlerSlot.cppSlot(mapet2.coordinate.latitude,mapet2.coordinate.longitude)}
        }
        Button {
         id: button2
         x:600
         y:0
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Точная выгрузка"
         onClicked: {HandlerSlot.bdSlot()}
         }
        Button {
         id: button3
         x:410
         y:40
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Очистить карту"
         onClicked: {mapModel.clear();mapModel2.clear();mapModel3.clear();mapModel4.clear()}
         }
        Button {
         id: button4
         x:600
         y:40
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Очистить всю БД"
         onClicked: {HandlerSlot.bdClear()}
         }
        Button {
         id: button5
         x:410
         y:80
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Очистить данные"
         onClicked: {HandlerSlot.bdClearnot()}
         }
        Button {
         id: button6
         x:600
         y:80
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Выгрузить точками"
         onClicked: {HandlerSlot.bdDot()}
         }
        Button {
         id: button7
         x:410
         y:120
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Выгрузить все"
         onClicked: {HandlerSlot.bdAll()}
         }
        Button {
         id: button8
         x:600
         y:120
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Выгрузить ТД"
         onClicked: {HandlerSlot.bdTD()}
         }
        Button {
         id: button9
         x:790
         y:0
         background: Rectangle{color:"greenyellow"}
         width: 180
         height: 30
         text: "Выгрузить клиентов"
         onClicked: {HandlerSlot.bdCL()}
         }
        Connections {
            target:HandlerSlot
            onSetText: {
                mapModel.append({s:ssid,b:bssid,lat:latit,lon:longit,bs:bssidby,c:countdig,d:datesearch})}
            onSetTextClient: {
                mapModel2.append({s:ssid,b:bssid,lat:latit,lon:longit,bs:bssidby,c:countdig,d:datesearch})
                }
            onSetDot:{ mapModel3.append({s:ssid,b:bssid,lat:latit,lon:longit,bs:bssidby,c:countdig,d:datesearch})}
            onSetDotClient:{ mapModel4.append({s:ssid,b:bssid,lat:latit,lon:longit,bs:bssidby,c:countdig,d:datesearch})}
            }
      }
}







