/****************************************************************************
** Meta object code from reading C++ file 'formmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../formmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormMain_t {
    QByteArrayData data[16];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormMain_t qt_meta_stringdata_FormMain = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FormMain"
QT_MOC_LITERAL(1, 9, 13), // "playbackError"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "message"
QT_MOC_LITERAL(4, 32, 21), // "onSetAlarmTimeRequest"
QT_MOC_LITERAL(5, 54, 17), // "onSettingsRequest"
QT_MOC_LITERAL(6, 72, 18), // "onSetAlarmTimeDone"
QT_MOC_LITERAL(7, 91, 7), // "newTime"
QT_MOC_LITERAL(8, 99, 11), // "onPlayStart"
QT_MOC_LITERAL(9, 111, 6), // "volume"
QT_MOC_LITERAL(10, 118, 10), // "onPlayStop"
QT_MOC_LITERAL(11, 129, 15), // "onVolumeChanged"
QT_MOC_LITERAL(12, 145, 14), // "onSettingsDone"
QT_MOC_LITERAL(13, 160, 7), // "timeout"
QT_MOC_LITERAL(14, 168, 29), // "on_pushButtonSetAlarm_clicked"
QT_MOC_LITERAL(15, 198, 29) // "on_pushButtonSettings_clicked"

    },
    "FormMain\0playbackError\0\0message\0"
    "onSetAlarmTimeRequest\0onSettingsRequest\0"
    "onSetAlarmTimeDone\0newTime\0onPlayStart\0"
    "volume\0onPlayStop\0onVolumeChanged\0"
    "onSettingsDone\0timeout\0"
    "on_pushButtonSetAlarm_clicked\0"
    "on_pushButtonSettings_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   74,    2, 0x0a /* Public */,
       8,    1,   77,    2, 0x0a /* Public */,
      10,    0,   80,    2, 0x0a /* Public */,
      11,    1,   81,    2, 0x0a /* Public */,
      12,    1,   84,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QTime,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playbackError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onSetAlarmTimeRequest(); break;
        case 2: _t->onSettingsRequest(); break;
        case 3: _t->onSetAlarmTimeDone((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 4: _t->onPlayStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onPlayStop(); break;
        case 6: _t->onVolumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onSettingsDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->timeout(); break;
        case 9: _t->on_pushButtonSetAlarm_clicked(); break;
        case 10: _t->on_pushButtonSettings_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormMain::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormMain::playbackError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormMain::onSetAlarmTimeRequest)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormMain::onSettingsRequest)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormMain::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormMain.data,
    qt_meta_data_FormMain,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormMain.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void FormMain::playbackError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormMain::onSetAlarmTimeRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FormMain::onSettingsRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
