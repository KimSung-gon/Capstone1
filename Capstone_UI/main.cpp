#include "capstone.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Capstone w;
    w.show();
    return a.exec();
}
