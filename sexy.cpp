#include "sexy.h"
#include "ui_sexy.h"
#include <QDebug>
#include <QApplication>

sexy::sexy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sexy)
{
    ui->setupUi(this);
}

sexy::~sexy()
{
    delete ui;
}

void sexy::on_pushButton_clicked()
{
    int strin = ui->mansrt->text().toInt();

}
