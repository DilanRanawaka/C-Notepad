#include "finder.h"
#include "ui_finder.h"
#include "notepad.h"

#include <QFile>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>

#include <QVBoxLayout>

QString abc ;

Finder::Finder(QWidget *parent,const QString word) :
    QMainWindow(parent),
    ui (new Ui::Finder),word(word)
{
    ui->setupUi(this);
    abc = word; //!Assigning word variable into abc String variable
}

Finder::~Finder()
{
    delete ui;
}

//!Backward text finder click method
void Finder::on_pushButton_clicked()
{
    if (ui->textEdit->toPlainText().isEmpty()) {
        ui->textEdit->setText(abc);
    }

    ui->textEdit->find(ui->lineEdit->text());

}

//!Forward text finder click method
void Finder::on_pushButton_2_clicked()
{
    if (ui->textEdit->toPlainText().isEmpty()) {
            ui->textEdit->setText(abc);
        }

    ui->textEdit->find(ui->lineEdit->text(),QTextDocument::FindBackward);
}

