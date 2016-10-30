#include "dialog.h"
#include "ui_dialog.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#define MAXSIZE 10
#define TIME_INTERVAL 300
//#include "dialog.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_splotButton_clicked()
{
    staticPlot();
}

//静态曲线绘制
void Dialog::staticPlot()
{
    staticline->clear();
    for(double x=1;x<10;x+=0.1)
    {
        staticline->append(x,sin(x));
    }
}

//清楚已有静态曲线
void Dialog::on_sclearButton_clicked()
{
    staticline->clear();
}

//更新实时绘图窗口
void Dialog::updateDynamicPlot()
{
    if(buffer.size()<MAXSIZE)
    {
    buffer.append((random(-1,1)));
    dynamicline->append(QPointF(buffer.size(),buffer.at(buffer.size()-1)));
    }
    else
    {
        buffer.pop_front();
        buffer.append(random(-1,1));
        dynamicline->clear();
        for(int i=0;i<MAXSIZE;++i)
            dynamicline->append(QPointF(i,buffer.at(i)));
    }

}
//随机数生成器
double Dialog::random(double start, double end)
{
    return (double)(start + (end - start)*rand()/(RAND_MAX));
}

//初始化函数
void Dialog::init()
{
    staticChart = new QChart;
    dynamicChart = new QChart;
    staticline = new QLineSeries;
    dynamicline = new QLineSeries;
    for(double x=0;x<10;x+=0.1)
    {
        staticline->append(x,sin(x));
    }
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, MAXSIZE);
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1.5, 1.5); //设置坐标轴范围
    staticChart->addSeries(staticline); //添加绘图曲线
    dynamicChart->addSeries(dynamicline);
    dynamicChart->setAxisX(axisX,dynamicline); //添加坐标轴
    dynamicChart->setAxisY(axisY,dynamicline);
    ui->staticPlot->setChart(staticChart); //添加待显示的图标
    ui->dynamicPlot->setChart(dynamicChart);
    mytimer=new QTimer;
    //关联定时器，用于实时刷新曲线数据
    connect(mytimer,&QTimer::timeout,this,&Dialog::updateDynamicPlot);
}

//开始实时数据绘制
void Dialog::on_dplotButton_clicked()
{
    mytimer->start(TIME_INTERVAL);
}

//停止实时数据绘制
void Dialog::on_dstopButton_clicked()
{
    mytimer->stop();
}
