/****************************************************************************
** Meta object code from reading C++ file 'MathLab.h'
**
** Created: Sun May 16 21:59:33 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MathLab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MathLab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MathLab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,    9,    8,    8, 0x0a,
      47,    8,    8,    8, 0x0a,
      83,   68,    8,    8, 0x0a,
     122,    8,    8,    8, 0x0a,
     148,  143,    8,    8, 0x0a,
     187,    8,    8,    8, 0x0a,
     214,  208,    8,    8, 0x0a,
     246,  239,    8,    8, 0x0a,
     307,  305,    8,    8, 0x08,
     365,  356,    8,    8, 0x08,
     413,    8,    8,    8, 0x08,
     436,    8,    8,    8, 0x08,
     460,    8,    8,    8, 0x08,
     483,    8,    8,    8, 0x08,
     499,    8,    8,    8, 0x08,
     517,    8,    8,    8, 0x08,
     572,  537,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MathLab[] = {
    "MathLab\0\0dateTime\0OnDateEditChanged(QDateTime)\0"
    "OnNewCourseClicked()\0classRoom,item\0"
    "OnNewCourse(QString,QTableWidgetItem*)\0"
    "OnDelCourseClicked()\0item\0"
    "OnTableWidgetDouble(QTableWidgetItem*)\0"
    "OnResetDateClicked()\0event\0"
    "closeEvent(QCloseEvent*)\0reason\0"
    "on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)\0"
    "p\0on_treeWidget_customContextMenuRequested(QPoint)\0"
    "item,col\0on_treeWidget_itemClicked(QTreeWidgetItem*,int)\0"
    "on_addItem_triggered()\0on_editItem_triggered()\0"
    "on_delItem_triggered()\0ReturnToLogin()\0"
    "showMineCourses()\0SearchClassCourse()\0"
    "courseLst,searchClass,teachersPaln\0"
    "SearchByUserClass(CourseInfoList&,QString,bool)\0"
};

void MathLab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MathLab *_t = static_cast<MathLab *>(_o);
        switch (_id) {
        case 0: _t->OnDateEditChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 1: _t->OnNewCourseClicked(); break;
        case 2: _t->OnNewCourse((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTableWidgetItem*(*)>(_a[2]))); break;
        case 3: _t->OnDelCourseClicked(); break;
        case 4: _t->OnTableWidgetDouble((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->OnResetDateClicked(); break;
        case 6: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 7: _t->on_activatedSysTrayIcon((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 8: _t->on_treeWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->on_treeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_addItem_triggered(); break;
        case 11: _t->on_editItem_triggered(); break;
        case 12: _t->on_delItem_triggered(); break;
        case 13: _t->ReturnToLogin(); break;
        case 14: _t->showMineCourses(); break;
        case 15: _t->SearchClassCourse(); break;
        case 16: _t->SearchByUserClass((*reinterpret_cast< CourseInfoList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MathLab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MathLab::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MathLab,
      qt_meta_data_MathLab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MathLab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MathLab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MathLab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MathLab))
        return static_cast<void*>(const_cast< MathLab*>(this));
    if (!strcmp(_clname, "MathLabDataService"))
        return static_cast< MathLabDataService*>(const_cast< MathLab*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MathLab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
