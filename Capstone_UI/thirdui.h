#ifndef THIRDUI_H
#define THIRDUI_H

#include <QDialog>

namespace Ui {
class thirdUi;
}

class thirdUi : public QDialog
{
    Q_OBJECT

public:
    explicit thirdUi(QWidget *parent = 0);
    ~thirdUi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::thirdUi *ui;
};

#endif // THIRDUI_H
