#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

//==Allowing for new slots============================================================//
    //cancel auto default
    push_0->setAutoDefault(false);
    push_1->setAutoDefault(false);
    push_2->setAutoDefault(false);
    push_3->setAutoDefault(false);
    push_4->setAutoDefault(false);
    push_5->setAutoDefault(false);
    push_6->setAutoDefault(false);
    push_7->setAutoDefault(false);
    push_8->setAutoDefault(false);
    push_9->setAutoDefault(false);
    push_clear->setAutoDefault(false);
    push_clearEntry->setAutoDefault(false);
    push_decimal->setAutoDefault(false);
    push_delete->setAutoDefault(false);
    push_divide->setAutoDefault(false);
    push_equal->setAutoDefault(false);
    push_minus->setAutoDefault(false);
    push_multiply->setAutoDefault(false);
    push_plus->setAutoDefault(false);
    push_sign->setAutoDefault(false);

    //connect buttons
    connect(push_0, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_1, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_2, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_3, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_4, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_5, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_6, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_7, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_8, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_9, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(push_clear, SIGNAL(clicked()), this, SLOT(clearClicked()));
    connect(push_clearEntry, SIGNAL(clicked()), this, SLOT(clearEntryClicked()));
    connect(push_decimal, SIGNAL(clicked()), this, SLOT(pointClicked()));
    connect(push_delete, SIGNAL(clicked()), this, SLOT(deleteClicked()));
    connect(push_divide, SIGNAL(clicked()), this, SLOT(OpClicked()));
    connect(push_equal, SIGNAL(clicked()), this, SLOT(equalClicked()));
    connect(push_minus, SIGNAL(clicked()), this, SLOT(OpClicked()));
    connect(push_multiply, SIGNAL(clicked()), this, SLOT(OpClicked()));
    connect(push_plus, SIGNAL(clicked()), this, SLOT(OpClicked()));
    connect(push_sign, SIGNAL(clicked()), this, SLOT(changeSignClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//==Slots===========================================================================//
void MainWindow::digitClicked(){
    if(lastOp == "=" && !isDecimal) //if the last operation was = and number isn't a decimal, clear the screen
        MainWindow::clearClicked();
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender()); //find digit clicked
    lineEdit->setText(lineEdit->text() + clickedButton->text()); //add to display
    lineEdit->end(false);
    QCoreApplication::processEvents(); //update
}

void MainWindow::OpClicked(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender()); //find operation
    int newPos = lineEdit->cursorPosition();

    //Extract the first number or calculate
    if(!opExists){ //there has not been an operation, lineEdit should only contain the first number
        lhs = lineEdit->text().toDouble(); //put first number into lhs
    }
    else{ //there has been a last operation
        lineEdit->setSelection(opPos + 1, newPos); //one after last operation to the last element
        rhs = lineEdit->selectedText().toDouble(); //put selected text (2nd number) into rhs
        calculate(lastOp); //calculate
    }

    //Modify last operation
    lastOp = clickedButton->text();
    opPos = newPos; //position of newest operation
    isDecimal = false;
    opExists = true;

    lineEdit->setText(QString::number(lhs) + lastOp);//set to the new lhs with the last operation
    lineEdit->end(false);
    QCoreApplication::processEvents();
}

void MainWindow::equalClicked(){
    if(lastOp == "="){ //do nothing if the person pressed equal again
        return;
    }else if(opPos == 0){ //why would you press equal before an operation? but just for completion's sake...
        return;
    }
    //repeat situation when there is a last operation
    lineEdit->setSelection(opPos + 1, lineEdit->cursorPosition()); //one after last operation to the last element
    rhs = lineEdit->selectedText().toDouble(); //put selected text (2nd number) into rhs
    calculate(lastOp); //calculate

    opExists = false;
    lastOp = "="; //set last operation as equal
    lineEdit->setText(QString::number(lhs));//set to the new lhs
    lineEdit->end(false);
    QCoreApplication::processEvents();
}

void MainWindow::pointClicked(){
    isDecimal = true;
    //add a decimal to lineEdit and process
    lineEdit->setText(lineEdit->text() + QString("."));
    lineEdit->end(false);
    QCoreApplication::processEvents();
}

void MainWindow::changeSignClicked(){
    if(isNegative){ //delete -
        lineEdit->setCursorPosition(1); //start after -
        lineEdit->end(true); //select all the way to the end
        lineEdit->setText(lineEdit->selectedText());
        isNegative = false;
    }else{ //add - to the beginning
        isNegative = true;
        lineEdit->setText(QString("-") + lineEdit->text());
    }
    lineEdit->end(false);
    QCoreApplication::processEvents();
}

void MainWindow::deleteClicked(){
    lineEdit->backspace();
    QCoreApplication::processEvents();
}

void MainWindow::clearEntryClicked(){ //deletes everything after the last operation
    if(opPos == 0) //there is no last operation, clear.
        MainWindow::clearClicked();
    else{ //there is a last operation
        lineEdit->setCursorPosition(opPos + 1); //select everything after last operation
        lineEdit->end(true);
        lineEdit->backspace(); //delete
    }
    QCoreApplication::processEvents();
}

void MainWindow::clearClicked(){
    //set everything back to zero
    lhs = 0;
    rhs = 0;
    opPos = 0;
    lineEdit->clear();
    QCoreApplication::processEvents();

}

//==Functions=======================================================================//
void MainWindow::abort(){
    lineEdit->setText("Error");
    QCoreApplication::processEvents();
}

void MainWindow::calculate(const QString& op){
    //negative operations don't work
    if(rhsZero() && (op == "/")){ //cannot divide by 0
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
}

bool MainWindow::rhsZero(){
    return (rhs == 0 ? true : false);
}
