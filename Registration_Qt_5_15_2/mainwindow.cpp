#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_register.h"
#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDir>

bool Check(QString line){
    bool checker = false;
    QString filename = QDir::currentPath() + "data.txt";
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString user_data;
        QString email;
        do
        {
            stream >> user_data >> email;
            if(user_data == line){
                checker = true;
                break;
           }
        }while(!user_data.isNull());
        file.close();
    }
    return checker;
}

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


void MainWindow::on_submit_clicked()
{
    QString login = ui->login->text();
        QString password = ui->password->text();
        QString line = login + "_" + password;
        if (Check(line)){
            QMessageBox::information(this, "Successful login", "Welcome to test.com!");
        }
        else{
            QMessageBox::warning(this, "Failed to log in", "Wrong login or password \nTry to register instead.");
        }
}

void MainWindow::on_register_button_clicked()
{
    dialog_register window;
    window.setModal(true);
    window.exec();
}
