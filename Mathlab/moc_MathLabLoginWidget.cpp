/****************************************************************************
** Meta object code from reading C++ file 'MathLabLoginWidget.h'
**
** Created: Sun Apr 18 21:11:34 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MathLabLoginWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MathLabLoginWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MathLabLoginWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      40,   19,   19,   19, 0x0a,
      58,   19,   19,   19, 0x0a,
      80,   19,   19,   19, 0x0a,
      97,   19,   19,   19, 0x0a,
     121,  117,   19,   19, 0x0a,
     155,  117,   19,   19, 0x0a,
     196,  189,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MathLabLoginWidget[] = {
    "MathLabLoginWidget\0\0on_Longin_clicked()\0"
    "on_Edit_clicked()\0on_Register_clicked()\0"
    "on_Yes_clicked()\0on_Return_clicked()\0"
    "arg\0on_checkBox_stu_stateChanged(int)\0"
    "on_checkBox_tea_stateChanged(int)\0"
    "edText\0on_lineEdit_textEdited(QString)\0"
};

void MathLabLoginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MathLabLoginWidget *_t = static_cast<MathLabLoginWidget *>(_o);
        switch (_id) {
        case 0: _t->on_Longin_clicked(); break;
        case 1: _t->on_Edit_clicked(); break;
        case 2: _t->on_Register_clicked(); break;
        case 3: _t->on_Yes_clicked(); break;
        case 4: _t->on_Return_clicked(); break;
        case 5: _t->on_checkBox_stu_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_tea_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MathLabLoginWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MathLabLoginWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MathLabLoginWidget,
      qt_meta_data_MathLabLoginWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MathLabLoginWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MathLabLoginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MathLabLoginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MathLabLoginWidget))
        return static_cast<void*>(const_cast< MathLabLoginWidget*>(this));
    if (!strcmp(_clname, "MathLabDataService"))
        return static_cast< MathLabDataService*>(const_cast< MathLabLoginWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int MathLabLoginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
