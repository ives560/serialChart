#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QtCharts/QChart>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QSplineSeries *m_series;
    QChart *chart;
    QValueAxis *m_axis;
};

#endif // WIDGET_H
