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
    //setCentralWidget(ui->mTabWidget);


    //setCentralWidget(ui->mTextEdit);


    //myTabPage *mNewTab = new myTabPage;
    ui->mTabWidget ->removeTab(0);
    //ui->mTabWidget ->addTab(mNewTab, tr("New tab"));
    ui->mTabWidget->insertTab(1,new myTabPage(),QIcon(QString("")),"New Tab");

    //myNewTab->functionDeclaredInMyTabPage(); //access parameters of myNewTab

    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
    //        ui->progressBar_2,SLOT(setValue(int)));

    //connect(ui->mTabWidget, SIGNAL(tabBarClicked(int)),
           // ui->label,SLOT(setValue(ui->mTabWidget->currentIndex())));

    //Setting the mTextEdit object as the main one, i.e. take all the space available
    //setCentralWidget(ui->mTextEdit);


    // connect(ui->mTabWidget, SIGNAL(currentChanged(int)), ui->label, SLOT(setText(int)));


    //ui->label->setText(QString::number(ui->mTabWidget->currentIndex()));
    //ui->label->show();
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

    myTabPage *newTaby = new myTabPage;
    newTaby = ui->mTabWidget->findChild<myTabPage*>("myTabPage");
    //QString aaag = QString::number(ui->mTabWidget->currentIndex());
    //newTaby->setTabText(aaag);

    //QList *newTabyList = new QList;
    //newTabyList = ui->mTabWidget->findChildren<myTabPage*>("myTabPage");

    //qDebug() << "My newTaby:";
    //qDebug() << newTaby;// qDebug() << aaag;

    QTextEdit *newTextEdit = new QTextEdit;
    newTextEdit = newTaby->findChild<QTextEdit*>("mTextEdit");

    qDebug() << "newTaby newTextEdit child:";
    qDebug() << newTextEdit;

    newTextEdit->setPlainText(mFileStream);

    //qDebug()<< "Have set text:" + newTextEdit->toPlainText() + "\nto newTextEdit on tab number:" + newTextEdit->objectName();

    //outputs index of the tab you're on
    //qDebug()<< "Tab selected:"; qDebug()<< ui->mTabWidget->currentIndex();

    //mTabWidget->ui->myTabPage::myFoo(mFileStream);

    //myTabPage::myFoo(mFileStream);

    //ui->mTextEdit->setText("random text");

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
    //QString text = ui->mTextEdit->toPlainText();

    //Writing to file
    //out << text;

    //Flushing after use
    mFile.flush();

    //Closing the file
    mFile.close();

    QString statusString = "File " + Filename + " saved.";
    statusBar()->showMessage(statusString);
}

void MainWindow::on_actionNew_File_triggered()
{

    ui->mTabWidget->insertTab(ui->mTabWidget->currentIndex()+1,new myTabPage(),QIcon(QString("")),"New Tab");

    //QString aaasd = QString::number(ui->mTabWidget->currentIndex());
    //ui->mTabWidget->setTabText(ui->mTabWidget->currentIndex(),aaasd);


    //myTabPage.setTabText("kekuru");

    //qDebug() << "Children:"; qDebug() << ui->mTabWidget->children();

    //qDebug() << ui->mTabWidget->findChild("mTextEdit");



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


//The below is not erally neededs
void MainWindow::addMyItems(QString mFileSring)
{
    //ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);//increase row count by 1

    //QWidget *txt = new QWidget;
    //txt = ui->mTabWidget->widget(0);



    //int row = ui->tableWidget->rowCount() - 1;

    //set all data in cells
    //ui->tableWidget->setItem(row,0,new QTableWidgetItem(name));
    //ui->tableWidget->setItem(row,1,new QTableWidgetItem(address));
    //ui->tableWidget->setItem(row,2,new QTableWidgetItem(phone));
    //ui->tableWidget->setItem(row,3,new QTableWidgetItem(mobile));
}
/*
void MainWindow::on_mTabWidget_tabBarClicked(int index)
{
    connect(ui->mTabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(onTabChanged(int)));
}*/
/*
void MainWindow::onTabChanged(int tabIndex)
{
    qDebug() << "Tab number:" + QString::number(ui->mTabWidget->currentIndex()) + " selected";
}*/
/*
 *
 *
 *
 *     connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar_2,SLOT(setValue(int)));
       **/

/*
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    bool result = QObject::eventFilter(obj, event);

        if (event->type() == QEvent::MouseButtonDblClick)
        {
            //perhaps we need to start a new name editing action...
            QMouseEvent* me = static_cast<QMouseEvent*>(event);
            int clickedTabId = ui->mTabWidget->currentIndex();
            qDebug() << "Clicked tab ID:" + QString::number(clickedTabId);
         }

            /*if (clickedTabId == -1)
                return result;
            if (!m_allowRenamingDisabledTabs && !ui->mTabWidget->isTabEnabled(clickedTabId))
                return result;
            triggerRename(clickedTabId);
            return true; //no further handling of this event is required
        }
    }*/
/*
    //handle some events on the line edit to make it behave itself nicely as a rename editor
    if (o == m_lineEdit) {
        if (e->type() == QEvent::KeyPress) {
            QKeyEvent* ke = static_cast<QKeyEvent*>(e);
            if (ke->key() == Qt::Key_Escape) {
                m_lineEdit->deleteLater();
                return true; //no further handling of this event is required
            }
        }
    }
*//*
    return result;
 }
*/
/*
void MainWindow::on_mTabWidget_tabBarClicked(int index)
{
    ui->label->setText(QString::number(ui->mTabWidget->currentIndex()));
    ui->label->show();
}*/
