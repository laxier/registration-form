#include "dialog_register.h"
#include "ui_dialog_register.h"
#include<QString>
#include<QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
void WriteUser(QString line){

    QString filename = QDir::currentPath() + "data.txt";
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream stream(&file);
        stream <<"\n" << line;
        file.flush();
        file.close();
    }
}

bool CheckUser(QString line){
    bool checker = true;
    QString filename = QDir::currentPath() + "data.txt";
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString user_data;
        do
        {
            user_data = stream.readLine();
            if(user_data == line){
                checker = false;
                break;
           }
        }while(!user_data.isNull());
        file.close();
    }
    return checker;
}


dialog_register::dialog_register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_register)
{
    ui->setupUi(this);
}

dialog_register::~dialog_register()
{
    delete ui;
}
void dialog_register::on_send_clicked()
{
    QString login = ui->login->text();
        QString password = ui->password->text();
        QString email = ui->email->text();
        if (password != "" && login != "" && email != ""){
            QString line = login + "_" + password + " " + email;
            if (CheckUser(line)){
                WriteUser(line);
                QMessageBox::information(this,"Successful registration", "You are registered now.");
                this->close();
            }
            else{
                QMessageBox::warning(this,"Re-registration", "This user is already registered.\nTry to log in.");
                this->close();

            }
        }
        else{
            QMessageBox::warning(this,"Error", "Enter all fields.");
        }
}
