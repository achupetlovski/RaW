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

#ifndef COLOR_H
#define COLOR_H

class color{
public:
    void setName(QString name) { keyword_name = name; }
    void setColor(QString color) { keyword_color = color; }
    QString getKeyWordName() { return keyword_name;}
    QString getKeyWordColor() { return keyword_color; }
private:
    QString keyword_name;
    QString keyword_color;

};

#endif // COLOR_H
