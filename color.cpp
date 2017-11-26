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
//#include <QStringMatcher>
#include <QDateTime>

#include "color.h"

/*
enum myEnum {
  var,
  foo,
  function
};

typedef QMap<QString, myEnum> StringToEnumMap;
 StringToEnumMap stringToEnum;
*/
QList<color> list;


void MainWindow::eventAutoColor()
{


    color *first = new color;
    first->setColor("red");
    first->setName("foo");

    color *second = new color;
    first->setColor("green");
    first->setName("function");

    color *third = new color;
    first->setColor("purple");
    first->setName("if");

    list.push_back(*first);
    list.push_back(*second);
    list.push_back(*third);


    //QList<QSharedPointer<Object> > object_list;
    //object_list.push_back(QSharedPointer<Object>(new Object));

    //disconnect(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"), SIGNAL(textChanged()), this, SLOT(eventAutoColor()));
    ui->statusBar->showMessage("Thinking...");
    //qDebug() << "\neventAutoColor occurred at";
    //qDebug() << QTime::currentTime();

    //QString myStr = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

    ///here we have the string of the mTextEdit box on which we've envoked the Show command
    ///
    ///coloring code goes here.





    //QString myAqua="<font color=\"Aqua\">";
    //myStr.append(myAqua);



    //qDebug() << "myStr after change:";
    //qDebug() << myStr;

    //QPoint tmp;// = new QPoint;
    //QCursor *tmp = new QCursor;
    //tmp->setPos(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->cursor.pos());

    //cursor.pos()

    //ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->cursor/

    //ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setHtml(myStr);

    //ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->cursor.setPos(tmp);

    //qDebug() << myStr.QStringMatcher("foo", 0);

    //QStringMatcher *matcher = new QstringMatcher;
    //matcher->pattern();
    //QTextStream myStream(&myStr);

     //QTextStream out;
     //out << ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

    //out.skipWhiteSpace();

    //out >> myStr;



    //QLineEdit *line = new QLineEdit();
    //line->setText("this is a test");
    //line->setStyleSheet("foreground-color: blue;");



    //myStr="<font color=\"Aqua\">newstr";




    //ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setHtml(myStr);

    //qDebug() << myStr;
    //ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setPlainText(myStream);

    /*
    QTextCursor cursor = ui->editor->textCursor(); // editor is QTextEdit
    cursor.select(QTextCursor::WordUnderCursor);
    QString c = cursor.selectedText();

    if (c == keywords[i])
    {
        cursor.removeSelectedText();
        cursor.insertHtml("<font color=\"DeepPink\">" + keywords[i] + "</font>");
    }
    */

    //QString keywords[] = "foo";

    //QStringList myList = new QStringList;
    //myList = myStr;

    //QStringListIterator
    //if(myStr == keywords[i])
    //{






    /*myStream.readAll();


    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    QString text;
    text = in.readAll();
    file.close();*/


    /*
    if()
    {
        qDebug() << "do stuff";
    }*/

    //ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->moveCursor(QTextCursor::End);      /*QTextCursor::Right, QTextCursor::MoveAnchor);*/
    ui->statusBar->showMessage("");
    //connect(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"), SIGNAL(textChanged()), this, SLOT(eventAutoColor()));
}

void MainWindow::diseventAutoColor()
{
    //QString tmp = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toHtml();
    //ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setPlainText(tmp);

    //QTextEdit htmlText(HtmlText);  // HtmlText is any QString with html tags.
    //QString plainText = htmlTextEdit.toPlainText();



    QString plainText = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

    qDebug() << "\nplainTextVariable:";
    qDebug() << plainText;

}



void MainWindow::eventAutoColor_new()
{
    disconnect(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"), SIGNAL(textChanged()), this, SLOT(eventAutoColor_new()));

    QTextCursor tmp = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->textCursor();

    //qDebug() << "\nui->mTabWidget->currentWidget()->findChild<QTextEdit*>(\"mTextEdit\")->textCursor():";
    //qDebug() << ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->textCursor().position();
    int tempInt = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->textCursor().position();

    tmp.select(QTextCursor::WordUnderCursor);
    QString word = tmp.selectedText();


    qDebug() << "\nQString word:";
    qDebug() << word;

    //qDebug() << "\ntmp before:";
    //qDebug() << tmp.position();


    ///If word matches a key word, add color to it .. ;d
    /*
    if(word=="var")
    {
        word="<font color=\"Green\">" + word;

    }
    */



    //qDebug() << "\nQString Colored word RIGHT BEFORE WORD SWITCH STATEMENT:";
    //qDebug() << word;

    /*
    switch(stringToEnum[word])
    {
        case foo:
            word="<font color=\"White\">" + word;
            break;
        case function:
            word="<font color=\"Red\">" + word;
            break;
        case var:
            word="<font color=\"Green\">" + word;
            break;
        default:
            word="<font color=\"Black\">" + word;
            break;
    }
    */
    ///don't use switch and strings
    ///

    /*qDebug() << "list.count():";
    qDebug() << list.count();

    for (int i = 0; i < list.count(); i++)
    {
        qDebug() << "iteration:";
        qDebug() << i;

        qDebug() << "list[i].getKeyWordName()";
        qDebug() << list[i].getKeyWordName();
        //match "word" to all of the keywords. if any matches set it's colour
        if(word==list[i].getKeyWordName())
        {
            qDebug() << "list[i].getKeyWordColor()";
            qDebug() << list[i].getKeyWordColor();
            word="<font color="+ list[i].getKeyWordColor() +">" + word;

        }
    }*/




    qDebug() << "\nQString Colored word RIGHT BEFORE INSERT HTML TO TMP:";
    qDebug() << word;

    ///Append the colorful things to the word
    tmp.insertHtml(word);


    //tmp.setPosition(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->textCursor().position());

    tmp.setPosition(tempInt);

    ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setTextCursor(tmp);



    qDebug() << "\nQString Colored word:";
    qDebug() << word;

    //qDebug() << "\ntmp after::";
    //qDebug() << tmp.position();



    QString plainText = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

    //qDebug() << "\nplainTextVariable:";
    //qDebug() << plainText;

    connect(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"), SIGNAL(textChanged()), this, SLOT(eventAutoColor_new()));
}


