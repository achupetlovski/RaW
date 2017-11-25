#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionNew_File_triggered();
    void on_actionClose_triggered();
    void on_actionShow_triggered();
    void on_actionShow_current_triggered();
    void on_actionShow_Current_Tab_Index_triggered();

private:
    Ui::MainWindow *ui;
    //QString Filename;
};

#endif // MAINWINDOW_H
