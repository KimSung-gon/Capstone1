/********************************************************************************
** Form generated from reading UI file 'second.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_H
#define UI_SECOND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_second
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *second)
    {
        if (second->objectName().isEmpty())
            second->setObjectName(QStringLiteral("second"));
        second->resize(400, 300);
        second->setMouseTracking(false);
        second->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushButton = new QPushButton(second);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 250, 80, 26));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));
        pushButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushButton->setAcceptDrops(false);
        pushButton->setAutoDefault(false);

        retranslateUi(second);

        QMetaObject::connectSlotsByName(second);
    } // setupUi

    void retranslateUi(QDialog *second)
    {
        second->setWindowTitle(QApplication::translate("second", "Dialog", 0));
        pushButton->setText(QApplication::translate("second", "Logout", 0));
    } // retranslateUi

};

namespace Ui {
    class second: public Ui_second {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_H
