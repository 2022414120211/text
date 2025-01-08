#include "replacedialog.h"
#include "ui_replacedialog.h"
#include <QMessageBox>

ReplaceDialog::ReplaceDialog(QWidget *parent,QPlainTextEdit * textEdit) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    pTextEdit=textEdit;
    ui->rbDown->setChecked(true);
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::on_btCancel_clicked()
{
    accept();
}


void ReplaceDialog::on_btFindNext_clicked()
{
    QString target = ui->searchText->text();
    if (target.isEmpty() || pTextEdit == nullptr) {
        return;
    }

    QString text = pTextEdit->toPlainText();
    QTextCursor cursor = pTextEdit->textCursor();


    Qt::CaseSensitivity caseSensitivity = ui->cbCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    int index = -1;
    if (ui->rbDown->isChecked()) {

        index = text.indexOf(target, cursor.position(), caseSensitivity);
    } else if (ui->rbUp->isChecked()) {

        index = text.lastIndexOf(target, cursor.position() - text.length() - 1, caseSensitivity);
    }

    if (index >= 0) {
        cursor.setPosition(index);
        cursor.setPosition(index + target.length(), QTextCursor::KeepAnchor);
        pTextEdit->setTextCursor(cursor);
    } else {

        QMessageBox::information(this, "记事本", QString("找不到") + "  " + target, QMessageBox::Ok);
    }
}



void ReplaceDialog::on_btReplace_clicked()
{
    QString target = ui->searchText->text();
    QString to = ui->targetText->text();


    if (pTextEdit && !target.isEmpty() && !to.isEmpty()) {
        QString selText = pTextEdit->textCursor().selectedText();


        if (selText == target) {
            pTextEdit->textCursor().insertText(to);
        }
    }
}


void ReplaceDialog::on_btReplaceAll_clicked()
{
    QString target = ui->searchText->text();
    QString to = ui->targetText->text();


    if (pTextEdit && !target.isEmpty() && !to.isEmpty()) {
        QString text = pTextEdit->toPlainText();


        Qt::CaseSensitivity caseSensitivity = ui->cbCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
        text.replace(target, to, caseSensitivity);


        pTextEdit->setPlainText(text);
    }
}



