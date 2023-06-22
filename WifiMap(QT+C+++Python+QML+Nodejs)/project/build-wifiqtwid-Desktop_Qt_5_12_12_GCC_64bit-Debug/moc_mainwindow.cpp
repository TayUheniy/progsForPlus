/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wifiqtwid/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HandlerSignals_t {
    QByteArrayData data[23];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HandlerSignals_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HandlerSignals_t qt_meta_stringdata_HandlerSignals = {
    {
QT_MOC_LITERAL(0, 0, 14), // "HandlerSignals"
QT_MOC_LITERAL(1, 15, 7), // "setText"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "ssid"
QT_MOC_LITERAL(4, 29, 5), // "bssid"
QT_MOC_LITERAL(5, 35, 5), // "latit"
QT_MOC_LITERAL(6, 41, 6), // "longit"
QT_MOC_LITERAL(7, 48, 7), // "bssidby"
QT_MOC_LITERAL(8, 56, 8), // "countdig"
QT_MOC_LITERAL(9, 65, 10), // "datesearch"
QT_MOC_LITERAL(10, 76, 13), // "setTextClient"
QT_MOC_LITERAL(11, 90, 6), // "setDot"
QT_MOC_LITERAL(12, 97, 12), // "setDotClient"
QT_MOC_LITERAL(13, 110, 7), // "cppSlot"
QT_MOC_LITERAL(14, 118, 8), // "latitude"
QT_MOC_LITERAL(15, 127, 9), // "longitude"
QT_MOC_LITERAL(16, 137, 6), // "bdSlot"
QT_MOC_LITERAL(17, 144, 7), // "bdClear"
QT_MOC_LITERAL(18, 152, 10), // "bdClearnot"
QT_MOC_LITERAL(19, 163, 5), // "bdDot"
QT_MOC_LITERAL(20, 169, 5), // "bdAll"
QT_MOC_LITERAL(21, 175, 4), // "bdTD"
QT_MOC_LITERAL(22, 180, 4) // "bdCL"

    },
    "HandlerSignals\0setText\0\0ssid\0bssid\0"
    "latit\0longit\0bssidby\0countdig\0datesearch\0"
    "setTextClient\0setDot\0setDotClient\0"
    "cppSlot\0latitude\0longitude\0bdSlot\0"
    "bdClear\0bdClearnot\0bdDot\0bdAll\0bdTD\0"
    "bdCL"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HandlerSignals[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   74,    2, 0x06 /* Public */,
      10,    7,   89,    2, 0x06 /* Public */,
      11,    7,  104,    2, 0x06 /* Public */,
      12,    7,  119,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  134,    2, 0x0a /* Public */,
      16,    0,  139,    2, 0x0a /* Public */,
      17,    0,  140,    2, 0x0a /* Public */,
      18,    0,  141,    2, 0x0a /* Public */,
      19,    0,  142,    2, 0x0a /* Public */,
      20,    0,  143,    2, 0x0a /* Public */,
      21,    0,  144,    2, 0x0a /* Public */,
      22,    0,  145,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime,    3,    4,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HandlerSignals::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HandlerSignals *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QDateTime(*)>(_a[7]))); break;
        case 1: _t->setTextClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QDateTime(*)>(_a[7]))); break;
        case 2: _t->setDot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QDateTime(*)>(_a[7]))); break;
        case 3: _t->setDotClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QDateTime(*)>(_a[7]))); break;
        case 4: _t->cppSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->bdSlot(); break;
        case 6: _t->bdClear(); break;
        case 7: _t->bdClearnot(); break;
        case 8: _t->bdDot(); break;
        case 9: _t->bdAll(); break;
        case 10: _t->bdTD(); break;
        case 11: _t->bdCL(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HandlerSignals::*)(QString , QString , double , double , QString , int , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandlerSignals::setText)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HandlerSignals::*)(QString , QString , double , double , QString , int , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandlerSignals::setTextClient)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HandlerSignals::*)(QString , QString , double , double , QString , int , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandlerSignals::setDot)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HandlerSignals::*)(QString , QString , double , double , QString , int , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandlerSignals::setDotClient)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HandlerSignals::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HandlerSignals.data,
    qt_meta_data_HandlerSignals,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HandlerSignals::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandlerSignals::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HandlerSignals.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HandlerSignals::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void HandlerSignals::setText(QString _t1, QString _t2, double _t3, double _t4, QString _t5, int _t6, QDateTime _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HandlerSignals::setTextClient(QString _t1, QString _t2, double _t3, double _t4, QString _t5, int _t6, QDateTime _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HandlerSignals::setDot(QString _t1, QString _t2, double _t3, double _t4, QString _t5, int _t6, QDateTime _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HandlerSignals::setDotClient(QString _t1, QString _t2, double _t3, double _t4, QString _t5, int _t6, QDateTime _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
