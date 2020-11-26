#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string2int.h"
#include "ui_string2int.h"
#include "func.h"

#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QLabel *label = new QLabel("Hello");
//    label->resize(400, 400);
//    label->show();


    return a.exec();
}
