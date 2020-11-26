#include "string2int.h"
#include "ui_string2int.h"

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


