#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vigenere.h"
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Q_msg = ui->textEdit->toPlainText();
    QString Q_key = ui->textEdit_2->toPlainText();


    std::string ans;
    std::string msg = Q_msg.toStdString();
    std::string key = Q_key.toStdString();

    bool check_msg = check(msg);
    bool check_key = check(key);

    if (check_msg && check_key){
        ans = encryption(msg, key);
        QString Q_ans;
        Q_ans = QString::fromStdString(ans);

        ui->textBrowser_3->setText(Q_ans);
    } else {
        ui->textBrowser_3->setText("Invalid type!");
    }

}


void MainWindow::on_actionDecrypto_triggered()
{
    form.show();
    //this->setVisible(false);
}
