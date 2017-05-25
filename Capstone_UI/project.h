#ifndef PROJECT_H
#define PROJECT_H

#include <QMainWindow>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "second.h"
#include <QDialog>
#include <QMainWindow>

namespace Ui {
class project;
}

class project : public QMainWindow
{
    Q_OBJECT

public:
    explicit project(QWidget *parent = 0);
    ~project();

     void Connect();

signals:
     void connected();
     void disconnect();
     void bytesWritten(qint64 bytes);
     void readyRead();

private slots:
    void on_pushButton_clicked();

private:
    QTcpSocket *socket;
    Ui::project *ui;
};

#endif // PROJECT_H
