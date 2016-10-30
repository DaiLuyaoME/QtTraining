#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QTimer>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_splotButton_clicked();
    void on_sclearButton_clicked();
    void updateDynamicPlot();

    void on_dplotButton_clicked();

    void on_dstopButton_clicked();

private:
    void staticPlot();
    double random(double start, double end);
    void init();


private:
    Ui::Dialog *ui;
    QChart* staticChart;
    QChart* dynamicChart;
    QLineSeries* staticline;
    QLineSeries* dynamicline;
    QTimer * mytimer;
    QVector<double> buffer;


};

#endif // DIALOG_H
