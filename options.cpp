#include "options.h"
#include "ui_options.h"
#include <QWidget>
#include <QDebug>
#include <QDir>
#include <QFileInfo>

QString myFilePath = "";

options::options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);

    ui->gridLayoutOptions->addWidget(ui->pushButtonPlus,0,0);
    ui->gridLayoutOptions->addWidget(ui->pushButtonMinus,0,1);
    //ui->gridLayoutOptions->addWidget(ui->pushButtonMinus,0,);
    ui->gridLayoutOptions->addWidget(ui->tableWidget,1,0,1,3);

    setLayout(ui->gridLayoutOptions);

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(2);

    connect(ui->pushButtonPlus,SIGNAL(clicked(bool)), SLOT(addRow()));
    connect(ui->pushButtonMinus,SIGNAL(clicked(bool)), SLOT(removeSelectedRow()));

    //qDebug()<<"1";

    //QDir myDir = QDir::current();
    //qDebug() << "QDir::current()" << myDir;

    //qDebug() << "QDir::currentPath()" << QDir::currentPath();

    ///qApp->applicationDirPath(); leads to /build-*-Debug/
    //qDebug() << "App path : " << qApp->applicationDirPath();

    QString myPath = qApp->applicationDirPath() + "/conf";
    //qDebug() << "myPath: " << myPath;



    if(!QDir(myPath).exists())
    {
        //create
        //qDebug() << "myPath does not exist...creating";
        QDir(myPath).mkpath(myPath);
        qDebug() << "created dir at " << myPath;
    }
    else
    {
        //qDebug() << "myPath does exists...not creating";
        //the /conf dir exists. we can now check if the keywords file exists.


        //qDebug() << "myPath :" << myPath;

        //QFileInfo::exists();

        //if (QDir(myFilePath).exists()) //if keywords file exist, read from it
    }

    myFilePath = myPath + "/keywords.conf";

    if (QFileInfo(myFilePath).exists())
    {
        //qDebug() << "Keywords file exists at " << myFilePath;


        //here, given that the file exists, make table read from it

        readFromFile(myFilePath);

    }
    else //if keywords file does not exist, create one
    {
        //qDebug() << "Keywords file does not exist at" << myFilePath;
        QFile mFile(myFilePath);
        if(!mFile.open(QFile::WriteOnly | QFile::Text))
        {
                qDebug() << "Could not open file for writing at " << myFilePath;
                return;
        }

        //TextStream of the file
        //QTextStream out(&mFile);

        //out << "";

        mFile.flush();
        mFile.close();

        qDebug() << "Keywords.conf file created at" << myFilePath;
    }

    //up to here we have created the /conf and /conf/keywords.conf dir and file respectively
    //if they were not there


    //at any change made to the table, write to file

}

options::~options()
{
    delete ui;
}

void options::addRow()
{
    if (ui->tableWidget->rowCount() == 0)
    {
        ui->tableWidget->setRowCount(1);
    }
    else
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    }
}

void options::removeSelectedRow()
{
    //if rows are selected remove them
    /*if(ui->tableWidget->currentRow()!=NULL)
    {
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    }
    //else remove the newest one
    else
    {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount());
    }*/

    if(ui->tableWidget->isItemSelected(ui->tableWidget->currentItem()))
    {
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    }
    else
    {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
    }

    //the below removes the last row
    //ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
}

void options::readFromFile(QString myFilePath)
{
    QFile myFile(myFilePath);
    if(!myFile.open(QFile::ReadOnly | QFile::Text))
    {
            qDebug() << "Could not open file for reading at " << myFilePath;
            return;
    }

    QTextStream in(&myFile);

    QString mFileString = in.readAll();
    QStringList myStringList = mFileString.split(QRegExp("\n| "), QString::SkipEmptyParts);//.split(" |\n");

    int words_c = myStringList.count();
    //qDebug() << "Words_C:" << words_c;

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(words_c/2);
    int p = 0;
    for(int i = 0; i < words_c/2;i++)
    {
        for( int t = 0; t < 2; t++)
        {
            //QTableWidgetItem *myCell = ui->tableWidget->item(i, j);

            QTableWidgetItem *myQTWI= new QTableWidgetItem;;
            myQTWI->setText(myStringList[p]);
            ui->tableWidget->setItem(i,t, myQTWI);
            p++;
        }
    }


    myFile.close();
    //here we now have the contents of the file keywords.conf into the QString mFileString.
    // and we must fill the table with it's contents




    //qDebug() << "\nContents of mFileString: " << mFileString;

    //qDebug() << "\nContents of myStringList: " << myStringList;
}

//cant get automatic saving when selection changes for now, some unhelpful error pops up
void options::on_tableWidget_itemSelectionChanged()
{
    //save to the keywords file if table item selection is changed.

    /*QFile myFile(myFilePath);
    if(!myFile.open(QFile::WriteOnly | QFile::Text))
    {
            qDebug() << "Could not open file for writing at " << myFilePath;
            return;
    }

    QTextStream out(&myFile);

    QString blq = "";

    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for(int t = 0; t < ui->tableWidget->columnCount(); t++)
        {
            //blq = blq + cell
            QTableWidgetItem *myItem = ui->tableWidget->item(i,t);
            blq = blq + myItem->text();
            blq = blq + " ";
        }
        blq = blq + "\n";
    }

    qDebug() << "Blq final: " << blq;

    out << blq;


    myFile.flush();

    myFile.close();*/
}

void options::on_pushButtonSave_clicked()
{
    QFile myFile(myFilePath);
        if(!myFile.open(QFile::WriteOnly | QFile::Text))
        {
                qDebug() << "Could not open file for writing at " << myFilePath;
                return;
        }

        QTextStream out(&myFile);

        QString blq = "";

        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            for(int t = 0; t < ui->tableWidget->columnCount(); t++)
            {
                //blq = blq + cell
                QTableWidgetItem *myItem = ui->tableWidget->item(i,t);
                blq = blq + myItem->text();
                blq = blq + " ";
            }
            blq = blq + "\n";
        }

        //qDebug() << "Blq final: " << blq;

        out << blq;


        myFile.flush();

        myFile.close();
}
