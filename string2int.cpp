#include "string2int.h"
#include "ui_string2int.h"
#include <func.h>
#include <QDebug>

string2int::string2int(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::string2int)
{
    ui->setupUi(this);
}

string2int::~string2int()
{
    delete ui;
}



void string2int::on_Ok_clicked()
{
    QString str = ui->strInput->text();
    int f = ui->fNumber->text().toInt();
    int s = ui->sNumber->text().toInt();
    stringnow = str;
    now1 = f;
    now2 = s;
    qDebug() << now1 << now2 << stringnow;
    //insert(str, n);
}
