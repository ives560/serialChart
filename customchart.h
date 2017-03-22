#ifndef CUSTOMCHART_H
#define CUSTOMCHART_H

#include <QtCharts/QChart>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

class CustomChart : public QChart
{
public:
    CustomChart();
    ~CustomChart();


private:
    QSplineSeries *m_series;
};

#endif // CUSTOMCHART_H
