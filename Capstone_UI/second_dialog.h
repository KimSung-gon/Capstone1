#ifndef SECOND_DIALOG_H
#define SECOND_DIALOG_H

#include <QDialog>

namespace Ui {
class second_Dialog;
}

class second_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit second_Dialog(QWidget *parent = 0);
    ~second_Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::second_Dialog *ui;
};

#endif // SECOND_DIALOG_H
