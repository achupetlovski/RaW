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
#include <QGridLayout>
#include <QTime>
#include <QTimer>
#include "color.h"

#include "options.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mTabWidget);

    ui->mTabWidget ->removeTab(0);
    ui->mTabWidget->insertTab(1,new myTabPage(),QIcon(QString("")),"New Tab");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"));
    ui->mTabWidget->currentWidget()->setLayout(layout);
    ui->mTabWidget->currentWidget()->show();
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
        tr("Open file"), "/home/mike/qt/mini-projects/read-and-write-file/", tr("All Files (*.*)"));

    //If filename is not empty, i.e. nothing, send it to the read function for opening
    //maybe this will need to be changed over time
    if(fileName!="")
    {
        ///
        ///     DEBUG PART
        ///
        /*
        qDebug()<<"\n\nOPEN FILE DEBUG:";
        qDebug()<<"\nMy Filename is:";
        qDebug()<<fileName;
        */

        ui->mTabWidget->currentWidget()->setAccessibleName(fileName);

        ///
        ///     DEBUG PART
        ///
        /*
        qDebug()<<"\nFor ui->mTabWidget->currentWidget():";
        qDebug()<<ui->mTabWidget->currentWidget();
        qDebug()<<"\nEchoing AccessibleName is:";
        qDebug()<<ui->mTabWidget->currentWidget()->accessibleName();
        */

        MainWindow::read(fileName);
    }
}

//This function gets the contents of a file and reads it all/puts it into a file stream
void MainWindow::read(QString fileName)
{
    //Creating new QFile object
    QFile mFile(fileName);

    //Check if file opens
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
            qDebug() << "Could not open file for reading.";
            return;
    }

    //If file does open, get contents to a stream
    QTextStream in(&mFile);

    //Get text stream contents to a QString
    QString mFileString = in.readAll();

    ///
    ///     DEBUG PART
    ///
    /*
    qDebug() << "\n\nREAD LOG:\nui->mTabWidget->currentIndex(); IS:";
    qDebug() << ui->mTabWidget->currentIndex();

    qDebug() << "\nui->mTabWidget->currentWidget() IS:";
    qDebug() << ui->mTabWidget->currentWidget();

    qDebug() << "\nui->mTabWidget->currentWidget()->children() IS:";
    qDebug()<<ui->mTabWidget->currentWidget()->children();

    qDebug() << "\nSetting text to mTextEdit...";
    */
    ///

    ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setPlainText(mFileString);

    //Closing the file after we're done naturally
    mFile.close();
}

void MainWindow::on_actionSave_triggered()
{
    //QBool myBool = true;
    if(!ui->mTabWidget->currentWidget()->accessibleName().isNull())
    {
    QString fileName = ui->mTabWidget->currentWidget()->accessibleName();

    ///
    ///     DEBUG PART
    ///
    /*
    qDebug()<<"\n\nSAVE FILE DEBUG:";
    qDebug()<<"\nSave will use this fileName:";
    qDebug()<<fileName;
    */
    ///

    //Opening file, ready for writing
    QFile mFile(fileName);

    //writeonly = locking the file
    //Check if file opens, if not, abort mission
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
            qDebug() << "Could not open file for writing.";
            return;
    }

    //TextStream of the file
    QTextStream out(&mFile);

    ///
    ///     DEBUG PART
    ///
    /*
    qDebug() << "\n\nSAVE LOG:\nui->mTabWidget->currentIndex(); IS:";
    qDebug() << ui->mTabWidget->currentIndex();

    qDebug() << "\nui->mTabWidget->currentWidget() IS:";
    qDebug() << ui->mTabWidget->currentWidget();

    qDebug() << "\nui->mTabWidget->currentWidget()->children() IS:";
    qDebug()<<ui->mTabWidget->currentWidget()->children();

    qDebug() << "\nSaving text from mTextEdit to the file opened";
    */
    ///

    //Getting the text from the text box mTestEdit
    out << ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

    //Flushing after use
    mFile.flush();

    //Closing the file
    mFile.close();

    QString statusString = "File " + fileName + " saved.";
    statusBar()->showMessage(statusString);
    }
    else
    {
        QString fileName = QFileDialog::getSaveFileName(this, "Save As", "");

        QFile mFile(fileName);

        if(!mFile.open(QFile::WriteOnly | QFile::Text))
        {
                qDebug() << "Could not open file for writing.";
                return;
        }

        ui->mTabWidget->currentWidget()->setAccessibleName(fileName);

        //TextStream of the file
        QTextStream out(&mFile);

        out << ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

        mFile.flush();

        mFile.close();
    }
}

void MainWindow::on_actionNew_File_triggered()
{
    int tabIndex = ui->mTabWidget->currentIndex();
    int totalTabs = ui->mTabWidget->count();

    ui->mTabWidget->insertTab(ui->mTabWidget->currentIndex()+1,new myTabPage(),QIcon(QString("")),"New Tab");
    tabIndex++;

    ui->mTabWidget->setCurrentIndex(totalTabs);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"));
    ui->mTabWidget->currentWidget()->setLayout(layout);
    ui->mTabWidget->currentWidget()->show();

    ///
    ///     DEBUG PART
    ///
    /*
    qDebug() << "\n\nNEW TAB LOG:";
    qDebug() << "\nui->mTabWidget->currentIndex(); IS:";
    qDebug() << ui->mTabWidget->currentIndex();

    qDebug() << "\nui->mTabWidget->currentWidget() IS:";
    qDebug() << ui->mTabWidget->currentWidget();

    qDebug() << "\nui->mTabWidget->currentWidget()->children() IS:";
    qDebug()<<ui->mTabWidget->currentWidget()->children();

    qDebug() << "\n\nNEW TAB LOG:";
    qDebug() << "\nui->mTabWidget->currentIndex(); IS:";
    qDebug() << ui->mTabWidget->currentIndex();
    */
    ///
}

void MainWindow::on_actionClose_triggered()
{
    int tab_index = ui->mTabWidget->currentIndex();

    int tab_count = ui->mTabWidget->count();

    if(tab_count!=0)
    {
        ///
        ///     DEBUG PART
        ///
        /*
        qDebug() << "\n\nCLOSE LOG:\nui->mTabWidget->currentIndex(); IS:";
        qDebug() << ui->mTabWidget->currentIndex();

        qDebug() << "\nui->mTabWidget->currentWidget() IS:";
        qDebug() << ui->mTabWidget->currentWidget();

        qDebug() << "\nui->mTabWidget->currentWidget()->children() IS:";
        qDebug()<<ui->mTabWidget->currentWidget()->children();

        //QWidget *tmp = ui->mTabWidget->currentWidget();
        //QObjectList *tmp = new QObjectList();

        qDebug()<< "\nui->mTabWidget->currentWidget()->findChild<QTextEdit*>(\"mTextEdit\") IS:";
        */
        ///

        delete ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit");

        ///
        ///     DEBUG PART
        ///
        /*
        if(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"))
        {
            qDebug() << "Destroyed";
            qDebug() << "Here's what's left:";
            //qDebug() << tmp;
        }
        else
        {
            qDebug() << "Not Destroyed";
            qDebug() << "Here's what's left:";
            qDebug() << ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit");
        }
        */
        ///

        ui->mTabWidget->removeTab(tab_index);
    }
    else
    {
        ///
        ///     DEBUG PART
        ///
        /*
        qDebug()<<"\n\n\nEXITING PROGRAM";
        */
        ///

        QApplication::quit();
    }
}

void MainWindow::on_actionShow_triggered()
{
    ///
    ///     DEBUG PART
    ///
    //qDebug()<< "List of all mTextEdits:";
    //qDebug()<< ui->mTabWidget->findChildren<QTextEdit*>("mTextEdit");
    //qDebug()<< "Showing current Access Name";
    //qDebug()<< ui->mTabWidget->currentWidget()->accessibleName();
    //qDebug() << "\nEchoing retrunString:";
    //qDebug() << ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();
    ///

    QString myStr = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();
    //MainWindow::doFoo(/*myStr*/);

}

void MainWindow::on_actionShow_current_triggered()
{
    ///
    ///     DEBUG PART
    ///
    /*
    qDebug() << "\n\nCURRENT TAB LOG:\nui->mTabWidget->currentIndex(); IS:";
    qDebug() << ui->mTabWidget->currentIndex();

    qDebug() << "\nui->mTabWidget->currentWidget() IS:";
    qDebug() << ui->mTabWidget->currentWidget();

    qDebug() << "\nui->mTabWidget->currentWidget()->children() IS:";
    qDebug()<<ui->mTabWidget->currentWidget()->children();
    */
    ///
}

void MainWindow::on_actionShow_Current_Tab_Index_triggered()
{
    ///
    ///     DEBUG PART
    ///

    //qDebug()<< "Current tab index:";
    //qDebug()<< ui->mTabWidget->currentIndex();
    ///
}

void MainWindow::on_actionAuto_Coloring_toggled(bool arg1)
{
    if(arg1)
    {
        MainWindow::eventAutoColor();
        connect(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"), SIGNAL(textChanged()), this, SLOT(eventAutoColor_new()));
    }
    if(!arg1)
    {
        //MainWindow::diseventAutoColor();
        disconnect(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"), SIGNAL(textChanged()), this, SLOT(eventAutoColor_new()));
    }
}


void MainWindow::on_actionOptions_triggered()
{
    //qDebug()<<"\nOptions menu opened";

    QWidget *myOptions = new options;
    //myOptions->



    myOptions->show();
}
