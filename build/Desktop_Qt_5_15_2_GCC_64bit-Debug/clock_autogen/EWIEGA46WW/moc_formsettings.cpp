/****************************************************************************
** Meta object code from reading C++ file 'formsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../formsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormSettings_t {
    QByteArrayData data[16];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormSettings_t qt_meta_stringdata_FormSettings = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FormSettings"
QT_MOC_LITERAL(1, 13, 13), // "onWifiRequest"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "onSettingsExit"
QT_MOC_LITERAL(4, 43, 14), // "onSettingsDone"
QT_MOC_LITERAL(5, 58, 6), // "volume"
QT_MOC_LITERAL(6, 65, 11), // "onPlayStart"
QT_MOC_LITERAL(7, 77, 10), // "onPlayStop"
QT_MOC_LITERAL(8, 88, 15), // "onVolumeChanged"
QT_MOC_LITERAL(9, 104, 15), // "onPlaybackError"
QT_MOC_LITERAL(10, 120, 7), // "message"
QT_MOC_LITERAL(11, 128, 36), // "on_pushButtonVolumeDecrement_..."
QT_MOC_LITERAL(12, 165, 36), // "on_pushButtonVolumeIncrement_..."
QT_MOC_LITERAL(13, 202, 25), // "on_pushButtonExit_clicked"
QT_MOC_LITERAL(14, 228, 25), // "on_pushButtonDone_clicked"
QT_MOC_LITERAL(15, 254, 25) // "on_pushButtonTest_clicked"

    },
    "FormSettings\0onWifiRequest\0\0onSettingsExit\0"
    "onSettingsDone\0volume\0onPlayStart\0"
    "onPlayStop\0onVolumeChanged\0onPlaybackError\0"
    "message\0on_pushButtonVolumeDecrement_clicked\0"
    "on_pushButtonVolumeIncrement_clicked\0"
    "on_pushButtonExit_clicked\0"
    "on_pushButtonDone_clicked\0"
    "on_pushButtonTest_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    1,   76,    2, 0x06 /* Public */,
       6,    1,   79,    2, 0x06 /* Public */,
       7,    0,   82,    2, 0x06 /* Public */,
       8,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   86,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onWifiRequest(); break;
        case 1: _t->onSettingsExit(); break;
        case 2: _t->onSettingsDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onPlayStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onPlayStop(); break;
        case 5: _t->onVolumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onPlaybackError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonVolumeDecrement_clicked(); break;
        case 8: _t->on_pushButtonVolumeIncrement_clicked(); break;
        case 9: _t->on_pushButtonExit_clicked(); break;
        case 10: _t->on_pushButtonDone_clicked(); break;
        case 11: _t->on_pushButtonTest_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::onWifiRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::onSettingsExit)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormSettings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::onSettingsDone)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FormSettings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::onPlayStart)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FormSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::onPlayStop)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FormSettings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::onVolumeChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormSettings.data,
    qt_meta_data_FormSettings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormSettings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void FormSettings::onWifiRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormSettings::onSettingsExit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FormSettings::onSettingsDone(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FormSettings::onPlayStart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FormSettings::onPlayStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FormSettings::onVolumeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
