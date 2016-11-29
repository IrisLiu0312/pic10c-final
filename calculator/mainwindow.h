#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
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
    double lhs;
    double rhs;
    bool isDecimal = false;
    Ui::MainWindow *ui;
    QString display;
    QString lastAdditiveOp;
    QString lastMultiplicativeOp;
    void abort(); //throws error
    void calculate(double rhs, const QString& op); //applies op
    bool rhsNotZero();
};

#endif // MAINWINDOW_H
