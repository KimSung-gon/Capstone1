#ifndef THIRD_H
#define THIRD_H

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "second.h"
#include <QMainWindow>

namespace Ui {
class third;
}

class third : public QDialog
{
    Q_OBJECT

public:
    explicit third(QWidget *parent = 0);
    ~third();

    void Connect();

signals:

private slots:
    void on_pushButton_clicked();

private:
    QTcpSocket *socket;
    Ui::third *ui;
};

#endif // THIRD_H
