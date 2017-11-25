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
    //ui->mTabTextEdit->setWindowState(Qt::WindowMaximized);

    //QGridLayout *layout = new QGridLayout;
    //layout->addWidget(ui->mTextEdit);
    //ui->setLayout(layout);



    /*
    QHBoxLayout* layout = new QHBoxLayout;
    //layout->setMargin(3);
    layout->addWidget(ui->mTextEdit);



    QWidget main;
    main.setLayout(layout);
    main.show();
    */

    //ui->mTextEdit->setLayout(layout);

    //ui->mTextEdit->resize(ui->mTextEdit->document()->size().width(),ui->mTextEdit->document()->size().height());
    /*
    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(ui->mTextEdit);

    window->setLayout(layout);
    window->show();
*/
    //setCentralWidget(ui->mTabTextEdit);

    //ui->mTextEdit->setPlainText("mFileStream");

    //MainWindow().ui->mTabTextEdit->setPlainText(mFileStream);
    //Ui::MainWindow().ui->mTabTextEditsetPlainText("mFileStream");
    //ui->mTabTextEdit->setPlainText("Text");
    //ui->mTabTextEdit->setPlainText("asdasdas");
    //MainWindow().mTabTextEdit->setPlainText("mFileStream");

    //ui->mPlainTextEdit->setPlainText("some text1");

}

myTabPage::~myTabPage()
{
    delete ui;
}


