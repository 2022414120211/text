#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include "syntaxhighlighter.h"
#include <QDesktopServices>
#include <QUrl>
#include <QTextDocument>
#include <QTextCursor>

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = nullptr);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);

public slots:
    void showLineNumberArea(bool flag);


    void highlightBookmarks();
    void onBookmarkAdded(int line);
    void onBookmarkRemoved(int line);
    void updateBookmarkMenu();
private:
    QWidget *lineNumberArea;
    SyntaxHighlighter *highlighter;
    QMenu *bookmarkMenu;
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor)
    {}

    QSize sizeHint() const override
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;

};

#endif // CODEEDITOR_H
