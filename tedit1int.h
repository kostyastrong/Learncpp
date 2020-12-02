#ifndef TEDIT1INT_H
#define TEDIT1INT_H

#include <QDialog>

namespace Ui {
class tEdit1int;
}

class tEdit1int : public QDialog
{
    Q_OBJECT

public:
    explicit tEdit1int(QWidget *parent = nullptr);
    ~tEdit1int();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tEdit1int *ui;
};

#endif // TEDIT1INT_H
