#include "thirdui.h"
#include "ui_thirdui.h"
#include "second_dialog.h"

thirdUi::thirdUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdUi)
{
    ui->setupUi(this);
}

thirdUi::~thirdUi()
{
    delete ui;
}

void thirdUi::on_pushButton_clicked()
{
    close();
}
