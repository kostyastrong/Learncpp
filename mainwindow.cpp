#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string2int.h"
#include "ui_string2int.h"
#include "onlynumber.h"
#include "func.h"
#include "tedit1int.h"
#include "twostring2int.h"

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
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();

    for (int i = 1; i < now1; ++i) {
        ui->textEdit->append(pieces[i - 1]);
    }

    for (int i = 1; i < now2; ++i) {
        QString out = "";
        if (i == 1) out += '\n';  // we should add new line
        out.append(pieces[now1 - 1][i - 1]);
        ui->textEdit->insertPlainText(out);  // it doesn't take char
        ui->textEdit->moveCursor(QTextCursor::End);
    }
    ui->textEdit->insertPlainText(stringnow);
    ui->textEdit->moveCursor(QTextCursor::End);

    for (int i = now2; i <= pieces[now1- 1].size(); ++i){
        QString out = "";
        out.append(pieces[now1 - 1][i]);
        ui->textEdit->insertPlainText(out);
        ui->textEdit->moveCursor(QTextCursor::End);
    }
    ui->textEdit->insertPlainText("");
    for (int i = now1 + 1; i <= pieces.size(); ++i) {
        ui->textEdit->append(pieces[i - 1]);
    }
    qDebug() << stringnow;
}


void MainWindow::on_InsertString_clicked()
{
    string2int window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    now1 = std::min(now1, pieces.size());
    qDebug() << 1;
    ui->textEdit->clear();

    QStringList out;
    for (int i = 0; i < now1; ++i) {
        out.append(pieces.at(i));
        //ui->textEdit->append(pieces.at(i));
    }
    //ui->textEdit->append(stringnow);
    out.append(stringnow);
    qDebug() << now1;
    for (int i = now1; i < pieces.size(); ++i) {
        out.append(pieces.at(i));
        //ui->textEdit->append(pieces.at(i));      ui append is a second way to add strings to editText
    }

    QString outstr = out.join('\n');
    ui->textEdit->setText(outstr);
    qDebug() << stringnow;
}

void MainWindow::on_DeleteZeroes_clicked()
{
    string2int window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();
    for (int l = now1; l <= now2; ++l) {
        int k = l - 1;
        QString ret = "";
        int i = 0;
        for (; i < pieces[k].size();) {
            if (pieces[k][i] != '0' || (i > 0 && pieces[k][i - 1] > '0' && pieces[k][i - 1] <= '9')) {
                ret += pieces[k][i];
                ++i;
            } else {
                bool ok = true;
                int j = i + 1;
                while (j < pieces[k].size() && pieces[k][j] == '0') {
                    ++j;
                }
                if (j == pieces[k].size() || pieces[k][j] < '0' || pieces[k][j] > '9') {
                    ret += '0';
                }
                i = j;
            }
        }
        pieces[k] = ret;
    }
    for (auto i : pieces) {
        ui->textEdit->append(i);
    }
    //auto list = ui->textEdit->toPlainText().trimmed().split('\n');
}

void MainWindow::on_IncreaseFigures_clicked()
{
    onlynumber window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();
    QString ret = "";

    int i = 0;
    for (; i < pieces[now1 - 1].size();) {
        if (pieces[now1 - 1][i] > '9' || pieces[now1 - 1][i] < '0') {
            ret += pieces[now1 - 1][i];
            ++i;
        } else {
            bool ok = true;
            int j = i + 1;
            while (j < pieces[now1 - 1].size() && pieces[now1 - 1][j] >= '0' && pieces[now1 - 1][j] <= '9') {
                QString digStr = "";
                digStr += pieces[now1 - 1][j];
                QString digStrLast = "";
                digStrLast += pieces[now1 - 1][j - 1];
                if (digStr.toInt() < digStrLast.toInt()) {
                    ok = false;
                }
                ++j;
            }
            if (ok) {
                ret += pieces[now1 - 1][i];
                j = i + 1;
                while (j < pieces[now1 - 1].size() && pieces[now1 - 1][j] >= '0' && pieces[now1 - 1][j] <= '9') {
                    ret += pieces[now1 - 1][j];
                    ++j;
                }
            }
            i = j;
        }
    }
    pieces[now1 - 1] = ret;
    for (auto i : pieces) {
        ui->textEdit->append(i);
    }
}

void MainWindow::on_DeleteBrackets_clicked()
{
    onlynumber window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();

    QString rep = "";
    bool ok = true;
    for (int i = 0; i < pieces[now1 - 1].size(); ++i) {
        if (pieces[now1 -  1][i] == '{') {
            ok = false;
        }
        if (ok) {
            rep += pieces[now1 - 1][i];
        }
        if (pieces[now1 - 1][i] == '}') {
            ok = true;
        }
    }
    pieces[now1 - 1] = rep;
    for (auto i : pieces) {
        ui->textEdit->append(i);
    }
}

void MainWindow::on_ReplaceSpecCharN_clicked()
{
    onlynumber window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();

    stringnow = "";
    for (int i = 0; i < now1; ++i) {
        stringnow += '*';
    }
    stringnew = "";
    for (int i = 0; i < now1 / 2; ++i) {
        stringnew += '+';
    }

    now1 = 1;
    now2 = pieces.size();
    for (int i = now1; i <= now2; ++i) {
        if (pieces[i - 1].contains(stringnow)) {
            QString newS = pieces[i - 1];
            int index = 0;
            while (newS.contains(stringnow) && index < pieces[i - 1].size()) {
                int newind = newS.indexOf(stringnow);
                if (newind == -1) break;
                newS.replace(newind, stringnow.size(), stringnew);
                index = newind + stringnow.size();
            }
            pieces[i - 1] = newS;
        }
    }
    for (auto i : pieces) {
        ui->textEdit->append(i);
    }

}

void MainWindow::on_DeleteString_clicked()
{
    onlynumber window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    now1 = std::min(now1, pieces.size());
    ui->textEdit->clear();

    for (int i = 1; i <= pieces.size(); ++i) {
        if (i == now1) continue;
        ui->textEdit->append(pieces.at(i - 1));
    }
}

void MainWindow::on_InsertStringMany_clicked()
{
    tEdit1int window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();

    now1 = std::min(pieces.size(), now1);
    for (int i = 0; i < now1; ++i) {
        ui->textEdit->append(pieces.at(i));
    }
    ui->textEdit->append(stringnow);
    for (int i = now1; i < pieces.size(); ++i) {
        ui->textEdit->append(pieces.at(i));
    }
}

void MainWindow::on_ReplaceChar_clicked()
{
    string2int window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();

    //QChar chnow = stringnow[0];
    qDebug() << now1 << ' ' << now2;
    pieces[now1 - 1].replace(now2 - 1, 1, stringnow);  // replace is a void func
    for (int i = 0; i < pieces.size(); ++i) {
        ui->textEdit->append(pieces.at(i));
    }
}

void MainWindow::on_ReplaceString_clicked()
{
    twoString2int window;
    window.setModal(true);
    window.exec();
    QString allT = ui->textEdit->toPlainText();
    QStringList pieces = allT.split('\n');
    ui->textEdit->clear();
    if (now1 == 0) {
        now1 = 1;
        now2 = pieces.size();
    }
    if (stringnew == stringnow) return;
    for (int i = now1; i <= now2; ++i) {
        if (pieces[i - 1].contains(stringnow)) {
            QString newS = pieces[i - 1];
            int index = 0;
            while (newS.contains(stringnow) && index < pieces[i - 1].size()) {
                int newind = newS.indexOf(stringnow);
                if (newind == -1) break;
                newS.replace(newind, stringnow.size(), stringnew);
                index = newind + stringnow.size();
            }
            pieces[i - 1] = newS;
        }
    }
    for (auto i : pieces) {
        ui->textEdit->append(i);
    }
}
