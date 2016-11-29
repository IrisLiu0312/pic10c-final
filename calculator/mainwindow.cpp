#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//slots
void MainWindow::digitClicked(){
    //find digit
    display += digit;
    QCoreApplication::processEvents();
}

void MainWindow::additiveOpClicked(){
    //find operation
    //pull information from display out into rhs
    calculate(rhs, op);
    display = lhs;
    display += op;
    QCoreApplication::processEvents();
}

void MainWindow::multiplicativeOpClicked(){
    //find operation
    //pull information from display out into rhs
    calculate(rhs, op);
    display = lhs;
    display += op;
    QCoreApplication::processEvents();
}

void MainWindow::equalClicked(){
    //pull info from display out into rhs
    calculate(rhs, op);
    display = lhs;
    QCoreApplication::processEvents();
}

void MainWindow::pointClicked(){
    isDecimal = true;
    display += ".";
    QCoreApplication::processEvents();
}

void MainWindow::changeSignClicked(){
    rhs *= -1;
    display = rhs;
    QCoreApplication::processEvents();
}

void MainWindow::deleteClicked(){
    if(rhsNotZero()){
        rhs -= (rhs % 10);
        display = rhs;
        QCoreApplication::processEvents();
    }
}

void MainWindow::clearEntryClicked(){
    rhs = 0;
    display = "0";
    QCoreApplication::processEvents();
}

void MainWindow::clearClicked(){
    lhs = 0;
    rhs = 0;
    display = "0";
    QCoreApplication::processEvents();

}

//functions
void MainWindow::abort(){
    display = "Error";
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
    display = lhs;
    QCoreApplication::processEvents();
}

bool MainWindow::rhsNotZero(){
    return (rhs == 0 ? false : true);
}
