/****************************************************************************
** Meta object code from reading C++ file 'project.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "project.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_project_t {
    QByteArrayData data[8];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_project_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_project_t qt_meta_stringdata_project = {
    {
QT_MOC_LITERAL(0, 0, 7), // "project"
QT_MOC_LITERAL(1, 8, 9), // "connected"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "disconnect"
QT_MOC_LITERAL(4, 30, 12), // "bytesWritten"
QT_MOC_LITERAL(5, 43, 5), // "bytes"
QT_MOC_LITERAL(6, 49, 9), // "readyRead"
QT_MOC_LITERAL(7, 59, 21) // "on_pushButton_clicked"

    },
    "project\0connected\0\0disconnect\0"
    "bytesWritten\0bytes\0readyRead\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_project[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,
       6,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void project::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        project *_t = static_cast<project *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnect(); break;
        case 2: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->readyRead(); break;
        case 4: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (project::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&project::connected)) {
                *result = 0;
            }
        }
        {
            typedef void (project::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&project::disconnect)) {
                *result = 1;
            }
        }
        {
            typedef void (project::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&project::bytesWritten)) {
                *result = 2;
            }
        }
        {
            typedef void (project::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&project::readyRead)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject project::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_project.data,
      qt_meta_data_project,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *project::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *project::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_project.stringdata0))
        return static_cast<void*>(const_cast< project*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int project::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void project::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void project::disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void project::bytesWritten(qint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void project::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
