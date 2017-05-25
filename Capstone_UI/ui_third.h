/********************************************************************************
** Form generated from reading UI file 'third.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRD_H
#define UI_THIRD_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_third
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_pic;
    QStatusBar *statusBar;

    void setupUi(QDialog *third)
    {
        if (third->objectName().isEmpty())
            third->setObjectName(QStringLiteral("third"));
        third->resize(400, 340);
        QFont font;
        font.setPointSize(9);
        third->setFont(font);
        centralWidget = new QWidget(third);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 401, 351));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(9, 270, 381, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        pushButton->setFont(font1);
        pushButton->setMouseTracking(false);
        pushButton->setFocusPolicy(Qt::StrongFocus);
        pushButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushButton->setAcceptDrops(false);
        pushButton->setToolTipDuration(-1);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"  background-color: rgb(255, 113, 19);"));
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);
        pushButton->setAutoDefault(true);
        pushButton->setFlat(false);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(9, 170, 381, 31));
        lineEdit_2->setToolTipDuration(-1);
        lineEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 203, 185);"));
        lineEdit_2->setFrame(false);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        lineEdit_2->setCursorPosition(0);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setClearButtonEnabled(false);
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(9, 214, 381, 31));
        lineEdit_3->setToolTipDuration(-1);
        lineEdit_3->setLayoutDirection(Qt::RightToLeft);
        lineEdit_3->setAutoFillBackground(false);
        lineEdit_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 203, 185);"));
        lineEdit_3->setFrame(false);
        lineEdit_3->setEchoMode(QLineEdit::Password);
        lineEdit_3->setCursorPosition(0);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(9, 126, 381, 31));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 203, 185);"));
        lineEdit->setFrame(false);
        lineEdit->setEchoMode(QLineEdit::Normal);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setClearButtonEnabled(false);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 100, 401, 251));
        graphicsView->setContextMenuPolicy(Qt::DefaultContextMenu);
        graphicsView->setAutoFillBackground(false);
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(237, 237, 237);"));
        graphicsView->setLocale(QLocale(QLocale::Korean, QLocale::SouthKorea));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setLineWidth(1);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setInteractive(true);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(-5, 0, 411, 111));
        graphicsView_2->setFrameShape(QFrame::NoFrame);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 131, 41));
        QFont font2;
        font2.setPointSize(18);
        label->setFont(font2);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(3, 60, 221, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_pic = new QLabel(centralWidget);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(267, 10, 81, 81));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_pic->sizePolicy().hasHeightForWidth());
        label_pic->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(2);
        label_pic->setFont(font3);
        label_pic->setAcceptDrops(false);
        label_pic->setLayoutDirection(Qt::LeftToRight);
        label_pic->setAutoFillBackground(true);
        label_pic->setFrameShadow(QFrame::Plain);
        label_pic->setScaledContents(true);
        label_pic->setAlignment(Qt::AlignCenter);
        graphicsView_2->raise();
        graphicsView->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        pushButton->raise();
        label->raise();
        label_2->raise();
        label_pic->raise();
        statusBar = new QStatusBar(third);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 23));
        QWidget::setTabOrder(graphicsView, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton);

        retranslateUi(third);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(third);
    } // setupUi

    void retranslateUi(QDialog *third)
    {
        third->setWindowTitle(QApplication::translate("third", "Login", 0));
#ifndef QT_NO_ACCESSIBILITY
        pushButton->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        pushButton->setText(QApplication::translate("third", "LogIn", 0));
        pushButton->setShortcut(QString());
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("third", "Password...", 0));
        lineEdit_2->setProperty("2", QVariant(QString()));
        lineEdit_3->setInputMask(QString());
        lineEdit_3->setPlaceholderText(QApplication::translate("third", "Root Password...", 0));
#ifndef QT_NO_ACCESSIBILITY
        lineEdit->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("third", "Username...", 0));
        lineEdit->setProperty("1", QVariant(QString()));
        label->setText(QApplication::translate("third", "Lock Insider", 0));
        label_2->setText(QApplication::translate("third", "Enter your Username and Password...", 0));
        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class third: public Ui_third {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRD_H
