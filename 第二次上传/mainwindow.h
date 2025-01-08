#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include <QPlainTextEdit>
#include "codeeditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QMenu* getBookmarkMenu() const;



public slots:
    void updateStatusBar(QPlainTextEdit *editor);
    void on_tabWidget_currentChanged(int index);
    void on_actionThemeToggle_triggered();
    void onTabChanged(int index);
    void on_actionDark_triggered();
    void on_actionLight_triggered();
    void addToRecentFiles(const QString &filePath);
    void updateRecentFilesMenu();
    void onRecentFileTriggered();
    void on_actionClearHistory_triggered();
    void setupMenus();
    void addBookmark();
    void updateBookmarkMenu(QPlainTextEdit *editor);

    void initFavoriteMenu();
    void on_actionClearFavorites_triggered();
    void on_actionOpenFavorite_triggered();
    void on_actionRemoveFavorite_triggered();
    void on_actionAddFavorite_triggered();
    void on_actionAdd_triggered();
    void on_actionGoTo_triggered();
    void on_actionRemove_triggered();
    void on_actionRemoveAll_triggered();
    void on_actionSavetemp_triggered();
    void recoverUnsavedFiles();
    void autosaveFiles();
private slots:
    void on_actionAbout_triggered();
    void on_actionFind_triggered();
    void on_actionReplace_triggered();
    void on_actionNew_triggered();


    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_textEdit_textChanged();
    void on_actionUndo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionRedo_triggered();
    void on_textEdit_copyAvailable(bool b);
    void on_textEdit_redoAvailable(bool b);
    void on_textEdit_undoAvailable(bool b);
    void on_actionFontBackgroundColor_triggered();
    void on_actionBackgroundColor_triggered();
    void on_actionFontColor_triggered();
    void on_actionWrap_triggered();
    void on_actionFont_triggered();
    void on_actionToolbar_triggered();
    void on_actionStatusBar_triggered();
    void on_actionSelectAll_triggered();
    void on_action_Exit_triggered();
    void on_textEdit_cursorPositionChanged();
    void highlightBookmarks(QPlainTextEdit *editor);
    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;

    QStringList recentFiles;
    const int maxRecentFiles = 10;

    QLabel statusCursorLabel;
    QLabel statusLabel;

    QString filePath;
    QTabWidget *tabWidget;



    bool textChanged;
    bool userEditConfirmed();
    bool isDarkMode = false;

    CodeEditor *codeEditor;
    QMap<CodeEditor*, QSet<int>> bookmarks;

    QSet<QString> favorites;

    QTimer *autosaveTimer;

};
#endif // MAINWINDOW_H
