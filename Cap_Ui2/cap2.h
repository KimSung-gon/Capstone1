#ifndef CAP2_H
#define CAP2_H

#include <QMainWindow>

namespace Ui {
class Cap2;
}

class Cap2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cap2(QWidget *parent = 0);
    ~Cap2();

private:
    Ui::Cap2 *ui;
};

#endif // CAP2_H
