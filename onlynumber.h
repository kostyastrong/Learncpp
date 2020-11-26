#ifndef ONLYNUMBER_H
#define ONLYNUMBER_H

#include <QDialog>

namespace Ui {
class onlynumber;
}

class onlynumber : public QDialog
{
    Q_OBJECT

public:
    explicit onlynumber(QWidget *parent = nullptr);
    ~onlynumber();

private slots:
    void on_Ok_clicked();

private:
    Ui::onlynumber *ui;
};

#endif // ONLYNUMBER_H
