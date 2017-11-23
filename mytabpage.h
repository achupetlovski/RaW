#ifndef MYTABPAGE_H
#define MYTABPAGE_H

#include <QWidget>

namespace Ui {
class myTabPage;
}

class myTabPage : public QWidget
{
    Q_OBJECT

public:
    explicit myTabPage(QWidget *parent = 0);
    ~myTabPage();
    void setTabText(QString &mFileStream);
private slots:

private:
    Ui::myTabPage *ui;
};

#endif // MYTABPAGE_H
