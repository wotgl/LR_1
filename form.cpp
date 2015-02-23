#include "form.h"
#include "ui_form.h"
#include "vigenere.h"
#include <string>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QString Q_msg = ui->textEdit->toPlainText();
    QString Q_key = ui->textEdit_2->toPlainText();


    std::string ans;
    std::string msg = Q_msg.toStdString();
    std::string key = Q_key.toStdString();

    bool check_msg = check(msg);
    bool check_key = check(key);

    if (check_msg && check_key){
        ans = decryption(msg, key);
        QString Q_ans;
        Q_ans = QString::fromStdString(ans);

        ui->textBrowser_3->setText(Q_ans);
    } else {
        ui->textBrowser_3->setText("Invalid type!");
    }
}


