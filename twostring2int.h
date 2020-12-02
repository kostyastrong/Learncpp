#ifndef TWOSTRING2INT_H
#define TWOSTRING2INT_H

#include <QDialog>

namespace Ui {
class twoString2int;
}

class twoString2int : public QDialog
{
    Q_OBJECT

public:
    explicit twoString2int(QWidget *parent = nullptr);
    ~twoString2int();

private slots:
    void on_pushButton_clicked();

private:
    Ui::twoString2int *ui;
};

#endif // TWOSTRING2INT_H
