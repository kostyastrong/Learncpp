#include "twostring2int.h"
#include "ui_twostring2int.h"
#include "func.h"

twoString2int::twoString2int(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::twoString2int)
{
    ui->setupUi(this);
}

twoString2int::~twoString2int()
{
    delete ui;
}

void twoString2int::on_pushButton_clicked()
{
    QString strF = ui->lineEdit->text();
    QString strS = ui->lineEdit_2->text();
    int num1 = ui->fNumber->text().toInt();
    int num2 = ui->sNumber->text().toInt();

    now1 = num1;
    now2 = num2;
    stringnow = strF;
    stringnew = strS;
}
