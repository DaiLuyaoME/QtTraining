#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    connect(ui->myButton,&QPushButton::clicked,this,&Dialog::myButtonClicked);
    myTimer=new QTimer(this);
    connect(ui->myButton,SIGNAL(clicked()),this,SLOT(myButtonClicked()));
    connect(ui->changeButton,&QPushButton::clicked,this,&Dialog::changeButtonClicked);
    connect(myTimer,&QTimer::timeout,this,&Dialog::timeout);
    connect(this,&Dialog::threeSecondReachead,this,&Dialog::handleThreeSecond);
    myTimer->start(1000);
    count=0;
}

Dialog::~Dialog()
{
    delete ui;
}

long Dialog::random(double start, double end)
{
        return (long int)(start + (end - start)*rand()/(RAND_MAX));
}

void Dialog::on_pushButton_clicked()
{
    exit(0);
}

void Dialog::myButtonClicked()
{
    exit(0);
}

void Dialog::changeButtonClicked()
{
    QString temp=ui->lineEdit->text();
    ui->label->setText(temp);
}

void Dialog::timeout()
{
    count++;
    ui->timeLabel->setText(QString("%1").arg(count));
    if(count==3)
    {
        emit threeSecondReachead();
    }
}

void Dialog::handleThreeSecond()
{
    ui->label->setText(QString("Three Seconds Passed!"));
}
