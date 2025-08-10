/****************************************************************************
** Meta object code from reading C++ file 'handleuser.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../handleuser.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handleuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10handleuserE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10handleuserE = QtMocHelpers::stringData(
    "handleuser",
    "addUser",
    "",
    "firstname",
    "lastname",
    "phonenumber",
    "firstsession",
    "date",
    "sessions",
    "days",
    "deleteUser",
    "deleteUserFromDb",
    "inserttodb",
    "showusers",
    "getUser",
    "index",
    "item",
    "readFromDatabase",
    "getNumberOfUser",
    "convertToLastDatDay1",
    "firstDate",
    "convertToLastDatDay2",
    "convertToLastDatDay3",
    "convertToQDate",
    "whichDay",
    "firstSundayOrTuesday",
    "QDate&",
    "firstStep",
    "firstSundayOrThursday",
    "firstThursdayOrTuesday"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10handleuserE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    7,  110,    2, 0x02,    1 /* Public */,
      10,    1,  125,    2, 0x02,    9 /* Public */,
      11,    1,  128,    2, 0x02,   11 /* Public */,
      12,    7,  131,    2, 0x02,   13 /* Public */,
      13,    0,  146,    2, 0x02,   21 /* Public */,
      14,    2,  147,    2, 0x02,   22 /* Public */,
      17,    0,  152,    2, 0x02,   25 /* Public */,
      18,    0,  153,    2, 0x02,   26 /* Public */,
      19,    2,  154,    2, 0x02,   27 /* Public */,
      21,    2,  159,    2, 0x02,   30 /* Public */,
      22,    2,  164,    2, 0x02,   33 /* Public */,
      23,    1,  169,    2, 0x02,   36 /* Public */,
      24,    1,  172,    2, 0x02,   38 /* Public */,
      25,    1,  175,    2, 0x02,   40 /* Public */,
      28,    1,  178,    2, 0x02,   42 /* Public */,
      29,    1,  181,    2, 0x02,   44 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Int, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   20,    8,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   20,    8,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   20,    8,
    QMetaType::QDate, QMetaType::QString,    7,
    QMetaType::Int, QMetaType::QDate,    7,
    QMetaType::QDate, 0x80000000 | 26,   27,
    QMetaType::QDate, 0x80000000 | 26,   27,
    QMetaType::QDate, 0x80000000 | 26,   27,

       0        // eod
};

Q_CONSTINIT const QMetaObject handleuser::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN10handleuserE.offsetsAndSizes,
    qt_meta_data_ZN10handleuserE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10handleuserE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<handleuser, std::true_type>,
        // method 'addUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'deleteUser'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'deleteUserFromDb'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'inserttodb'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showusers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getUser'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'readFromDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getNumberOfUser'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'convertToLastDatDay1'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'convertToLastDatDay2'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'convertToLastDatDay3'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'convertToQDate'
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'whichDay'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        // method 'firstSundayOrTuesday'
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate &, std::false_type>,
        // method 'firstSundayOrThursday'
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate &, std::false_type>,
        // method 'firstThursdayOrTuesday'
        QtPrivate::TypeAndForceComplete<QDate, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDate &, std::false_type>
    >,
    nullptr
} };

void handleuser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<handleuser *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->addUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7]))); break;
        case 1: { int _r = _t->deleteUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->deleteUserFromDb((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->inserttodb((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7]))); break;
        case 4: _t->showusers(); break;
        case 5: { QString _r = _t->getUser((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->readFromDatabase(); break;
        case 7: { int _r = _t->getNumberOfUser();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->convertToLastDatDay1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->convertToLastDatDay2((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->convertToLastDatDay3((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QDate _r = _t->convertToQDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->whichDay((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { QDate _r = _t->firstSundayOrTuesday((*reinterpret_cast< std::add_pointer_t<QDate&>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        case 14: { QDate _r = _t->firstSundayOrThursday((*reinterpret_cast< std::add_pointer_t<QDate&>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        case 15: { QDate _r = _t->firstThursdayOrTuesday((*reinterpret_cast< std::add_pointer_t<QDate&>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *handleuser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *handleuser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10handleuserE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int handleuser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
