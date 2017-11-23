#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytabpage.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QTextStream>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mTabWidget);
    //setCentralWidget(ui->mTextEdit);


    //myTabPage *mNewTab = new myTabPage;
    ui->mTabWidget ->removeTab(0);
    //ui->mTabWidget ->addTab(mNewTab, tr("New tab"));
    ui->mTabWidget->insertTab(1,new myTabPage(),QIcon(QString("")),"New Tab");

    //myNewTab->functionDeclaredInMyTabPage(); //access parameters of myNewTab



    //Setting the mTextEdit object as the main one, i.e. take all the space available
    //setCentralWidget(ui->mTextEdit);


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



    //ui->statusBar->
    //QString statusString = "File " + Filename + " opened.";
    //statusBar()->showMessage(statusString);
}

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
    qDebug() << "mFileStream before parse:" + mFileStream;

    //Set the text in the editor to the QString above
    ///ui->mTextEdit->setPlainText(mFileStream);

    mTabWidget:myTabPage().setTabText(mFileStream);

    //Filename here returns the full path to the file including the file name
    //qDebug()<<Filename;

    //Flush is not needed really as we don't write to the file
    mFile.flush();

    //Closing the file after we're done naturally
    mFile.close();
}

void MainWindow::on_actionSave_triggered()
{
    //Opening file, ready for writing
    QFile mFile(Filename);

    //writeonly = locking the file
    //Check if file opens, if not, abort mission
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
            qDebug() << "Could not open file for writing.";
            return;
    }

    //TextStream of the file
    QTextStream out(&mFile);

    //Getting the text from the text box mTestEdit
    QString text = ui->mTextEdit->toPlainText();

    //Writing to file
    out << text;

    //Flushing after use
    mFile.flush();

    //Closing the file
    mFile.close();

    QString statusString = "File " + Filename + " saved.";
    statusBar()->showMessage(statusString);
}

void MainWindow::on_actionNew_File_triggered()
{
    ui->mTabWidget->insertTab(1,new myTabPage(),QIcon(QString("")),"New Tab");

    //int tab_index = ui->mTabWidget->currentIndex();
    //ui->mTabWidget->setTabText(tab_index, Filename);
}

void MainWindow::on_actionClose_triggered()
{
    int tab_index = ui->mTabWidget->currentIndex();

    int tab_count = ui->mTabWidget->count();
    //qDebug() << tab_count;

    if(tab_count!=0)
    {
        ui->mTabWidget->removeTab(tab_index);
    }
    else
    {
        qDebug()<<"Closing app";
        QApplication::quit();
        //myBool=true;
    }
}
