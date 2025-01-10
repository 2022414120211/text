#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "searchdialog.h"
#include "replacedialog.h"
#include "qfiledialog.h"
#include "syntaxhighlighter.h"
#include "QColorDialog"
#include"QTextStream"
#include"QMessageBox"
#include"QFontDialog"
#include<QDebug>
#include "codeeditor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFileDialog>
#include <QMenu>
#include <QDebug>
#include <QInputDialog>
#include <QTimer>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget);
    tabWidget->setTabsClosable(true);


    textChanged = false;


    on_actionNew_triggered();


    statusLabel.setMaximumWidth(150);
    statusLabel.setText("Length: 0  Lines: 1");
    ui->statusbar->addPermanentWidget(&statusLabel);


    QLabel *author = new QLabel(ui->statusbar);
    author->setText(tr("李华凯"));
    ui->statusbar->addPermanentWidget(author);


    statusCursorLabel.setMaximumWidth(100);
    statusCursorLabel.setText("Ln: 1  Col: 1");
    ui->statusbar->addPermanentWidget(&statusCursorLabel);

    connect(ui->textEdit, &QPlainTextEdit::textChanged, this, &MainWindow::on_textEdit_textChanged);

    connect(ui->textEdit, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::on_textEdit_cursorPositionChanged);

    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::on_tabWidget_tabCloseRequested);

    connect(tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    connect(ui->actionDark, &QAction::triggered, this, &MainWindow::on_actionDark_triggered);

    connect(ui->actionLight, &QAction::triggered, this, &MainWindow::on_actionLight_triggered);

    connect(ui->actionclear, &QAction::triggered, this, &MainWindow::on_actionClearHistory_triggered);

    connect(ui->actionadd, &QAction::triggered, this, &MainWindow::on_actionAddFavorite_triggered);
    connect(ui->actionopen, &QAction::triggered, this, &MainWindow::on_actionOpenFavorite_triggered);
    connect(ui->actionremove, &QAction::triggered, this, &MainWindow::on_actionRemoveFavorite_triggered);
    connect(ui->actionremoveall, &QAction::triggered, this, &MainWindow::on_actionClearFavorites_triggered);

    connect(ui->add, &QAction::triggered, this, &MainWindow::on_actionAdd_triggered);
    connect(ui->gotobookmark, &QAction::triggered, this, &MainWindow::on_actionGoTo_triggered);
    connect(ui->remove, &QAction::triggered, this, &MainWindow::on_actionRemove_triggered);
    connect(ui->removeall, &QAction::triggered, this, &MainWindow::on_actionRemoveAll_triggered);

    autosaveTimer = new QTimer(this);
    connect(autosaveTimer, &QTimer::timeout, this, &MainWindow::autosaveFiles);
    autosaveTimer->start(300000);
}

void MainWindow::on_actionSavetemp_triggered()
{
    CodeEditor *editor = qobject_cast<CodeEditor *>(tabWidget->currentWidget());
    if (editor) {
        QString filePath = QFileDialog::getSaveFileName(this, "Save File");
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QFile::WriteOnly | QFile::Text)) {
                QTextStream out(&file);
                out << editor->toPlainText();
                file.close();


                tabWidget->setTabText(tabWidget->currentIndex(), QFileInfo(filePath).fileName());


                QDir autosaveDir(QDir::tempPath() + "/temp_autosave");
                QFile::remove(autosaveDir.filePath("autosave_tab_" + QString::number(tabWidget->currentIndex()) + ".txt"));
            }
        }
    }
}

void MainWindow::recoverUnsavedFiles()
{
    QDir autosaveDir(QDir::tempPath() + "/temp_autosave");
    if (!autosaveDir.exists()) {
        return;
    }

    QStringList autosaveFiles = autosaveDir.entryList(QStringList() << "*.txt", QDir::Files);
    if (autosaveFiles.isEmpty()) {
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Recover Files",
        "There are unsaved files from the previous session. Do you want to recover them?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        for (const QString &fileName : autosaveFiles) {
            QFile file(autosaveDir.filePath(fileName));
            if (file.open(QFile::ReadOnly | QFile::Text)) {
                QTextStream in(&file);
                QString content = in.readAll();
                file.close();

                CodeEditor *editor = new CodeEditor();
                editor->setPlainText(content);

                QString recoveredTabName = fileName;
                recoveredTabName.replace("autosave_tab_", "Recovered Tab ");
                tabWidget->addTab(editor, recoveredTabName);
                tabWidget->setCurrentWidget(editor);
            }
        }
    }


    for (const QString &fileName : autosaveFiles) {
        QFile::remove(autosaveDir.filePath(fileName));
    }
}



void MainWindow::autosaveFiles()
{
    QDir autosaveDir(QDir::tempPath() + "/temp_autosave");
    if (!autosaveDir.exists()) {
        autosaveDir.mkpath(".");
    }

    for (int i = 0; i < tabWidget->count(); ++i) {
        CodeEditor *editor = qobject_cast<CodeEditor *>(tabWidget->widget(i));
        if (editor) {
            QString filePath = autosaveDir.filePath("autosave_tab_" + QString::number(i) + ".txt");
            QFile file(filePath);
            if (file.open(QFile::WriteOnly | QFile::Text)) {
                QTextStream out(&file);
                out << editor->toPlainText();
                file.close();
            }
        }
    }

    qDebug() << "Autosaved all open files.";
}


void MainWindow::on_actionAdd_triggered()
{

    CodeEditor *currentEditor = qobject_cast<CodeEditor *>(tabWidget->currentWidget());
    if (!currentEditor) {
        QMessageBox::warning(this, "错误", "没有窗口或行可以添加书签");
        return;
    }

    int currentLine = currentEditor->textCursor().blockNumber();
    if (bookmarks[currentEditor].contains(currentLine)) {
        QMessageBox::information(this, "添加", "这行已经是书签了");
    } else {
        bookmarks[currentEditor].insert(currentLine);
        QMessageBox::information(this, "添加", "添加书签成功在: " + QString::number(currentLine + 1));
    }
}

void MainWindow::on_actionGoTo_triggered()
{

    CodeEditor *currentEditor = qobject_cast<CodeEditor *>(tabWidget->currentWidget());
    if (!currentEditor) {
        QMessageBox::warning(this, "错误", "没有窗口或书签可以去往");
        return;
    }

    if (bookmarks[currentEditor].isEmpty()) {
        QMessageBox::information(this, "前往", "这个文件里没有书签");
        return;
    }


    QStringList bookmarkList;
    for (int line : bookmarks[currentEditor]) {
        bookmarkList.append("Line " + QString::number(line + 1));
    }


    QString selectedBookmark = QInputDialog::getItem(this, "去到",
                                                     "选择一个书签:",
                                                     bookmarkList, -1, false);
    if (selectedBookmark.isEmpty()) {

        return;
    }
    if (!selectedBookmark.isEmpty()) {
        int lineNumber = selectedBookmark.split(" ")[1].toInt() - 1;

        QTextCursor cursor = currentEditor->textCursor();
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, lineNumber);
        currentEditor->setTextCursor(cursor);
    }
}

void MainWindow::on_actionRemove_triggered()
{

    CodeEditor *currentEditor = qobject_cast<CodeEditor *>(tabWidget->currentWidget());
    if (!currentEditor) {
        QMessageBox::warning(this, "错误", "没有文件可以清除书签");
        return;
    }

    if (bookmarks[currentEditor].isEmpty()) {
        QMessageBox::information(this, "移除", "在这个文件里没有书签");
        return;
    }


    QStringList bookmarkList;
    for (int line : bookmarks[currentEditor]) {
        bookmarkList.append("Line " + QString::number(line + 1));
    }


    QString selectedBookmark = QInputDialog::getItem(this, "移除书签",
                                                     "选择一个书签移除:",
                                                     bookmarkList, -1, false);

    if (selectedBookmark.isEmpty()) {

        return;
    }


    int lineNumber = selectedBookmark.split(" ")[1].toInt() - 1;


    bookmarks[currentEditor].remove(lineNumber);


    QMessageBox::information(this, "Info", "移除书签在: " + QString::number(lineNumber + 1));
}



void MainWindow::on_actionRemoveAll_triggered()
{

    CodeEditor *currentEditor = qobject_cast<CodeEditor *>(tabWidget->currentWidget());
    if (!currentEditor) {
        QMessageBox::warning(this, "错误", "没有文件可以清除书签");
        return;
    }

    if (bookmarks[currentEditor].isEmpty()) {
        QMessageBox::information(this, "移除所有", "在这个文件里没有书签");
        return;
    }

    bookmarks[currentEditor].clear();
    QMessageBox::information(this, "移除所有", "成功清除所有书签");
}


void MainWindow::on_actionAddFavorite_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择一个文件添加进收藏夹");
    if (!filePath.isEmpty()) {
        if (favorites.contains(filePath)) {
            QMessageBox::information(this, "添加", "这个文件已经在收藏夹里了");
        } else {
            favorites.insert(filePath);
            qDebug() << "Added to favorites:" << filePath;
        }
    }
}

void MainWindow::on_actionRemoveFavorite_triggered()
{

    QStringList favoriteList = favorites.values();


    QString fileToRemove = QInputDialog::getItem(this, "移除收藏的文件",
                                                 "选择一个收藏去移除:",
                                                 favoriteList, -1, false);
    if (fileToRemove.isEmpty()) {
        return;
    }
    if (!fileToRemove.isEmpty()) {

        favorites.remove(fileToRemove);
        QMessageBox::information(this, "Favorite Removed", "成功移除: " + fileToRemove);
    }
}


void MainWindow::on_actionOpenFavorite_triggered()
{

    QStringList favoriteList = favorites.values();


    QString fileToOpen = QInputDialog::getItem(this, "打开收藏夹",
                                               "选择文件打开:",
                                               favoriteList, -1, false);

    if (fileToOpen.isEmpty()) {
        return;
    }
    if (!fileToOpen.isEmpty()) {
        QFile file(fileToOpen);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "错误", "无法打开文件: " + fileToOpen);
            return;
        }


        QTextStream in(&file);
        QString content = in.readAll();
        file.close();

        CodeEditor *editor = new CodeEditor();
        editor->setPlainText(content);

        tabWidget->addTab(editor, QFileInfo(fileToOpen).fileName());
        tabWidget->setCurrentWidget(editor);


        updateStatusBar(editor);
    }
}


void MainWindow::on_actionClearFavorites_triggered()
{
    if (!favorites.isEmpty()) {
        favorites.clear();
        QMessageBox::information(this, "Info", "成功清空收藏夹");
        qDebug() << "收藏夹已清空";
    } else {
        QMessageBox::warning(this, "Warning", "收藏夹已为空，无需清空");
        qDebug() << "尝试清空空的收藏夹";
    }
}


void MainWindow::initFavoriteMenu()
{

}


QString darkStyle = R"(
    QPlainTextEdit {
        background-color: #2e2e2e;
        color: white;
        font-family: Consolas, monospace;
        font-size: 12px;
    }
    QPlainTextEdit:focus {
        border: 2px solid #3498db;
    }
)";

QString lightStyle = R"(
    QPlainTextEdit {
        background-color: white;
        color: black;
        font-family: Consolas, monospace;
        font-size: 12px;
    }
    QPlainTextEdit:focus {
        border: 2px solid #3498db;
    }
)";


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg;
    dlg.exec();
}


void MainWindow::on_actionFind_triggered()
{
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (editor) {
        SearchDialog dlg(this, editor);
        dlg.exec();
    }
}



void MainWindow::on_actionReplace_triggered()
{
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (editor) {
        ReplaceDialog dlg(this, editor);
        dlg.exec();
    }
}


void MainWindow::on_actionNew_triggered()
{

    if (!userEditConfirmed()) {
        return;
    }
    filePath = "";
    textChanged = false;

    CodeEditor *editor = new CodeEditor();
    if (!editor) {
        qDebug() << "Failed to create a new editor!";
        return;
    }

    SyntaxHighlighter *highlighter = new SyntaxHighlighter(editor->document());

    editor->clear();

    tabWidget->addTab(editor, "无标题");

    tabWidget->setCurrentWidget(editor);

    connect(editor, &QPlainTextEdit::textChanged, this, &MainWindow::on_textEdit_textChanged);
    connect(editor, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::on_textEdit_cursorPositionChanged);

    this->setWindowTitle(tr("新建文本文件 - 编辑器"));
    updateStatusBar(editor);
}

void MainWindow::on_actionOpen_triggered()
{

    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text files (*.txt);;All files (*.*)"));
    if (filename.isEmpty()) {
        return;
    }

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Unable to open file"));
        return;
    }

    addToRecentFiles(filename);
    CodeEditor *editor = new CodeEditor();
    QTextStream in(&file);
    editor->setPlainText(in.readAll());

    new SyntaxHighlighter(editor->document());

    tabWidget->addTab(editor, QFileInfo(filename).fileName());
    tabWidget->setCurrentWidget(editor);

    filePath = filename;

    updateStatusBar(editor);

    connect(editor, &QPlainTextEdit::textChanged, this, &MainWindow::on_textEdit_textChanged);

    highlightBookmarks(editor);
}

void MainWindow::on_actionSave_triggered()
{

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (!editor) {
        return;
    }

    if (filePath.isEmpty()) {
        filePath = QFileDialog::getSaveFileName(this, tr("保存文件"), ".", tr("Text files (*.txt);;All files (*.*)"));
        if (filePath.isEmpty()) {
            return;
        }
    }

    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("保存失败"), tr("无法保存文件"));
        return;
    }

    QTextStream out(&file);
    out << editor->toPlainText();

    file.flush();
    file.close();

    setWindowTitle(QFileInfo(filePath).absoluteFilePath());
    textChanged = false;
}






void MainWindow::on_actionSaveAs_triggered()
{

    QString filename = QFileDialog::getSaveFileName(this, tr("保存文件"), ".", tr("Text files (*.txt);;All files (*.*)"));
    if (filename.isEmpty()) {
        return;
    }


    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (!editor) {
        return;
    }


    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("保存失败"), tr("无法保存文件"));
        return;
    }


    QTextStream out(&file);
    out << editor->toPlainText();


    file.flush();
    file.close();


    setWindowTitle(QFileInfo(filename).absoluteFilePath());


    textChanged = false;
}




void MainWindow::updateStatusBar(QPlainTextEdit *editor)
{
    if (!editor) {
        return;
    }


    QString text = editor->toPlainText();
    int length = text.length();
    int lines = text.isEmpty() ? 1 : text.count("\n") + 1;


    statusLabel.setText(tr("Length: %1  Lines: %2").arg(length).arg(lines));


    QTextCursor cursor = editor->textCursor();
    int line = cursor.blockNumber() + 1;
    int col = cursor.columnNumber() + 1;


    statusCursorLabel.setText(tr("Ln: %1  Col: %2").arg(line).arg(col));


    qDebug() << "Status updated: Length =" << length
             << ", Lines =" << lines
             << ", Ln =" << line
             << ", Col =" << col;
}



void MainWindow::on_textEdit_cursorPositionChanged()
{

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

    if (!editor) {
        qDebug() << "No active editor found in the current tab!";
        return;
    }


    updateStatusBar(editor);

    int cursorPosition = editor->textCursor().position();
    qDebug() << "Cursor position changed to:" << cursorPosition;
}



void MainWindow::on_textEdit_textChanged()
{

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

    if (!editor) {
        qDebug() << "No active editor found in the current tab!";
        return;
    }


    int textLength = editor->document()->characterCount();


    qDebug() << "Text content changed, current text length: " << textLength;


    updateStatusBar(editor);


    if (!windowTitle().endsWith("*")) {
        setWindowTitle(windowTitle() + " *");
    }
}



bool MainWindow::userEditConfirmed()
{

    if (textChanged) {

        QString path = filePath.isEmpty() ? "无标题.txt" : filePath;


        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowTitle("保存更改");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(QString("是否将更改保存到\n\"%1\"?").arg(path));
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);


        int response = msg.exec();
        switch (response) {
        case QMessageBox::Yes:
            on_actionSave_triggered();
            break;
        case QMessageBox::No:

            textChanged = false;
            break;
        case QMessageBox::Cancel:

            break;
        }
    }


    return true;
}




void MainWindow::on_tabWidget_currentChanged(int index)
{

    CodeEditor *editor = qobject_cast<CodeEditor*>(ui->tabWidget->currentWidget());


    if (editor) {

        editor->showLineNumberArea(true);

        updateBookmarkMenu(editor);
    }

}



void MainWindow::on_actionUndo_triggered()
{

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());


    if (editor) {
        editor->undo();
    }

}


void MainWindow::on_actionCut_triggered()
{

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());


    if (editor) {
        editor->cut();
        ui->actionPaste->setEnabled(true);
    }

}



void MainWindow::on_actionCopy_triggered()
{

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());


    if (editor) {
        editor->copy();
        ui->actionPaste->setEnabled(true);
    }

}



void MainWindow::on_actionPaste_triggered()
{
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (editor) {
        editor->paste();
    }
}



void MainWindow::on_actionRedo_triggered()
{
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (editor) {
        editor->redo();
    }
}


void MainWindow::on_textEdit_undoAvailable(bool b)
{
    ui->actionUndo->setEnabled(b);
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actionCopy->setEnabled(b);
    ui->actionCut->setEnabled(b);

}


void MainWindow::on_textEdit_redoAvailable(bool b)
{
    ui->actionRedo->setEnabled(b);
}





void MainWindow::on_actionFontBackgroundColor_triggered()
{

    QColor color = QColorDialog::getColor(Qt::white, this, "选择背景颜色");


    if (color.isValid()) {

        QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

        if (editor) {
            QTextCursor cursor = editor->textCursor();


            if (cursor.selectedText().isEmpty()) {
                cursor.select(QTextCursor::Document);
            }


            QTextCharFormat format;
            format.setBackground(color);


            cursor.mergeCharFormat(format);


            editor->setTextCursor(cursor);
        }
    }
}




void MainWindow::on_actionBackgroundColor_triggered()
{

    QColor color = QColorDialog::getColor(Qt::black, this, "选择背景颜色");


    if (color.isValid()) {
        QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

        if (editor) {
            QString style = QString("QPlainTextEdit {background-color:%1}").arg(color.name());
            editor->setStyleSheet(style);
        }
    }
}




void MainWindow::on_actionFontColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "选择字体颜色");
    if (color.isValid()) {
        QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

        if (editor) {
            QString style = QString("QPlainTextEdit {color:%1}").arg(color.name());
            editor->setStyleSheet(style);
        }
    }
}






void MainWindow::on_actionWrap_triggered()
{
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

    if (editor) {
        QPlainTextEdit::LineWrapMode currentMode = editor->lineWrapMode();
        if (currentMode == QPlainTextEdit::NoWrap) {
            editor->setLineWrapMode(QPlainTextEdit::WidgetWidth);
            ui->actionWrap->setChecked(true);
        } else {
            editor->setLineWrapMode(QPlainTextEdit::NoWrap);
            ui->actionWrap->setChecked(false);
        }
    }
}





void MainWindow::on_actionFont_triggered()
{
    bool fontSelected = false;
    QFont selectedFont = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected) {
        QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

        if (editor) {
            editor->setFont(selectedFont);
        }
    }
}




void MainWindow::on_actionToolbar_triggered()
{
    bool visible = ui->toolBar->isVisible();
    ui->toolBar->setVisible(!visible);
    ui->actionToolbar->setChecked(!visible);
}

void MainWindow::on_actionStatusBar_triggered()
{
    bool visible = ui->statusbar->isVisible();
    ui->statusbar->setVisible(!visible);
    ui->actionStatusBar->setChecked(!visible);
}

void MainWindow::on_actionSelectAll_triggered()
{
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (editor) {
        editor->selectAll();
    }
}


void MainWindow::on_action_Exit_triggered()
{
    if(userEditConfirmed()){
        exit(0);
    }
}




void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->widget(index));
    if (editor && textChanged) {
        QString path = filePath.isEmpty() ? "无标题.txt" : filePath;

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText(QString("是否将更改保存到\n") + "\"" + path + "\"?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        int userChoice = msgBox.exec();
        switch (userChoice) {
        case QMessageBox::Yes:
            on_actionSave_triggered();
            break;
        case QMessageBox::Cancel:
            return;
        default:
            break;
        }
    }


    tabWidget->removeTab(index);
}


void MainWindow::on_actionThemeToggle_triggered() {
    static bool isDarkMode = false;


    isDarkMode = !isDarkMode;


    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());
    if (editor) {

        editor->setStyleSheet(isDarkMode ? darkStyle : lightStyle);


        SyntaxHighlighter *highlighter = editor->findChild<SyntaxHighlighter*>();
        if (highlighter) {
            highlighter->setKeywordColor(isDarkMode ? Qt::cyan : Qt::blue);
        }
    }


    onTabChanged(tabWidget->currentIndex());
}


void MainWindow::onTabChanged(int index)
{

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(tabWidget->currentWidget());

    if (editor) {

        if (isDarkMode) {
            editor->setStyleSheet(darkStyle);
        } else {
            editor->setStyleSheet(lightStyle);
        }


        highlightBookmarks(editor);
    }
}


void MainWindow::on_actionDark_triggered() {
    isDarkMode = true;


    setStyleSheet(darkStyle);
    onTabChanged(tabWidget->currentIndex());
}


void MainWindow::on_actionLight_triggered() {
    isDarkMode = false;


    setStyleSheet(lightStyle);
    onTabChanged(tabWidget->currentIndex());
}

void MainWindow::addToRecentFiles(const QString &filePath)
{
    if (recentFiles.contains(filePath)) {
        return;
    }


    recentFiles.prepend(filePath);
    if (recentFiles.size() > maxRecentFiles) {
        recentFiles.removeLast();
    }

    updateRecentFilesMenu();
}


void MainWindow::updateRecentFilesMenu()
{
    QAction *clearHistoryAction = ui->recentFilesMenu->findChild<QAction *>("clearHistoryAction");
    if (!clearHistoryAction) {
        clearHistoryAction = new QAction("清除历史", this);
        clearHistoryAction->setObjectName("clearHistoryAction");
        connect(clearHistoryAction, &QAction::triggered, this, &MainWindow::on_actionClearHistory_triggered);
        ui->recentFilesMenu->addAction(clearHistoryAction);
    }
    qDeleteAll(ui->recentFilesMenu->actions());
    ui->recentFilesMenu->addAction(clearHistoryAction);

    for (const QString &file : recentFiles) {
        QAction *action = new QAction(file, this);
        connect(action, &QAction::triggered, this, &MainWindow::onRecentFileTriggered);
        ui->recentFilesMenu->addAction(action);
    }
}



void MainWindow::onRecentFileTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action) {
        QString filename = action->text();
        QFile file(filename);


        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Error", "Unable to open file");
            return;
        }


        CodeEditor *editor = new CodeEditor();
        QTextStream in(&file);
        QString text = in.readAll();
        editor->setPlainText(text);

        new SyntaxHighlighter(editor->document());

        tabWidget->addTab(editor, QFileInfo(filename).fileName());
        tabWidget->setCurrentWidget(editor);

        filePath = filename;
        updateStatusBar(editor);

        file.close();

        connect(editor, &QPlainTextEdit::textChanged, this, &MainWindow::on_textEdit_textChanged);
    }
}


void MainWindow::on_actionClearHistory_triggered()
{

    if (!recentFiles.isEmpty()) {
        recentFiles.clear();
        updateRecentFilesMenu();
        QMessageBox::information(this, "History Cleared", "Recent files history has been cleared.");
    }
    else {
        QMessageBox::information(this, "No History", "There are no recent files to clear.");
    }
}


void MainWindow::setupMenus()
{

}


void MainWindow::highlightBookmarks(QPlainTextEdit *editor)
{
}

void MainWindow::addBookmark()
{

    QList<CodeEditor*> editors = findChildren<CodeEditor*>();


    if (editors.isEmpty()) {
        return;
    }


    for (CodeEditor *editor : editors) {
        if (editor) {
            QTextCursor cursor = editor->textCursor();


            if (cursor.hasSelection()) {

                int line = cursor.blockNumber();
                editor->onBookmarkAdded(line);
            }
        }
    }
}


void MainWindow::updateBookmarkMenu(QPlainTextEdit *editor)
{

}




