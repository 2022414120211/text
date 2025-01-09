#include "syntaxhighlighter.h"


SyntaxHighlighter::SyntaxHighlighter(QTextDocument *document)
    : QSyntaxHighlighter(document)
{
    initKeywordPatterns();


    keywordFormat.setForeground(Qt::darkBlue);
    commentFormat.setForeground(QColor(34, 139, 34));
    stringFormat.setForeground(QColor(255, 69, 0));
    numberFormat.setForeground(QColor(148, 0, 211));
    linkFormat.setForeground(QColor(0, 139, 139));
}


void SyntaxHighlighter::initKeywordPatterns()
{
    QStringList keywords = { "\\bif\\b", "\\belse\\b", "\\bwhile\\b",
                            "\\bfor\\b", "\\breturn\\b", "\\bint\\b",
                            "\\bfloat\\b", "\\bdouble\\b", "\\bchar\\b" };

    keywordPatterns.append(keywords);
}

void SyntaxHighlighter::setKeywordColor(const QColor &color)
{
    keywordFormat.setForeground(color);
}


void SyntaxHighlighter::highlightBlock(const QString &text)
{

    foreach (const QString &pattern, keywordPatterns) {
        QRegularExpression regex(pattern);
        QRegularExpressionMatchIterator matchIterator = regex.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), keywordFormat);
        }
    }


    {
        QRegularExpression commentRegex("//[^\n]*");
        QRegularExpressionMatchIterator commentIterator = commentRegex.globalMatch(text);
        while (commentIterator.hasNext()) {
            QRegularExpressionMatch match = commentIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), commentFormat);
        }
    }


    {
        QRegularExpression stringRegex("\".*\"");
        QRegularExpressionMatchIterator stringIterator = stringRegex.globalMatch(text);
        while (stringIterator.hasNext()) {
            QRegularExpressionMatch match = stringIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), stringFormat);
        }
    }


    {
        QRegularExpression numberRegex("\\b[0-9]+\\b");
        QRegularExpressionMatchIterator numberIterator = numberRegex.globalMatch(text);
        while (numberIterator.hasNext()) {
            QRegularExpressionMatch match = numberIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), numberFormat);
        }
    }


    {
        QRegularExpression linkRegex(R"((https?|ftp)://[\S]+)");
        QRegularExpressionMatchIterator linkIterator = linkRegex.globalMatch(text);
        QTextCharFormat linkFormat;
        linkFormat.setForeground(Qt::blue);
        linkFormat.setFontUnderline(true);
        linkFormat.setUnderlineColor(Qt::blue);

        while (linkIterator.hasNext()) {
            QRegularExpressionMatch match = linkIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), linkFormat);
        }
    }
}
