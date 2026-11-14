/****************************************************************************
** Meta object code from reading C++ file 'formsetalarmtime.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../formsetalarmtime.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formsetalarmtime.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormSetAlarmTime_t {
    QByteArrayData data[16];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormSetAlarmTime_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormSetAlarmTime_t qt_meta_stringdata_FormSetAlarmTime = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FormSetAlarmTime"
QT_MOC_LITERAL(1, 17, 18), // "onSetAlarmTimeExit"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 18), // "onSetAlarmTimeDone"
QT_MOC_LITERAL(4, 56, 7), // "newTime"
QT_MOC_LITERAL(5, 64, 25), // "on_pushButtonExit_clicked"
QT_MOC_LITERAL(6, 90, 25), // "on_pushButtonDone_clicked"
QT_MOC_LITERAL(7, 116, 33), // "on_pushButtonSetAlarmTime_cli..."
QT_MOC_LITERAL(8, 150, 32), // "on_pushButton_Hh_mm_plus_clicked"
QT_MOC_LITERAL(9, 183, 33), // "on_pushButton_Hh_mm_minus_cli..."
QT_MOC_LITERAL(10, 217, 32), // "on_pushButton_hH_mm_plus_clicked"
QT_MOC_LITERAL(11, 250, 33), // "on_pushButton_hH_mm_minus_cli..."
QT_MOC_LITERAL(12, 284, 32), // "on_pushButton_hh_Mm_plus_clicked"
QT_MOC_LITERAL(13, 317, 33), // "on_pushButton_hh_Mm_minus_cli..."
QT_MOC_LITERAL(14, 351, 32), // "on_pushButton_hh_mM_plus_clicked"
QT_MOC_LITERAL(15, 384, 33) // "on_pushButton_hh_mM_minus_cli..."

    },
    "FormSetAlarmTime\0onSetAlarmTimeExit\0"
    "\0onSetAlarmTimeDone\0newTime\0"
    "on_pushButtonExit_clicked\0"
    "on_pushButtonDone_clicked\0"
    "on_pushButtonSetAlarmTime_clicked\0"
    "on_pushButton_Hh_mm_plus_clicked\0"
    "on_pushButton_Hh_mm_minus_clicked\0"
    "on_pushButton_hH_mm_plus_clicked\0"
    "on_pushButton_hH_mm_minus_clicked\0"
    "on_pushButton_hh_Mm_plus_clicked\0"
    "on_pushButton_hh_Mm_minus_clicked\0"
    "on_pushButton_hh_mM_plus_clicked\0"
    "on_pushButton_hh_mM_minus_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormSetAlarmTime[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormSetAlarmTime::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormSetAlarmTime *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSetAlarmTimeExit(); break;
        case 1: _t->onSetAlarmTimeDone((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonExit_clicked(); break;
        case 3: _t->on_pushButtonDone_clicked(); break;
        case 4: _t->on_pushButtonSetAlarmTime_clicked(); break;
        case 5: _t->on_pushButton_Hh_mm_plus_clicked(); break;
        case 6: _t->on_pushButton_Hh_mm_minus_clicked(); break;
        case 7: _t->on_pushButton_hH_mm_plus_clicked(); break;
        case 8: _t->on_pushButton_hH_mm_minus_clicked(); break;
        case 9: _t->on_pushButton_hh_Mm_plus_clicked(); break;
        case 10: _t->on_pushButton_hh_Mm_minus_clicked(); break;
        case 11: _t->on_pushButton_hh_mM_plus_clicked(); break;
        case 12: _t->on_pushButton_hh_mM_minus_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormSetAlarmTime::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSetAlarmTime::onSetAlarmTimeExit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormSetAlarmTime::*)(QTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSetAlarmTime::onSetAlarmTimeDone)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormSetAlarmTime::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormSetAlarmTime.data,
    qt_meta_data_FormSetAlarmTime,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormSetAlarmTime::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormSetAlarmTime::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormSetAlarmTime.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormSetAlarmTime::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FormSetAlarmTime::onSetAlarmTimeExit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormSetAlarmTime::onSetAlarmTimeDone(QTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
