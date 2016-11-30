#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void digitClicked();            //0123456789
    void additiveOpClicked();       //+ -
    void multiplicativeOpClicked(); //x /
    void equalClicked();            //=
    void pointClicked();            //.
    void changeSignClicked();       //+/-
    void deleteClicked();           //<
    void clearEntryClicked();       //CE
    void clearClicked();            //C

private:
    //variables
    bool waitingForOp = true;
    double lhs;
    double rhs;
    QString lastAdditiveOp;
    QString lastMultiplicativeOp;
    Ui::MainWindow *ui;
    //functiosn
    bool rhsNotZero();
    void abort(); //throws error
    void calculate(double rhs, const QString& op); //applies op
};

#endif // MAINWINDOW_H
