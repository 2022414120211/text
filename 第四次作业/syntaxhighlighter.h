#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QColor>
#include <QString>
#include <QTextCharFormat>
#include <QRegularExpression>

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit SyntaxHighlighter(QTextDocument *document);

    void setKeywordColor(const QColor &color);

protected:
    void highlightBlock(const QString &text) override;

private:
    QTextCharFormat keywordFormat;
    QTextCharFormat commentFormat;
    QTextCharFormat stringFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat linkFormat;

    QStringList keywordPatterns;

    void initKeywordPatterns();
};

#endif // SYNTAXHIGHLIGHTER_H
