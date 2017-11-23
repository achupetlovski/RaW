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
    void read(QString Filename);
private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionNew_File_triggered();
    void on_actionClose_triggered();

private:
    Ui::MainWindow *ui;
    QString Filename;
    //Boolean myBool=false;
    //QString Filenames[];
};

#endif // MAINWINDOW_H
