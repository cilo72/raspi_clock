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
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormMain_t qt_meta_stringdata_FormMain = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FormMain"
QT_MOC_LITERAL(1, 9, 21), // "onSetAlarmTimeRequest"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "onSettingsRequest"
QT_MOC_LITERAL(4, 50, 18), // "onSetAlarmTimeDone"
QT_MOC_LITERAL(5, 69, 7), // "newTime"
QT_MOC_LITERAL(6, 77, 11), // "onPlayStart"
QT_MOC_LITERAL(7, 89, 3), // "url"
QT_MOC_LITERAL(8, 93, 10), // "onPlayStop"
QT_MOC_LITERAL(9, 104, 15), // "onVolumeChanged"
QT_MOC_LITERAL(10, 120, 6), // "volume"
QT_MOC_LITERAL(11, 127, 14), // "onSettingsDone"
QT_MOC_LITERAL(12, 142, 7), // "station"
QT_MOC_LITERAL(13, 150, 7), // "timeout"
QT_MOC_LITERAL(14, 158, 29), // "on_pushButtonSetAlarm_clicked"
QT_MOC_LITERAL(15, 188, 29) // "on_pushButtonSettings_clicked"

    },
    "FormMain\0onSetAlarmTimeRequest\0\0"
    "onSettingsRequest\0onSetAlarmTimeDone\0"
    "newTime\0onPlayStart\0url\0onPlayStop\0"
    "onVolumeChanged\0volume\0onSettingsDone\0"
    "station\0timeout\0on_pushButtonSetAlarm_clicked\0"
    "on_pushButtonSettings_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   66,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    1,   73,    2, 0x0a /* Public */,
      11,    2,   76,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QTime,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   12,
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
        case 0: _t->onSetAlarmTimeRequest(); break;
        case 1: _t->onSettingsRequest(); break;
        case 2: _t->onSetAlarmTimeDone((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 3: _t->onPlayStart((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onPlayStop(); break;
        case 5: _t->onVolumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onSettingsDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->timeout(); break;
        case 8: _t->on_pushButtonSetAlarm_clicked(); break;
        case 9: _t->on_pushButtonSettings_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormMain::onSetAlarmTimeRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormMain::onSettingsRequest)) {
                *result = 1;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FormMain::onSetAlarmTimeRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormMain::onSettingsRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
