#include "mytabpage.h"
#include "ui_mytabpage.h"
//#include "mainwindow.h"
#include <QDebug>


#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QTextStream>
#include <QTabWidget>
#include <QHBoxLayout>

myTabPage::myTabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTabPage)
{
    ui->setupUi(this);


}

myTabPage::~myTabPage()
{
    delete ui;
}
