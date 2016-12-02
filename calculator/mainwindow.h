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
    void OpClicked();               //+ - x /
    void equalClicked();            //=
    void pointClicked();            //.
    void changeSignClicked();       //+/-
    void deleteClicked();           //<
    void clearEntryClicked();       //CE
    void clearClicked();            //C

private:
    //variables
    double lhs;
    double rhs;
    int opPos = 0;
    QString lastOp;
    bool isDecimal = false;
    bool isNegative = false;
    bool opExists = false;
    Ui::MainWindow *ui;

    //functions
    bool rhsZero();
    void abort(); //throws error
    void calculate(const QString& op); //applies op
};

#endif // MAINWINDOW_H
