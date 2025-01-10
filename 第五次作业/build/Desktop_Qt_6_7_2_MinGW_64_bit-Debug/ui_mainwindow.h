/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <codeeditor.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *action_Exit;
    QAction *actionUndo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionFont;
    QAction *actionWrap;
    QAction *actionToolbar;
    QAction *actionStatusBar;
    QAction *actionRedo;
    QAction *actionSelectAll;
    QAction *actionAbout;
    QAction *actionFontColor;
    QAction *actionBackgroundColor;
    QAction *actionFontBackgroundColor;
    QAction *actionDark;
    QAction *actionLight;
    QAction *actionclear;
    QAction *actionadd;
    QAction *actionremove;
    QAction *actionopen;
    QAction *actionremoveall;
    QAction *add;
    QAction *gotobookmark;
    QAction *remove;
    QAction *removeall;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    CodeEditor *textEdit;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_V;
    QMenu *menu_H;
    QMenu *menu_2;
    QMenu *recentFilesMenu;
    QMenu *bookmarkmenu;
    QMenu *favorites;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/new.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon);
        actionNew->setMenuRole(QAction::MenuRole::NoRole);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen->setIcon(icon1);
        actionOpen->setMenuRole(QAction::MenuRole::NoRole);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave->setIcon(icon2);
        actionSave->setMenuRole(QAction::MenuRole::NoRole);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/saveas.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSaveAs->setIcon(icon3);
        actionSaveAs->setMenuRole(QAction::MenuRole::NoRole);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName("action_Exit");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        action_Exit->setIcon(icon4);
        action_Exit->setMenuRole(QAction::MenuRole::NoRole);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/chexiao.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionUndo->setIcon(icon5);
        actionUndo->setMenuRole(QAction::MenuRole::NoRole);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/jianqie.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCut->setIcon(icon6);
        actionCut->setMenuRole(QAction::MenuRole::NoRole);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/copy.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCopy->setIcon(icon7);
        actionCopy->setMenuRole(QAction::MenuRole::NoRole);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/zhantie.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPaste->setIcon(icon8);
        actionPaste->setMenuRole(QAction::MenuRole::NoRole);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFind->setIcon(icon9);
        actionFind->setMenuRole(QAction::MenuRole::NoRole);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName("actionReplace");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/tihuan.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionReplace->setIcon(icon10);
        actionReplace->setMenuRole(QAction::MenuRole::NoRole);
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName("actionFont");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/font.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFont->setIcon(icon11);
        actionFont->setMenuRole(QAction::MenuRole::NoRole);
        actionWrap = new QAction(MainWindow);
        actionWrap->setObjectName("actionWrap");
        actionWrap->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/image/huanhang.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionWrap->setIcon(icon12);
        actionWrap->setMenuRole(QAction::MenuRole::NoRole);
        actionToolbar = new QAction(MainWindow);
        actionToolbar->setObjectName("actionToolbar");
        actionToolbar->setCheckable(true);
        actionToolbar->setChecked(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/image/gongjulan .png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionToolbar->setIcon(icon13);
        actionToolbar->setMenuRole(QAction::MenuRole::NoRole);
        actionStatusBar = new QAction(MainWindow);
        actionStatusBar->setObjectName("actionStatusBar");
        actionStatusBar->setCheckable(true);
        actionStatusBar->setChecked(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/image/zhuangtailan.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStatusBar->setIcon(icon14);
        actionStatusBar->setMenuRole(QAction::MenuRole::NoRole);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/image/huifu.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRedo->setIcon(icon15);
        actionRedo->setMenuRole(QAction::MenuRole::NoRole);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName("actionSelectAll");
        actionSelectAll->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        actionFontColor = new QAction(MainWindow);
        actionFontColor->setObjectName("actionFontColor");
        actionFontColor->setMenuRole(QAction::MenuRole::NoRole);
        actionBackgroundColor = new QAction(MainWindow);
        actionBackgroundColor->setObjectName("actionBackgroundColor");
        actionBackgroundColor->setMenuRole(QAction::MenuRole::NoRole);
        actionFontBackgroundColor = new QAction(MainWindow);
        actionFontBackgroundColor->setObjectName("actionFontBackgroundColor");
        actionFontBackgroundColor->setMenuRole(QAction::MenuRole::NoRole);
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName("actionDark");
        actionDark->setCheckable(false);
        actionDark->setChecked(false);
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName("actionLight");
        actionLight->setCheckable(false);
        actionLight->setChecked(false);
        actionclear = new QAction(MainWindow);
        actionclear->setObjectName("actionclear");
        actionadd = new QAction(MainWindow);
        actionadd->setObjectName("actionadd");
        actionremove = new QAction(MainWindow);
        actionremove->setObjectName("actionremove");
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName("actionopen");
        actionremoveall = new QAction(MainWindow);
        actionremoveall->setObjectName("actionremoveall");
        add = new QAction(MainWindow);
        add->setObjectName("add");
        gotobookmark = new QAction(MainWindow);
        gotobookmark->setObjectName("gotobookmark");
        remove = new QAction(MainWindow);
        remove->setObjectName("remove");
        removeall = new QAction(MainWindow);
        removeall->setObjectName("removeall");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        textEdit = new CodeEditor(tab);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 10, 798, 491));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_E = new QMenu(menubar);
        menu_E->setObjectName("menu_E");
        menu_O = new QMenu(menubar);
        menu_O->setObjectName("menu_O");
        menu_V = new QMenu(menubar);
        menu_V->setObjectName("menu_V");
        menu_H = new QMenu(menubar);
        menu_H->setObjectName("menu_H");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_2->setTearOffEnabled(false);
        menu_2->setSeparatorsCollapsible(false);
        menu_2->setToolTipsVisible(false);
        recentFilesMenu = new QMenu(menubar);
        recentFilesMenu->setObjectName("recentFilesMenu");
        bookmarkmenu = new QMenu(menubar);
        bookmarkmenu->setObjectName("bookmarkmenu");
        favorites = new QMenu(menubar);
        favorites->setObjectName("favorites");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu_V->menuAction());
        menubar->addAction(recentFilesMenu->menuAction());
        menubar->addAction(bookmarkmenu->menuAction());
        menubar->addAction(favorites->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addAction(action_Exit);
        menu_E->addAction(action_Exit);
        menu_E->addAction(actionUndo);
        menu_E->addAction(actionCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionPaste);
        menu_E->addSeparator();
        menu_E->addAction(actionFind);
        menu_E->addAction(actionReplace);
        menu_E->addSeparator();
        menu_E->addAction(actionSelectAll);
        menu_O->addAction(actionFont);
        menu_O->addAction(actionFontColor);
        menu_O->addAction(actionFontBackgroundColor);
        menu_O->addAction(actionBackgroundColor);
        menu_O->addAction(actionWrap);
        menu_V->addAction(actionToolbar);
        menu_V->addAction(actionStatusBar);
        menu_H->addAction(actionAbout);
        menu_2->addAction(actionDark);
        menu_2->addAction(actionLight);
        recentFilesMenu->addAction(actionclear);
        bookmarkmenu->addAction(add);
        bookmarkmenu->addAction(gotobookmark);
        bookmarkmenu->addAction(remove);
        bookmarkmenu->addAction(removeall);
        favorites->addAction(actionadd);
        favorites->addAction(actionremove);
        favorites->addAction(actionopen);
        favorites->addAction(actionremoveall);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSaveAs);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addSeparator();
        toolBar->addAction(actionFind);
        toolBar->addAction(actionReplace);
        toolBar->addSeparator();
        toolBar->addAction(actionWrap);
        toolBar->addSeparator();
        toolBar->addAction(actionFont);
        toolBar->addAction(actionToolbar);
        toolBar->addAction(actionStatusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
        action_Exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", nullptr));
#if QT_CONFIG(tooltip)
        action_Exit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200\357\274\210&U\357\274\211", nullptr));
#if QT_CONFIG(tooltip)
        actionUndo->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", nullptr));
#if QT_CONFIG(tooltip)
        actionCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266\357\274\210&C\357\274\211", nullptr));
#if QT_CONFIG(tooltip)
        actionCopy->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264\357\274\210&V\357\274\211", nullptr));
#if QT_CONFIG(tooltip)
        actionPaste->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276(&F)", nullptr));
#if QT_CONFIG(tooltip)
        actionFind->setToolTip(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("MainWindow", "\346\233\277\346\215\242(&R)", nullptr));
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFont->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223(&F)", nullptr));
#if QT_CONFIG(tooltip)
        actionFont->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWrap->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214(&W)", nullptr));
#if QT_CONFIG(tooltip)
        actionWrap->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actionToolbar->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217(&T)", nullptr));
#if QT_CONFIG(tooltip)
        actionToolbar->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionStatusBar->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217(&S)", nullptr));
#if QT_CONFIG(tooltip)
        actionStatusBar->setToolTip(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215(&)", nullptr));
#if QT_CONFIG(tooltip)
        actionRedo->setToolTip(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelectAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211(&A)", nullptr));
#if QT_CONFIG(tooltip)
        actionSelectAll->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSelectAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFontColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionFontColor->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBackgroundColor->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionBackgroundColor->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFontBackgroundColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionFontBackgroundColor->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDark->setText(QCoreApplication::translate("MainWindow", "\346\267\261\350\211\262\346\250\241\345\274\217", nullptr));
        actionLight->setText(QCoreApplication::translate("MainWindow", "\346\265\205\350\211\262\346\250\241\345\274\217", nullptr));
        actionclear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\216\206\345\217\262", nullptr));
        actionadd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\224\266\350\227\217\346\226\207\344\273\266", nullptr));
        actionremove->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\346\224\266\350\227\217\346\226\207\344\273\266", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\224\266\350\227\217\345\244\271", nullptr));
        actionremoveall->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\346\211\200\346\234\211\346\224\266\350\227\217\346\226\207\344\273\266", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\271\246\347\255\276", nullptr));
        gotobookmark->setText(QCoreApplication::translate("MainWindow", "\345\216\273\345\276\200\344\271\246\347\255\276", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\345\215\225\344\270\252\344\271\246\347\255\276", nullptr));
        removeall->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\346\211\200\346\234\211\344\271\246\347\255\276", nullptr));
        textEdit->setPlainText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_O->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217(&O)", nullptr));
        menu_V->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\344\270\273\351\242\230\345\210\207\346\215\242(L)", nullptr));
        recentFilesMenu->setTitle(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        bookmarkmenu->setTitle(QCoreApplication::translate("MainWindow", "\344\271\246\347\255\276", nullptr));
        favorites->setTitle(QCoreApplication::translate("MainWindow", "\346\224\266\350\227\217\345\244\271", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
