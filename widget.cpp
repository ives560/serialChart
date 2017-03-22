#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_series = new QSplineSeries();
    QPen green(Qt::red);
    green.setWidth(3);
    m_series->setPen(green);

    m_series->append(0, 6);
    m_series->append(2, 4);
    m_series->append(3, 8);
    m_series->append(7, 4);
    m_series->append(10, 5);

    m_axis = new QValueAxis;
    m_axis->setTickCount(5);

    chart = new QChart();
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(m_series);
    chart->setTitle("Chart Example");
    chart->createDefaultAxes();
    chart->axisY()->setRange(0, 10);
    chart->setAxisX(m_axis,m_series);


    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}

Widget::~Widget()
{
    delete ui;
}
