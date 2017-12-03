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
#include <QDateTime>
#include "color.h"

QList<color> list;

void MainWindow::eventAutoColor()
{

    color *words1 = new color;
    words1->setColor("red"); words1->setName("or");

    color *words2 = new color;
    words2->setColor("green"); words2->setName("function");

    color *words3 = new color;
    words3->setColor("purple"); words3->setName("true");

    color *words4 = new color;
    words4->setColor("aqua"); words4->setName("then");

    color *words5 = new color;
    words5->setColor("blue"); words5->setName("repeat");

    color *words6 = new color;
    words6->setColor("orange"); words6->setName("while");

    color *words7 = new color;
    words7->setColor("yellow"); words7->setName("for");

    color *words8 = new color;
    words8->setColor("brown"); words8->setName("if");

    color *words9 = new color;
    words9->setColor("white"); words9->setName("function");

    color *words10 = new color;
    words10->setColor("teal"); words10->setName("elseif");

    color *words11 = new color;
    words11->setColor("green"); words11->setName("else");

    color *words12 = new color;
    words12->setColor("magenta"); words12->setName("do");

    color *words13 = new color;
    words13->setColor("cyan"); words13->setName("break");

    color *words14 = new color;
    words14->setColor("purple"); words14->setName("and");

    color *words15 = new color;
    words15->setColor("#ff9966"); words15->setName("until");

    color *words16 = new color;
    words16->setColor("#cd7f32"); words16->setName("not");

    color *words17 = new color;
    words17->setColor("#f4c2c2"); words17->setName("local");

    color *words18 = new color;
    words18->setColor("#fe6f5e"); words18->setName("end");

    color *words19 = new color;
    words19->setColor("#8a2be2"); words19->setName("in");

    color *words20 = new color;
    words20->setColor("#cb4154"); words20->setName("return");

    color *words21 = new color;
    words21->setColor("#8a2be2"); words21->setName("nil");

    color *words22 = new color;
    words22->setColor("#cb4154"); words22->setName("false");


    list.push_back(*words1);
    list.push_back(*words2);
    list.push_back(*words3);
    list.push_back(*words4);
    list.push_back(*words5);
    list.push_back(*words6);
    list.push_back(*words7);
    list.push_back(*words8);
    list.push_back(*words9);
    list.push_back(*words10);
    list.push_back(*words11);
    list.push_back(*words12);
    list.push_back(*words13);
    list.push_back(*words14);
    list.push_back(*words15);
    list.push_back(*words16);
    list.push_back(*words17);
    list.push_back(*words18);
    list.push_back(*words19);
    list.push_back(*words20);
    list.push_back(*words21);
    list.push_back(*words22);


    QString myStr = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();
    QStringList myStrList = myStr.split(" ");

    //qDebug()<<"mystrlist count:"<<myStrList.count();

    for(int t=0; t < myStrList.count(); t++)
    {
        QString word = myStrList[t];
        //qDebug() <<"t iteration" << t;
        for (int i = 0; i < list.count(); i++)
        {
            //qDebug() <<"i iteration" << i;
            //qDebug() << "iteration:";
            //qDebug() << i;

            //qDebug() << "list[i].getKeyWordName()";
            //qDebug() << list[i].getKeyWordName();
            //match "word" to all of the keywords. if any matches set it's colour
            if(word==list[i].getKeyWordName())

            //if(word==keywords[i].getKeyWordName())
            {
                //qDebug() << "list[i].getKeyWordColor()";
                //qDebug() << list[i].getKeyWordColor();
                //qDebug()<<"old word:"+word;
                myStrList.replaceInStrings(word, "<font color="+ list[i].getKeyWordColor() +">" + word);

                 word="<font color="+ list[i].getKeyWordColor() +">" + word;

                //qDebug()<<"new word:" + word;


             //  word="<font color="+ list[i].getKeyWordColor() +">" + word;
            //      word="<font color="+ keywords[i].getKeyWordColor() +">" + word;

            }
        }
    }

    myStr = myStrList.join(" ");

    ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setHtml(myStr);

/*
    QString fileName = "/home/mike/qt/mini-projects/keywords.lua";

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


    QStringList list = mFileString.split(" ");

    qDebug() << "\nList count:";
    qDebug() << list.count();

    int n = list.count();
    color keywords[n-1];


    for ( int i = 0; i < n-1; i++)
    {
//        QString firstWord = mFileString.split(" ").at(0);
//        QString secondWord = mFileString.split(" ").at(1);

        keywords[i].setName(list[i]);
        keywords[i].setColor(list[i]+1);
    }

    mFile.close();



    for (int i = 0; i < n-1; i++)
    {
            qDebug() << "iteration:";
            qDebug() << i;
            QString i_str = QString::number(i);

            qDebug() << "list["+i_str+"].getKeyWordName()";
            qDebug() << keywords[i].getKeyWordName();

            qDebug() << "list["+i_str+"].getKeyWordColor()";
            qDebug() << keywords[i].getKeyWordColor();
    }
*/

    /*
    list << *first;
    list << *second;
    list << *third;

    qDebug()<<first->getKeyWordName();
    qDebug()<<first->getKeyWordColor();

    qDebug()<<second->getKeyWordName();
    qDebug()<<second->getKeyWordColor();

    qDebug()<<third->getKeyWordName();
    qDebug()<<third->getKeyWordColor();
    */
    /*for (int i = 0; i < list.count(); i++)
    {
        qDebug() << "iteration:";
        qDebug() << i;
        QString i_str = QString::number(i);

        qDebug() << "list["+i_str+"].getKeyWordName()";
        qDebug() << list[i].getKeyWordName();

        qDebug() << "list["+i_str+"].getKeyWordColor()";
        qDebug() << list[i].getKeyWordColor();
    }
    */


    //list.append(*second);
    //list.append(*first);

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

    ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setPlainText(plainText);

    //qDebug() << "\nplainTextVariable:";
    //qDebug() << plainText;

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


    //qDebug() << "\nQString word:";
    //qDebug() << word;

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

    //qDebug() << "list.count():";
    //qDebug() << list.count();



    for (int i = 0; i < list.count(); i++)
    {
        //qDebug() << "iteration:";
        //qDebug() << i;

        //qDebug() << "list[i].getKeyWordName()";
        //qDebug() << list[i].getKeyWordName();
        //match "word" to all of the keywords. if any matches set it's colour
        if(word==list[i].getKeyWordName())

        //if(word==keywords[i].getKeyWordName())
        {
            //qDebug() << "list[i].getKeyWordColor()";
            //qDebug() << list[i].getKeyWordColor();
           word="<font color="+ list[i].getKeyWordColor() +">" + word;
        //      word="<font color="+ keywords[i].getKeyWordColor() +">" + word;

        }
    }

/*
        qDebug() << "iteration:";
        qDebug() << i;

        qDebug() << "size of the object array:";
        qDebug() << sizeof(keywords);
    }
*/
    /*
    for (int i = 0; i < list.count(); i++)
    {
        qDebug() << "iteration:";
        qDebug() << i;
        QString i_str = QString::number(i);

        qDebug() << "list["+i_str+"].getKeyWordName()";
        qDebug() << list[i].getKeyWordName();

        qDebug() << "list["+i_str+"].getKeyWordColor()";
        qDebug() << list[i].getKeyWordColor();
    }
    */
    //qDebug() << "\nQString Colored word RIGHT BEFORE INSERT HTML TO TMP:";
    //qDebug() << word;

    ///Append the colorful things to the word
    tmp.insertHtml(word);


    //tmp.setPosition(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->textCursor().position());

    tmp.setPosition(tempInt);

    ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->setTextCursor(tmp);



    //qDebug() << "\nQString Colored word:";
    //qDebug() << word;

    //qDebug() << "\ntmp after::";
    //qDebug() << tmp.position();



    //QString plainText = ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit")->toPlainText();

    //qDebug() << "\nplainTextVariable:";
    //qDebug() << plainText;

    connect(ui->mTabWidget->currentWidget()->findChild<QTextEdit*>("mTextEdit"), SIGNAL(textChanged()), this, SLOT(eventAutoColor_new()));
}
