#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

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
    QMessageBox::StandardButton b = QMessageBox::question(this, "Заголовок", "Text",
                          QMessageBox::Yes | QMessageBox::No);
    if (b == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "No was yes";
    }
    //ui->AboveButton->setText("Оу, да");
}
