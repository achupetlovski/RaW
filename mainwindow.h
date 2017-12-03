#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "color.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void read(QString fileName);

public slots:
    void eventAutoColor();
    void eventAutoColor_new();
    void diseventAutoColor();

private slots:
    ///Basic functions
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionNew_File_triggered();
    void on_actionClose_triggered();

    ///Debugging functions
    void on_actionShow_triggered();
    void on_actionShow_current_triggered();
    void on_actionShow_Current_Tab_Index_triggered();

    ///Coloring functions
    void on_actionAuto_Coloring_toggled(bool arg1);
    void on_actionOptions_triggered();

private:
    Ui::MainWindow *ui;
    //QString Filename;
};

#endif // MAINWINDOW_H
