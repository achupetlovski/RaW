#include "options.h"
#include "ui_options.h"
#include <QWidget>
#include <QDebug>

options::options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);

    //QWidget *myWidget = new QWidget;
    //myWidget->show();

    //this->close();

    //QGridLayout *layout = new QGridLayout;
    //layout->addWidget(ui->tableWidget);
    //ui->mTabWidget->currentWidget()->setLayout(layout);
    //ui->mTabWidget->currentWidget()->show();

    //layout->addWidget(ui->pushButton,0,0);
    //layout->addWidget(ui->tableWidget,1,0);


    //setLayout(layout);.

    //QGridLayout *layout = new QGridLayout;

    ui->gridLayoutOptions->addWidget(ui->pushButtonPlus,0,0);
    ui->gridLayoutOptions->addWidget(ui->pushButtonMinus,0,1);
    ui->gridLayoutOptions->addWidget(ui->tableWidget,1,0,1,2);

    setLayout(ui->gridLayoutOptions);

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(2);

    connect(ui->pushButtonPlus,SIGNAL(clicked(bool)), SLOT(addRow()));
    connect(ui->pushButtonMinus,SIGNAL(clicked(bool)), SLOT(removeSelectedRow()));

    qDebug()<<"1";
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
        ui->tableWidget->insertRow(1);
    }
}

void options::removeSelectedRow()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}
