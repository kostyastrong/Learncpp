#include "onlynumber.h"
#include "ui_onlynumber.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <func.h>


onlynumber::onlynumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::onlynumber)
{
    ui->setupUi(this);
}

onlynumber::~onlynumber()
{
    delete ui;
}

void onlynumber::on_Ok_clicked()
{
    int f = ui->Number->text().toInt();
    now1 = f;
    /*QMessageBox::StandardButton ans = QMessageBox::question(this, "Мдем-с", "Are you sure about this?",
                                                            QMessageBox::Yes | QMessageBox::No);
    if (ans == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug()<< "Не вышел";
    }*/
}
