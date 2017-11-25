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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mTabWidget);

    //myTabPage *mNewTab = new myTabPage;
    ui->mTabWidget ->removeTab(0);
    //ui->mTabWidget ->addTab(mNewTab, tr("New tab"));
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
/*
void MainWindow::on_tabWidget_tabBarClicked()
{
    ui->label->setText(QString::number(ui->mTabWidget->currentIndex()));
    ui->label->show();
}
*/
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



    //ui->statusBar->
    //QString statusString = "File " + Filename + " opened.";
    //statusBar()->showMessage(statusString);
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

    ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setPlainText(mFileString);

    ///
    ///
    ///     Keeping the code(gibberish) below for now to remind me of my peak stupidity.
    ///
    ///

    //Debug in the QTconsole if you want to test
    //qDebug() << "mFileStream before parse:" + mFileStream;

    //Set the text in the editor to the QString above
    ///ui->mTextEdit->setPlainText(mFileStream);

    ////////mTabWidget:myTabPage().setTabText(mFileStream);

    /*
     *
     *       QTextEdit *asd = new QTextEdit;
     *       asd = ui->mTabWidget->findChild<QTextEdit*>("mTextEdit");
     *       asd->setPlainText(mFileStream);
     *
     */

    /*
    QTextEdit *asd = new QTextEdit;
    asd = ui->mTabWidget->findChild<QTextEdit*>("mTextEdit");
    asd->setPlainText(mFileStream);
    */

    //QList *newList = new QList;
    //newList = ui->mTabWidget->findChildren<QTextEdit*>("mTextEdit");
/*
    qDebug() << "My Widgets list on the tab:";
    qDebug() << ui->mTabWidget->findChildren<QTextEdit*>("mTextEdit");
*/
/*
    qDebug() << "My Widgets list on the current tab:";
    qDebug() << ui->mTabWidget->widget(ui->mTabWidget->currentIndex());
*/

    //myTabPage *newTaby = new myTabPage;
    //newTaby = ui->mTabWidget->findChild<myTabPage*>("myTabPage");
    //QString aaag = QString::number(ui->mTabWidget->currentIndex());
    //newTaby->setTabText(aaag);

    //QList *newTabyList = new QList;
    //newTabyList = ui->mTabWidget->findChildren<myTabPage*>("myTabPage");

    //qDebug() << "My newTaby:";
    //qDebug() << newTaby;// qDebug() << aaag;

    //QTextEdit *newTextEdit = new QTextEdit;
    //newTextEdit = newTaby->findChild<QTextEdit*>("mTextEdit");

    //qDebug() << "newTaby newTextEdit child under tab index ";
    //qDebug() << ui->mTabWidget->currentIndex();
    //qDebug() << "is:";
    //qDebug() << newTextEdit;

    //newTextEdit->setPlainText(mFileStream);

    //qDebug()<< "Have set text:" + newTextEdit->toPlainText() + "\nto newTextEdit on tab number:" + newTextEdit->objectName();

    //outputs index of the tab you're on
    //qDebug()<< "Tab selected:"; qDebug()<< ui->mTabWidget->currentIndex();

    //mTabWidget->ui->myTabPage::myFoo(mFileStream);

    //myTabPage::myFoo(mFileStream);

    //ui->mTextEdit->setText("random text");

    //Filename here returns the full path to the file including the file name
    //qDebug()<<Filename;

    //Flush is not needed really as we don't write to the file
    //mFile.flush();

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

    //Getting the text from the text box mTestEdit
    out << ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

    //Getting the text from the text box mTestEdit
    //QString text = ui->mTextEdit->toPlainText();

    //Writing to file
    //out << text;

    //Flushing after use
    mFile.flush();

    //Closing the file
    mFile.close();

    QString statusString = "File " + fileName + " saved.";
    statusBar()->showMessage(statusString);
    }
    else //qDebug()<< "gg";
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

    qDebug()<< "Showing current Access Name";
    qDebug()<< ui->mTabWidget->currentWidget()->accessibleName();
}

void MainWindow::on_actionShow_current_triggered()
{
    ///
    ///     DEBUG PART
    ///

    qDebug() << "\n\nCURRENT TAB LOG:\nui->mTabWidget->currentIndex(); IS:";
    qDebug() << ui->mTabWidget->currentIndex();

    qDebug() << "\nui->mTabWidget->currentWidget() IS:";
    qDebug() << ui->mTabWidget->currentWidget();

    qDebug() << "\nui->mTabWidget->currentWidget()->children() IS:";
    qDebug()<<ui->mTabWidget->currentWidget()->children();

}

void MainWindow::on_actionShow_Current_Tab_Index_triggered()
{
    ///
    ///     DEBUG PART
    ///

    qDebug()<< "Current tab index:";
    qDebug()<< ui->mTabWidget->currentIndex();

}

