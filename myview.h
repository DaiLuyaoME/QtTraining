#ifndef MYVIEW_H
#define MYVIEW_H

#include <QObject>
#include <QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE
class MyView : public QChartView
{
    Q_OBJECT

public:
    MyView(QWidget *parent = 0);
};

#endif // MYVIEW_H
