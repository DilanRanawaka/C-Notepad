#include "notepad.h"
#include "ui_notepad.h"
#include "finder.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QDate>
#include <QTime>

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget (ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}

//!New file action method
void Notepad::on_actionNew_triggered()
{
    filePath = "";
    ui->textEdit->setText("");
}

//!Open file action method
void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"!","File not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

//!Save file action method
void Notepad::on_actionSave_triggered()
{
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"!","File not save");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

//!Save As file action method
void Notepad::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save the file");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"!","File not save");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

//!Copy text action method
void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

//!Cut text action method
void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

//!Paste text action method
void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

//!Clear text action method
void Notepad::on_actionClear_triggered()
{
    ui->textEdit->clear();
}

//!Undo action method
void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

//!Redo action method
void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

//!About window action method
void Notepad::on_actionAbout_triggered()
{
    QString aboutText;
    aboutText = "Yasas Ranawaka\n";
    aboutText += "University of Plymouth, UK.\n";
    aboutText += "(c) Notepad 2022\n";
    QMessageBox::about(this,"About Notepad",aboutText);
}

//!Help window action method
void Notepad::on_actionHelp_triggered()
{
    QMessageBox::about(this, tr("Help"), tr("Notepad is a simple text editor software program.\n"
                                             "\nText can Save and Save-As.\n"
                                             "\nText can Copy, Cut, Paste and Clear.\n"
                                             "\nFont style supports bold, italic, and underlined font styles, and multicolored text.\n"
                                             "\nParagraphs can format into left-aligned, right-aligned, centered, and justified.\n"
                                             "\nFind word in the text using Text Finder.\n"
                                             "\nZoom-In text and Zoom-Out text\n"

                         ));
}

//!Text Align-Left action method
void Notepad::on_actionAlign_Left_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

//!Text Align-Right action method
void Notepad::on_actionAlign_Right_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

//!Text Center action method
void Notepad::on_actionCenter_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

//!Text Justify action method
void Notepad::on_actionJustify_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignJustify);
}

//!Zoom In action method
void Notepad::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn(2);
}

//!Zoom Out action method
void Notepad::on_actionZoom_Out_triggered()
{
    ui->textEdit->zoomOut(2);
}

//!Date and Time action method
void Notepad::on_actionDate_Time_triggered()
{
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    ui->textEdit->setText(cd.toString() +" "+ ct.toString());
}

//!Font window action method
void Notepad::on_actionFont_triggered()
{
    bool fontSelected;
           QFont font = QFontDialog::getFont(&fontSelected, this);
           if (fontSelected)
               ui->textEdit->setFont(font);
}

//!Font-color window action method
void Notepad::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this );
          if( color.isValid() )
          {
             ui->textEdit->setTextColor(color.name());//!Assigning the selected color into text
          }
}

//!Text finder window action method
void Notepad::on_actionFind_triggered()
{
    QString word = ui->textEdit->toPlainText();
    finder = new Finder(this,word);
    finder->show();
}

//!Window close/exit action method
void Notepad::on_actionExit_triggered()
{
    this->close();
}

