#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui {
class options;
}

class options : public QDialog
{
    Q_OBJECT

public:
    explicit options(QWidget *parent = 0);
    ~options();

    void readFromFile(QString myFilePath);

private slots:
    void addRow();
    void removeSelectedRow();

    void on_tableWidget_itemSelectionChanged();

    void on_pushButtonSave_clicked();

private:
    Ui::options *ui;

};

#endif // OPTIONS_H
