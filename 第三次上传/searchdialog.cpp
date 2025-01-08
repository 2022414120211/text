#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "QMessageBox"

SearchDialog::SearchDialog(QWidget *parent,QPlainTextEdit *textEdit) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    pTextEdit=textEdit;
    ui->rbDown->setChecked(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_btFindNext_clicked()
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



void SearchDialog::on_btCancel_clicked()
{
    accept();
}

