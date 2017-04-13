#include "second_dialog.h"
#include <QMessageBox>
#include "ui_second_dialog.h"
#include "thirdui.h"


second_Dialog::second_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_Dialog)
{
    ui->setupUi(this);
}

second_Dialog::~second_Dialog()
{
    delete ui;
}

void second_Dialog::on_pushButton_clicked()
{
    this->hide();
    thirdUi thirdui;
    thirdui.setModal(true);
    thirdui.exec();
}
