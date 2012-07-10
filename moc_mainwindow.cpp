/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Jul 9 22:17:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   12,   11,   11, 0x05,
      40,   11,   11,   11, 0x05,
      57,   53,   11,   11, 0x05,
      72,   11,   11,   11, 0x05,
      84,   11,   11,   11, 0x05,
      97,   11,   11,   11, 0x05,
     112,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     123,   11,   11,   11, 0x08,
     153,   11,   11,   11, 0x08,
     179,   12,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     210,   53,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     240,   11,   11,   11, 0x08,
     261,   11,   11,   11, 0x08,
     293,   11,   11,   11, 0x08,
     317,   11,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     366,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,
     414,   11,   11,   11, 0x08,
     438,   11,   11,   11, 0x08,
     463,   11,   11,   11, 0x08,
     485,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0direction\0gamerUpdated(int)\0"
    "boxUpdated()\0pos\0onSpot(QPoint)\0"
    "nextLevel()\0hudUpdated()\0gamerRemoved()\0"
    "gameOver()\0on_actionNew_Game_triggered()\0"
    "on_actionTest_triggered()\0updateGamer(int)\0"
    "updateBoxes()\0boxOnSpot(QPoint)\0"
    "updateHUD()\0removeGamerWarning()\0"
    "on_actionMap_Editor_triggered()\0"
    "on_loadButton_clicked()\0on_saveButton_clicked()\0"
    "on_floorButton_clicked()\0"
    "on_brickButton_clicked()\0"
    "on_boxButton_clicked()\0on_spotButton_clicked()\0"
    "on_gamerButton_clicked()\0on_okButton_clicked()\0"
    "finishGame()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->gamerUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->boxUpdated(); break;
        case 2: _t->onSpot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->nextLevel(); break;
        case 4: _t->hudUpdated(); break;
        case 5: _t->gamerRemoved(); break;
        case 6: _t->gameOver(); break;
        case 7: _t->on_actionNew_Game_triggered(); break;
        case 8: _t->on_actionTest_triggered(); break;
        case 9: _t->updateGamer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateBoxes(); break;
        case 11: _t->boxOnSpot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->updateHUD(); break;
        case 13: _t->removeGamerWarning(); break;
        case 14: _t->on_actionMap_Editor_triggered(); break;
        case 15: _t->on_loadButton_clicked(); break;
        case 16: _t->on_saveButton_clicked(); break;
        case 17: _t->on_floorButton_clicked(); break;
        case 18: _t->on_brickButton_clicked(); break;
        case 19: _t->on_boxButton_clicked(); break;
        case 20: _t->on_spotButton_clicked(); break;
        case 21: _t->on_gamerButton_clicked(); break;
        case 22: _t->on_okButton_clicked(); break;
        case 23: _t->finishGame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::gamerUpdated(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::boxUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::onSpot(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::nextLevel()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::hudUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindow::gamerRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
