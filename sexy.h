#ifndef SEXY_H
#define SEXY_H

#include <QDialog>

namespace Ui {
class sexy;
}

class sexy : public QDialog
{
    Q_OBJECT

public:
    explicit sexy(QWidget *parent = nullptr);
    ~sexy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sexy *ui;
};

#endif // SEXY_H
