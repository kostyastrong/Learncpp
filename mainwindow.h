#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "onlynumber.h"
#include "string2int.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Exit_clicked();

    void on_InsertStringFrom_clicked();

    void on_InsertString_clicked();

    void on_DeleteZeroes_clicked();

    void on_IncreaseFigures_clicked();

    void on_DeleteBrackets_clicked();

    void on_ReplaceSpecCharN_clicked();

    void on_DeleteString_clicked();

    void on_InsertStringMany_clicked();

    void on_ReplaceChar_clicked();

    void on_ReplaceString_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
