#ifndef STRING2INT_H
#define STRING2INT_H

#include <QDialog>

namespace Ui {
class string2int;
}

class string2int : public QDialog
{
    Q_OBJECT

public:
    explicit string2int(QWidget *parent = nullptr);
    ~string2int();

private slots:
    void on_Ok_clicked();

private:
    Ui::string2int *ui;
};

#endif // STRING2INT_H
