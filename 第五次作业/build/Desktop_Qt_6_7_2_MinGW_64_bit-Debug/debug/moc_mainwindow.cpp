/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "updateStatusBar",
    "",
    "QPlainTextEdit*",
    "editor",
    "on_tabWidget_currentChanged",
    "index",
    "on_actionThemeToggle_triggered",
    "onTabChanged",
    "on_actionDark_triggered",
    "on_actionLight_triggered",
    "addToRecentFiles",
    "filePath",
    "updateRecentFilesMenu",
    "onRecentFileTriggered",
    "on_actionClearHistory_triggered",
    "setupMenus",
    "addBookmark",
    "updateBookmarkMenu",
    "initFavoriteMenu",
    "on_actionClearFavorites_triggered",
    "on_actionOpenFavorite_triggered",
    "on_actionRemoveFavorite_triggered",
    "on_actionAddFavorite_triggered",
    "on_actionAdd_triggered",
    "on_actionGoTo_triggered",
    "on_actionRemove_triggered",
    "on_actionRemoveAll_triggered",
    "on_actionSavetemp_triggered",
    "recoverUnsavedFiles",
    "autosaveFiles",
    "on_actionAbout_triggered",
    "on_actionFind_triggered",
    "on_actionReplace_triggered",
    "on_actionNew_triggered",
    "on_actionOpen_triggered",
    "on_actionSave_triggered",
    "on_actionSaveAs_triggered",
    "on_textEdit_textChanged",
    "on_actionUndo_triggered",
    "on_actionCut_triggered",
    "on_actionCopy_triggered",
    "on_actionPaste_triggered",
    "on_actionRedo_triggered",
    "on_textEdit_copyAvailable",
    "b",
    "on_textEdit_redoAvailable",
    "on_textEdit_undoAvailable",
    "on_actionFontBackgroundColor_triggered",
    "on_actionBackgroundColor_triggered",
    "on_actionFontColor_triggered",
    "on_actionWrap_triggered",
    "on_actionFont_triggered",
    "on_actionToolbar_triggered",
    "on_actionStatusBar_triggered",
    "on_actionSelectAll_triggered",
    "on_action_Exit_triggered",
    "on_textEdit_cursorPositionChanged",
    "highlightBookmarks",
    "on_tabWidget_tabCloseRequested"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  332,    2, 0x0a,    1 /* Public */,
       5,    1,  335,    2, 0x0a,    3 /* Public */,
       7,    0,  338,    2, 0x0a,    5 /* Public */,
       8,    1,  339,    2, 0x0a,    6 /* Public */,
       9,    0,  342,    2, 0x0a,    8 /* Public */,
      10,    0,  343,    2, 0x0a,    9 /* Public */,
      11,    1,  344,    2, 0x0a,   10 /* Public */,
      13,    0,  347,    2, 0x0a,   12 /* Public */,
      14,    0,  348,    2, 0x0a,   13 /* Public */,
      15,    0,  349,    2, 0x0a,   14 /* Public */,
      16,    0,  350,    2, 0x0a,   15 /* Public */,
      17,    0,  351,    2, 0x0a,   16 /* Public */,
      18,    1,  352,    2, 0x0a,   17 /* Public */,
      19,    0,  355,    2, 0x0a,   19 /* Public */,
      20,    0,  356,    2, 0x0a,   20 /* Public */,
      21,    0,  357,    2, 0x0a,   21 /* Public */,
      22,    0,  358,    2, 0x0a,   22 /* Public */,
      23,    0,  359,    2, 0x0a,   23 /* Public */,
      24,    0,  360,    2, 0x0a,   24 /* Public */,
      25,    0,  361,    2, 0x0a,   25 /* Public */,
      26,    0,  362,    2, 0x0a,   26 /* Public */,
      27,    0,  363,    2, 0x0a,   27 /* Public */,
      28,    0,  364,    2, 0x0a,   28 /* Public */,
      29,    0,  365,    2, 0x0a,   29 /* Public */,
      30,    0,  366,    2, 0x0a,   30 /* Public */,
      31,    0,  367,    2, 0x08,   31 /* Private */,
      32,    0,  368,    2, 0x08,   32 /* Private */,
      33,    0,  369,    2, 0x08,   33 /* Private */,
      34,    0,  370,    2, 0x08,   34 /* Private */,
      35,    0,  371,    2, 0x08,   35 /* Private */,
      36,    0,  372,    2, 0x08,   36 /* Private */,
      37,    0,  373,    2, 0x08,   37 /* Private */,
      38,    0,  374,    2, 0x08,   38 /* Private */,
      39,    0,  375,    2, 0x08,   39 /* Private */,
      40,    0,  376,    2, 0x08,   40 /* Private */,
      41,    0,  377,    2, 0x08,   41 /* Private */,
      42,    0,  378,    2, 0x08,   42 /* Private */,
      43,    0,  379,    2, 0x08,   43 /* Private */,
      44,    1,  380,    2, 0x08,   44 /* Private */,
      46,    1,  383,    2, 0x08,   46 /* Private */,
      47,    1,  386,    2, 0x08,   48 /* Private */,
      48,    0,  389,    2, 0x08,   50 /* Private */,
      49,    0,  390,    2, 0x08,   51 /* Private */,
      50,    0,  391,    2, 0x08,   52 /* Private */,
      51,    0,  392,    2, 0x08,   53 /* Private */,
      52,    0,  393,    2, 0x08,   54 /* Private */,
      53,    0,  394,    2, 0x08,   55 /* Private */,
      54,    0,  395,    2, 0x08,   56 /* Private */,
      55,    0,  396,    2, 0x08,   57 /* Private */,
      56,    0,  397,    2, 0x08,   58 /* Private */,
      57,    0,  398,    2, 0x08,   59 /* Private */,
      58,    1,  399,    2, 0x08,   60 /* Private */,
      59,    1,  402,    2, 0x08,   62 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   45,
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
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'updateStatusBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPlainTextEdit *, std::false_type>,
        // method 'on_tabWidget_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_actionThemeToggle_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_actionDark_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLight_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addToRecentFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateRecentFilesMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRecentFileTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionClearHistory_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupMenus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addBookmark'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateBookmarkMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPlainTextEdit *, std::false_type>,
        // method 'initFavoriteMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionClearFavorites_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOpenFavorite_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRemoveFavorite_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAddFavorite_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAdd_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionGoTo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRemove_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRemoveAll_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSavetemp_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recoverUnsavedFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'autosaveFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAbout_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFind_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionReplace_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionNew_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOpen_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSave_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSaveAs_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_textEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionUndo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCut_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCopy_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionPaste_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRedo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_textEdit_copyAvailable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_textEdit_redoAvailable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_textEdit_undoAvailable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_actionFontBackgroundColor_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionBackgroundColor_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFontColor_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionWrap_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFont_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionToolbar_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionStatusBar_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSelectAll_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Exit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_textEdit_cursorPositionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highlightBookmarks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPlainTextEdit *, std::false_type>,
        // method 'on_tabWidget_tabCloseRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateStatusBar((*reinterpret_cast< std::add_pointer_t<QPlainTextEdit*>>(_a[1]))); break;
        case 1: _t->on_tabWidget_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_actionThemeToggle_triggered(); break;
        case 3: _t->onTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_actionDark_triggered(); break;
        case 5: _t->on_actionLight_triggered(); break;
        case 6: _t->addToRecentFiles((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->updateRecentFilesMenu(); break;
        case 8: _t->onRecentFileTriggered(); break;
        case 9: _t->on_actionClearHistory_triggered(); break;
        case 10: _t->setupMenus(); break;
        case 11: _t->addBookmark(); break;
        case 12: _t->updateBookmarkMenu((*reinterpret_cast< std::add_pointer_t<QPlainTextEdit*>>(_a[1]))); break;
        case 13: _t->initFavoriteMenu(); break;
        case 14: _t->on_actionClearFavorites_triggered(); break;
        case 15: _t->on_actionOpenFavorite_triggered(); break;
        case 16: _t->on_actionRemoveFavorite_triggered(); break;
        case 17: _t->on_actionAddFavorite_triggered(); break;
        case 18: _t->on_actionAdd_triggered(); break;
        case 19: _t->on_actionGoTo_triggered(); break;
        case 20: _t->on_actionRemove_triggered(); break;
        case 21: _t->on_actionRemoveAll_triggered(); break;
        case 22: _t->on_actionSavetemp_triggered(); break;
        case 23: _t->recoverUnsavedFiles(); break;
        case 24: _t->autosaveFiles(); break;
        case 25: _t->on_actionAbout_triggered(); break;
        case 26: _t->on_actionFind_triggered(); break;
        case 27: _t->on_actionReplace_triggered(); break;
        case 28: _t->on_actionNew_triggered(); break;
        case 29: _t->on_actionOpen_triggered(); break;
        case 30: _t->on_actionSave_triggered(); break;
        case 31: _t->on_actionSaveAs_triggered(); break;
        case 32: _t->on_textEdit_textChanged(); break;
        case 33: _t->on_actionUndo_triggered(); break;
        case 34: _t->on_actionCut_triggered(); break;
        case 35: _t->on_actionCopy_triggered(); break;
        case 36: _t->on_actionPaste_triggered(); break;
        case 37: _t->on_actionRedo_triggered(); break;
        case 38: _t->on_textEdit_copyAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 39: _t->on_textEdit_redoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 40: _t->on_textEdit_undoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 41: _t->on_actionFontBackgroundColor_triggered(); break;
        case 42: _t->on_actionBackgroundColor_triggered(); break;
        case 43: _t->on_actionFontColor_triggered(); break;
        case 44: _t->on_actionWrap_triggered(); break;
        case 45: _t->on_actionFont_triggered(); break;
        case 46: _t->on_actionToolbar_triggered(); break;
        case 47: _t->on_actionStatusBar_triggered(); break;
        case 48: _t->on_actionSelectAll_triggered(); break;
        case 49: _t->on_action_Exit_triggered(); break;
        case 50: _t->on_textEdit_cursorPositionChanged(); break;
        case 51: _t->highlightBookmarks((*reinterpret_cast< std::add_pointer_t<QPlainTextEdit*>>(_a[1]))); break;
        case 52: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPlainTextEdit* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPlainTextEdit* >(); break;
            }
            break;
        case 51:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPlainTextEdit* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    }
    return _id;
}
QT_WARNING_POP
