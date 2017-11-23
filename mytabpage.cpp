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

myTabPage::myTabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTabPage)
{
    ui->setupUi(this);
    //ui->mTabTextEdit->setWindowState(Qt::WindowMaximized);



    //setCentralWidget(ui->mTabTextEdit);

    //ui->mTabTextEdit->setPlainText(mFileStream);

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

void myTabPage::setTabText(QString &mFileStream)
{
    qDebug()<<"Made it this far...\n" + mFileStream;
    ui->mTextEdit->setPlainText(mFileStream);

    //ui->mTabTextEdit->setPlainText("some text");
    //ui->mPlainTextEdit->setPlainText("some text");

    QString text = ui->mTextEdit->toPlainText();
    qDebug()<<"Contents of text box:\n" + text;
}

