#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->show();

    //==Buttons=============================================//
    //0123456789
    QPushButton *button[10];
    button[0] = new QPushButton("0");
    QObject::connect(button[0], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[1] = new QPushButton("1");
    QObject::connect(button[1], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[2] = new QPushButton("2");
    QObject::connect(button[2], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[3] = new QPushButton("3");
    QObject::connect(button[3], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[4] = new QPushButton("4");
    QObject::connect(button[4], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[5] = new QPushButton("5");
    QObject::connect(button[5], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[6] = new QPushButton("6");
    QObject::connect(button[6], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[7] = new QPushButton("7");
    QObject::connect(button[7], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[8] = new QPushButton("8");
    QObject::connect(button[8], SIGNAL(clicked()), &w, SLOT(digitClicked()));
    button[9] = new QPushButton("9");
    QObject::connect(button[9], SIGNAL(clicked()), &w, SLOT(digitClicked()));

    //.+/-
    QPushButton *decimal = new QPushButton(".");
    QObject::connect(decimal, SIGNAL(clicked()), &w, SLOT(pointClicked()));
    QPushButton *sign = new QPushButton("+/-");
    QObject::connect(sign, SIGNAL(clicked()), &w, SLOT(changeSignClicked()));

    //+ -
    QPushButton *plus = new QPushButton("+");
    QObject::connect(plus, SIGNAL(clicked()), &w, SLOT(additiveOpClicked()));
    QPushButton *minus = new QPushButton("-");
    QObject::connect(minus, SIGNAL(clicked()), &w, SLOT(additiveOpClicked()));

    //* /
    QPushButton *multiply = new QPushButton("*");
    QObject::connect(multiply, SIGNAL(clicked()), &w, SLOT(multiplicativeOpClicked()));
    QPushButton *divide = new QPushButton("/");
    QObject::connect(divide, SIGNAL(clicked()), &w, SLOT(multiplicativeOpClicked()));

    //C CE
    QPushButton *clear = new QPushButton("C");
    QObject::connect(clear, SIGNAL(clicked()), &w, SLOT(clearClicked()));
    QPushButton *clearEntry = new QPushButton("CE");
    QObject::connect(clearEntry, SIGNAL(clicked()), &w, SLOT(clearEntryClicked()));

    //delete, =
    QPushButton *del = new QPushButton("Delete");
    QObject::connect(del, SIGNAL(clicked()), &w, SLOT(deleteClicked()));
    QPushButton *equal = new QPushButton("=");
    QObject::connect(equal, SIGNAL(clicked()), &w, SLOT(equalClicked()));

    QLineEdit *label = new QLineEdit("0");
    label->setReadOnly(true);

    //==Layout==============================================//
    QGridLayout *layout = new QGridLayout;
    QHBoxLayout *bar[5];
    bar[0]->addWidget(clearEntry);
    bar[0]->addWidget(clear);
    bar[0]->addWidget(del);
    bar[0]->addWidget(divide);

    bar[1]->addWidget(button[1]);
    bar[1]->addWidget(button[2]);
    bar[1]->addWidget(button[3]);
    bar[1]->addWidget(multiply);

    bar[2]->addWidget(button[4]);
    bar[2]->addWidget(button[5]);
    bar[2]->addWidget(button[6]);
    bar[2]->addWidget(plus);

    bar[3]->addWidget(button[7]);
    bar[3]->addWidget(button[8]);
    bar[3]->addWidget(button[9]);
    bar[3]->addWidget(minus);

    bar[4]->addWidget(sign);
    bar[4]->addWidget(button[0]);
    bar[4]->addWidget(decimal);
    bar[4]->addWidget(equal);

    layout->addWidget(label, 0, 0);
    for(size_t i = 0; i < 5; ++i)
        layout->addLayout(bar[i],i+1,0);

    QWidget *control = new QWidget;
    control->setLayout(layout);
    control->setWindowTitle("Calculator");
    control->show();

    return a.exec();
}
