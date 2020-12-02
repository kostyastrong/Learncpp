#include "tedit1int.h"
#include "ui_tedit1int.h"
#include "func.h"

tEdit1int::tEdit1int(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tEdit1int)
{
    ui->setupUi(this);
}

tEdit1int::~tEdit1int()
{
    delete ui;
}

void tEdit1int::on_pushButton_clicked()
{
    QString str = ui->textEdit->toPlainText();
    int f = ui->lineEdit->text().toInt();
    now1 = f;
    stringnow = str;
}
