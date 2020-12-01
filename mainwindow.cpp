#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string2int.h"
#include "ui_string2int.h"
#include "onlynumber.h"
#include "func.h"

#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <QTextEdit>


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

void MainWindow::on_Exit_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::question(this, "Попадос", "Вы точно хотите закрыть программу?",
                          QMessageBox::Yes | QMessageBox::No);
    if (result == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "А-а-а, а кнопочку то он не нажал, хехе";
    }
}


void MainWindow::on_InsertStringFrom_clicked()
{
    string2int window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_InsertString_clicked()
{
    string2int window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_DeleteZeroes_clicked()
{
    onlynumber window;
    window.setModal(true);
    window.exec();

    //auto list = ui->textEdit->toPlainText().trimmed().split('\n');
}

void MainWindow::on_IncreaseFigures_clicked()
{
    onlynumber window;
    window.setModal(true);
    window.exec();
}
