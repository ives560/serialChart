#include "widget.h"
#include "ui_widget.h"

#include <QtCharts/QVXYModelMapper>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    customModel = new CustomTableModel();

    ui->tableView->setModel(customModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    //
    chart = new QChart;
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);

    //
    m_series = new QSplineSeries();
    QPen green(Qt::red);
    green.setWidth(3);
    m_series->setPen(green);

    //
    QVXYModelMapper *mapper = new QVXYModelMapper(this);
    mapper->setXColumn(0);
    mapper->setYColumn(1);
    mapper->setSeries(m_series);
    mapper->setModel(customModel);
    chart->addSeries(m_series);

    //
    chart->createDefaultAxes();
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartView->setMinimumSize(640, 480);


}

Widget::~Widget()
{
    delete ui;
}
