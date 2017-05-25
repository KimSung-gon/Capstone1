#include "second.h"
#include "ui_second.h"
#include <QMessageBox>
#include "third.h"
#include "ui_third.h"
#include <QTcpSocket>
#include <QLocalSocket>
#include <QtNetwork>

#include "project.h"
#include "ui_project.h"
#include "second.h"
#include <QMessageBox>
#include <QLocalSocket>
#include <QTextStream>
#include <QCoreApplication>
#include <QApplication>
#include <QTcpSocket>
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <stdio.h>
#include "third.h"
#include <QtWidgets>
#include <QtNetwork>


second::second(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

}

second::~second()
{
    delete ui;
}

void second::on_pushButton_clicked()
{
    QString i = "false";
    socket->connectToHost("10.30.118.41",9000);
    socket->write(i.toUtf8());
    qDebug() << i.toUtf8();
    //socket->waitForBytesWritten(10000);

         //qDebug() << "Connected!";
         socket->waitForBytesWritten(10000);
         //qDebug() << "Reading: " << socket->bytesAvailable();
         qDebug() << socket->readAll();

         socket->close();
         socket->abort();

    this->hide();
    //QMessageBox::warning(this, "Login", "logout !");
    third third;
    third.setModal(true);
    third.exec();
}

