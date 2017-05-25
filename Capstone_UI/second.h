#ifndef SECOND_H
#define SECOND_H

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "third.h"
#include <QMainWindow>

namespace Ui {
class second;
}

class second : public QDialog
{
    Q_OBJECT

public:
    explicit second(QWidget *parent = 0);
    ~second();

    void Connect();

signals:

private slots:
    void on_pushButton_clicked();

private:
    QTcpSocket *socket;
    Ui::second *ui;
};

#endif // SECOND_H
