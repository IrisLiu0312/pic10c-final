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
    Ui::MainWindow *ui;
    void abort(); //throws error
    bool calculate(double rhs, const QString& op); //applies op
    double sum;
    QString lastAdditiveOp;
    QString lastMultiplicativeOp;
};

#endif // MAINWINDOW_H
