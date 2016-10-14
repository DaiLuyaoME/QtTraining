#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    //随机数生成函数，用于生成区间[start,end]之间的随机数
    long int random(double start, double end);

private slots:
    void on_pushButton_clicked();
    void myButtonClicked();
    void changeButtonClicked();
    void timeout();
    void handleThreeSecond();
signals:
    void threeSecondReachead();


private:
    Ui::Dialog *ui;
    QTimer * myTimer;
    int count;

};

#endif // DIALOG_H
