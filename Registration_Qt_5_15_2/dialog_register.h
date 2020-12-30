#ifndef DIALOG_REGISTER_H
#define DIALOG_REGISTER_H

#include <QDialog>

namespace Ui {
class dialog_register;
}

class dialog_register : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_register(QWidget *parent = nullptr);
    ~dialog_register();

private slots:
    void on_send_clicked();

private:
    Ui::dialog_register *ui;
};

#endif // DIALOG_REGISTER_H
