#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    push_1->setAutoDefault(false);

    //connect buttons?
    connect(push_1, SIGNAL(clicked()), this, SLOT(digitClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//slots
void MainWindow::digitClicked(){
    //find digit clicked
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    //add to display
    lineEdit->setText(lineEdit->text() + clickedButton->text());
    QCoreApplication::processEvents();
}

void MainWindow::additiveOpClicked(){
    //find operation
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    //pull information from display out into rhs
    //calculate(rhs, op);
    //add to display
    lineEdit->setText(lineEdit->text() + clickedButton->text());
    QCoreApplication::processEvents();
}

void MainWindow::multiplicativeOpClicked(){
    //find operation
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    //pull information from display out into rhs
    //calculate(rhs, op);
    lineEdit->setText(lineEdit->text() + clickedButton->text());
    QCoreApplication::processEvents();
}

void MainWindow::equalClicked(){
    //pull info from display out into rhs
    //calculate(rhs, op);
}

void MainWindow::pointClicked(){
    lineEdit->setText(lineEdit->text() + QString("."));
    QCoreApplication::processEvents();
}

void MainWindow::changeSignClicked(){
    rhs *= -1;
    lineEdit->setText(QString("-") + lineEdit->text());
    QCoreApplication::processEvents();
}

void MainWindow::deleteClicked(){
    lineEdit->backspace();
    QCoreApplication::processEvents();
}

void MainWindow::clearEntryClicked(){
    //implement
    QCoreApplication::processEvents();
}

void MainWindow::clearClicked(){
    //set everything back to zero
    lhs = 0;
    rhs = 0;
    lineEdit->setText("0");
    QCoreApplication::processEvents();

}

//functions
void MainWindow::abort(){
    lineEdit->setText("Error");
    QCoreApplication::processEvents();
}

void MainWindow::calculate(double rhs, const QString& op){
    if(!rhsNotZero() && (op == "/")){ //cannot divide by 0
        abort();
        return;
    }
    if(op == "+")
        lhs += rhs;
    else if(op == "-")
        lhs -= rhs;
    else if(op == "*")
        lhs *= rhs;
    else
        lhs /= rhs;
    lineEdit->setText(QString::number(lhs));
    QCoreApplication::processEvents();
}

bool MainWindow::rhsNotZero(){
    return (rhs == 0 ? false : true);
}
