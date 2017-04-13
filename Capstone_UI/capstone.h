#ifndef CAPSTONE_H
#define CAPSTONE_H
#include"second_dialog.h"
#include <QMainWindow>

namespace Ui {
class Capstone;
}

class Capstone : public QMainWindow
{
    Q_OBJECT

public:
    explicit Capstone(QWidget *parent = 0);
    ~Capstone();

private slots:
    void on_login_btn_clicked();

    //void on_pushButton_clicked();

private:
    Ui::Capstone *ui;
};

#endif // CAPSTONE_H
