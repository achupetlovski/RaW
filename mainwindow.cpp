#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QTextStream>
#include <QTabWidget>

//This function gets the contents of a file and reads it all/puts it into a file stream
void MainWindow::read(QString Filename)
{
    //Creating new QFile object
    QFile mFile(Filename);

    //Check if file opens
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
            qDebug() << "Could not open file for reading.";
            return;
    }

    //If file does open, get contents to a stream
    QTextStream in(&mFile);

    //Get text stream contents to a QString
    QString mFileStream = in.readAll();

    //Debug in the QTconsole if you want to test
    //qDebug() << mFileStream;

    //Set the text in the editor to the QString above
    ui->mTextEdit->setPlainText(mFileStream);

    //Filename here returns the full path to the file including the file name
    qDebug()<<Filename;

    //Flush is not needed really as we don't write to the file
    mFile.flush();

    //Closing the file after we're done naturally
    mFile.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Setting the mTextEdit object as the main one, i.e. take all the space available
    setCentralWidget(ui->mTextEdit);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName;

    // Here we get the path/filename in the QString variable fileName
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), "/home/mike/qt/mini-projects/read-and-write-file/", tr("Lua Files (*.lua)"));

    //If filename is not empty, i.e. nothing, send it to the read function for opening
    //maybe this will need to be changed over time
    if(fileName!="")
    {
        Filename = fileName;
        read(fileName);
    }
}

void MainWindow::on_actionSave_triggered()
{
    //QTextStream out;

    //QString text = ui->mTextEdit->toPlainText();

    QString text = ui->mTextEdit->toPlainText();

    QFile mFile(Filename);
    //writeonly = locking the file
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
            qDebug() << "Could not open file for writing.";
            return;
    }

    QTextStream out(&mFile);
    out << text;

    mFile.flush();
    mFile.close();

    //qDebug()<<Filename;
    //qDebug()<< Filename;
    //qDebug()<<text;
}
