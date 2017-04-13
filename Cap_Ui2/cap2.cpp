#include "cap2.h"
#include "ui_cap2.h"

Cap2::Cap2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cap2)
{
    ui->setupUi(this);
}

Cap2::~Cap2()
{
    delete ui;
}
