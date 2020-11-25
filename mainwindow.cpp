#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "sexy.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    sexy window;
    window.setModal(true);
    window.exec();
    //ui->AboveButton->setText("Оу, да");
}

void MainWindow::on_Exit_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::question(this, "Вы точно хотите закрыть программу?", "Точно-точно?",
                          QMessageBox::Yes | QMessageBox::No);
    if (result == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "А-а-а, а кнопочку он то не нажал, хехе";
    }
}
