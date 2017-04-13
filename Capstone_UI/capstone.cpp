#include "capstone.h"
#include "ui_capstone.h"
#include <QMessageBox>
#include "second_dialog.h"

Capstone::Capstone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Capstone)
{
    ui->setupUi(this);
}

Capstone::~Capstone()
{
    delete ui;
}

void Capstone::on_login_btn_clicked()
{
   QMessageBox::information(this,tr("Message"),tr("Login Succeed"));
   this->hide();
   second_Dialog secdialog;
   secdialog.setModal(true);
   secdialog.exec();
}

