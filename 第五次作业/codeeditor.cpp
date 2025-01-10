
#include "codeeditor.h"
#include <QPainter>
#include <QTextBlock>
#include <QPlainTextEdit>


CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{

    lineNumberArea = new LineNumberArea(this);
    highlighter = new SyntaxHighlighter(this->document());


    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::highlightCurrentLine);

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();

}


int CodeEditor::lineNumberAreaWidth()
{
    int digits = qMax(1, QString::number(blockCount()).length());
    return 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
}


void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy) {
        lineNumberArea->scroll(0, dy);
    }
    else {
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
    }

    if (rect.contains(viewport()->rect())) {
        updateLineNumberAreaWidth(0);
    }
}


void CodeEditor::showLineNumberArea(bool visible)
{
    if (visible) {
        lineNumberArea->show();
        setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
    }
    else {
        lineNumberArea->hide();
        setViewportMargins(0, 0, 0, 0);
    }
}


void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
    QRect contentRect = contentsRect();
    lineNumberArea->setGeometry(QRect(contentRect.left(), contentRect.top(), lineNumberAreaWidth(), contentRect.height()));
}


void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection currentLineSelection;
        currentLineSelection.format.setProperty(QTextFormat::FullWidthSelection, true);
        currentLineSelection.cursor = textCursor();
        currentLineSelection.cursor.clearSelection();
        extraSelections.append(currentLineSelection);
    }
    setExtraSelections(extraSelections);
}


void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + qRound(blockBoundingRect(block).height());
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void CodeEditor::mousePressEvent(QMouseEvent *event)
{
    QTextCursor cursor = cursorForPosition(event->pos());
    QString text = cursor.block().text();
    QRegularExpression linkRegex(R"((https?|ftp)://[^\s/$.?#].[^\s]*|mailto:[^\s@]+@[^\s@]+\.[^\s@]+)");
    QRegularExpressionMatch match = linkRegex.match(text);
    if (match.hasMatch()) {
        QDesktopServices::openUrl(QUrl(match.captured(0)));
    }

    highlightBookmarks();
    QPlainTextEdit::mousePressEvent(event);
}



void CodeEditor::highlightBookmarks()
{

}

void CodeEditor::onBookmarkAdded(int line)
{

}

void CodeEditor::onBookmarkRemoved(int line)
{

}

void CodeEditor::updateBookmarkMenu()
{

}




