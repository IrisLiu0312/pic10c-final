/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *push_2;
    QPushButton *push_clearEntry;
    QPushButton *push_8;
    QPushButton *push_5;
    QPushButton *push_9;
    QPushButton *push_4;
    QPushButton *push_sign;
    QPushButton *push_6;
    QPushButton *push_plus;
    QPushButton *push_minus;
    QPushButton *push_equal;
    QPushButton *push_3;
    QPushButton *push_delete;
    QPushButton *push_clear;
    QPushButton *push_multiply;
    QPushButton *push_1;
    QPushButton *push_7;
    QPushButton *push_0;
    QPushButton *push_decimal;
    QPushButton *push_divide;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 60, 401, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        push_2 = new QPushButton(gridLayoutWidget);
        push_2->setObjectName(QStringLiteral("push_2"));

        gridLayout->addWidget(push_2, 2, 2, 1, 1);

        push_clearEntry = new QPushButton(gridLayoutWidget);
        push_clearEntry->setObjectName(QStringLiteral("push_clearEntry"));

        gridLayout->addWidget(push_clearEntry, 1, 1, 1, 1);

        push_8 = new QPushButton(gridLayoutWidget);
        push_8->setObjectName(QStringLiteral("push_8"));

        gridLayout->addWidget(push_8, 4, 2, 1, 1);

        push_5 = new QPushButton(gridLayoutWidget);
        push_5->setObjectName(QStringLiteral("push_5"));

        gridLayout->addWidget(push_5, 3, 2, 1, 1);

        push_9 = new QPushButton(gridLayoutWidget);
        push_9->setObjectName(QStringLiteral("push_9"));

        gridLayout->addWidget(push_9, 4, 3, 1, 1);

        push_4 = new QPushButton(gridLayoutWidget);
        push_4->setObjectName(QStringLiteral("push_4"));

        gridLayout->addWidget(push_4, 3, 1, 1, 1);

        push_sign = new QPushButton(gridLayoutWidget);
        push_sign->setObjectName(QStringLiteral("push_sign"));

        gridLayout->addWidget(push_sign, 5, 1, 1, 1);

        push_6 = new QPushButton(gridLayoutWidget);
        push_6->setObjectName(QStringLiteral("push_6"));

        gridLayout->addWidget(push_6, 3, 3, 1, 1);

        push_plus = new QPushButton(gridLayoutWidget);
        push_plus->setObjectName(QStringLiteral("push_plus"));

        gridLayout->addWidget(push_plus, 3, 4, 1, 1);

        push_minus = new QPushButton(gridLayoutWidget);
        push_minus->setObjectName(QStringLiteral("push_minus"));

        gridLayout->addWidget(push_minus, 4, 4, 1, 1);

        push_equal = new QPushButton(gridLayoutWidget);
        push_equal->setObjectName(QStringLiteral("push_equal"));

        gridLayout->addWidget(push_equal, 5, 4, 1, 1);

        push_3 = new QPushButton(gridLayoutWidget);
        push_3->setObjectName(QStringLiteral("push_3"));

        gridLayout->addWidget(push_3, 2, 3, 1, 1);

        push_delete = new QPushButton(gridLayoutWidget);
        push_delete->setObjectName(QStringLiteral("push_delete"));

        gridLayout->addWidget(push_delete, 1, 3, 1, 1);

        push_clear = new QPushButton(gridLayoutWidget);
        push_clear->setObjectName(QStringLiteral("push_clear"));

        gridLayout->addWidget(push_clear, 1, 2, 1, 1);

        push_multiply = new QPushButton(gridLayoutWidget);
        push_multiply->setObjectName(QStringLiteral("push_multiply"));

        gridLayout->addWidget(push_multiply, 2, 4, 1, 1);

        push_1 = new QPushButton(gridLayoutWidget);
        push_1->setObjectName(QStringLiteral("push_1"));

        gridLayout->addWidget(push_1, 2, 1, 1, 1);

        push_7 = new QPushButton(gridLayoutWidget);
        push_7->setObjectName(QStringLiteral("push_7"));

        gridLayout->addWidget(push_7, 4, 1, 1, 1);

        push_0 = new QPushButton(gridLayoutWidget);
        push_0->setObjectName(QStringLiteral("push_0"));

        gridLayout->addWidget(push_0, 5, 2, 1, 1);

        push_decimal = new QPushButton(gridLayoutWidget);
        push_decimal->setObjectName(QStringLiteral("push_decimal"));

        gridLayout->addWidget(push_decimal, 5, 3, 1, 1);

        push_divide = new QPushButton(gridLayoutWidget);
        push_divide->setObjectName(QStringLiteral("push_divide"));

        gridLayout->addWidget(push_divide, 1, 4, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 4);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        push_2->setText(QApplication::translate("MainWindow", "2", 0));
        push_clearEntry->setText(QApplication::translate("MainWindow", "CE", 0));
        push_8->setText(QApplication::translate("MainWindow", "8", 0));
        push_5->setText(QApplication::translate("MainWindow", "5", 0));
        push_9->setText(QApplication::translate("MainWindow", "9", 0));
        push_4->setText(QApplication::translate("MainWindow", "4", 0));
        push_sign->setText(QApplication::translate("MainWindow", "\302\261", 0));
        push_6->setText(QApplication::translate("MainWindow", "6", 0));
        push_plus->setText(QApplication::translate("MainWindow", "+", 0));
        push_minus->setText(QApplication::translate("MainWindow", "-", 0));
        push_equal->setText(QApplication::translate("MainWindow", "=", 0));
        push_3->setText(QApplication::translate("MainWindow", "3", 0));
        push_delete->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        push_clear->setText(QApplication::translate("MainWindow", "C", 0));
        push_multiply->setText(QApplication::translate("MainWindow", "\303\227", 0));
        push_1->setText(QApplication::translate("MainWindow", "1", 0));
        push_7->setText(QApplication::translate("MainWindow", "7", 0));
        push_0->setText(QApplication::translate("MainWindow", "0", 0));
        push_decimal->setText(QApplication::translate("MainWindow", ".", 0));
        push_divide->setText(QApplication::translate("MainWindow", "\303\267", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
