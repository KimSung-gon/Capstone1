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

project::project(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::project)
{
    //system(qPrintable("/home/kimsunggon/바탕화면/./a.out -d"));
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    QPixmap pix("/home/kimsunggon/바탕화면/Login.png");
    ui->label_pic->setPixmap(pix);

 }

project::~project()
{
    delete ui;
}

void project::on_pushButton_clicked()
{
    QString Xmax, Ymax, Zmax, Kmax;

    Xmax = ui->lineEdit->text();
    Ymax = ui->lineEdit_2->text();
    Zmax = ui->lineEdit_3->text();

   socket->connectToHost("192.168.0.18",10000);

   socket->write("{$}");
   socket->write(Xmax.toUtf8());
   socket->write("{$}");
   socket->write(Ymax.toUtf8());
   socket->write("{$}");
   socket->write(Zmax.toUtf8());

   if(socket->waitForConnected(30000))
   {
        socket->waitForBytesWritten(10000);
        //qDebug() << "Reading: " << socket->bytesAvailable();
        //qDebug() << socket->readAll();
        socket->abort();
        socket->connectToHost("10.30.119.196",10000);

        QString k;

           if (socket->waitForReadyRead(-1))
           {
               QByteArray message = socket->readAll();// Read message
               k = message.data();
               //qDebug() << QString(k);
           }
           else
           {
               qDebug() << "ERROR: could not receive message";
           }

        Kmax = QString(k);
        socket->close();
    }
    else
    {
      qDebug() << "Not Connected!";
    }
    if(Kmax=="[test] true\n")
    {
        this->hide();
        QMessageBox::warning(this, "Login", "Login Succeed !");
        second second;
        second.setModal(true);
        second.exec();
    }
    else
    {
        this->hide();
        QMessageBox::warning(this, "Login", "Login failed !");
        third third;
        third.setModal(true);
        third.exec();
    }
}
