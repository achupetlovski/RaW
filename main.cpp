#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //if(MainWindow.myBool=true) return a.exec();
    return a.exec();
}
