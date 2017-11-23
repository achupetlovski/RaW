#include "mytabpage.h"
#include "ui_mytabpage.h"
#include "mainwindow.h"
#include <QDebug>

myTabPage::myTabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTabPage)
{
    ui->setupUi(this);
    //setCentralWidget(ui->mTabTextEdit);

    //ui->mTabTextEdit->setPlainText(mFileStream);

    //MainWindow().ui->mTabTextEdit->setPlainText(mFileStream);
    //Ui::MainWindow().ui->mTabTextEditsetPlainText("mFileStream");
    //ui->mTabTextEdit->setPlainText("Text");
    //ui->mTabTextEdit->setPlainText("asdasdas");
    //MainWindow().mTabTextEdit->setPlainText("mFileStream");
}

myTabPage::~myTabPage()
{
    delete ui;
}

void myTabPage::setTabText(QString &mFileStream)
{
    qDebug()<<"Made it this far...\n" + mFileStream;
    ui->mTabTextEdit->setPlainText(mFileStream);

    //ui->mTabTextEdit->setPlainText("some text");
    ui->mTabTextEdit->setText("some text");

    QString text = ui->mTabTextEdit->toPlainText();
    qDebug()<<"Contents of text box:\n" + text;
}
