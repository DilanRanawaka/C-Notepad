#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <finder.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionHelp_triggered();

    void on_actionAlign_Left_triggered();

    void on_actionAlign_Right_triggered();

    void on_actionCenter_triggered();

    void on_actionJustify_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionDate_Time_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionClear_triggered();

    void on_actionExit_triggered();

    void on_actionFind_triggered();

private:
    Ui::Notepad *ui;
    QString filePath; //!filePath variable initialize as a String variable
    Finder *finder; //!Initialize Finder
};
#endif // NOTEPAD_H
