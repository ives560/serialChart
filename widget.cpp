#include "widget.h"
#include "ui_widget.h"

#include <QtCharts/QVXYModelMapper>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    customModel = new CustomTableModel();

    //
    m_series = new QSplineSeries();
    QPen green(Qt::red);
    green.setWidth(3);
    m_series->setPen(green);

    m_axis = new QValueAxis;
    m_axis->setTickCount(5);
    //
    QVXYModelMapper *mapper = new QVXYModelMapper(this);
    mapper->setXColumn(0);
    mapper->setYColumn(1);
    mapper->setSeries(m_series);
    mapper->setModel(customModel);

    //
    chart = new QChart;
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(m_series);
    chart->setAxisX(m_axis,m_series);
    chart->createDefaultAxes();


    chart->axisX()->setRange(0,40);
    chart->axisY()->setRange(0,15);

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    ui->tableView->setModel(customModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    customModel->addRow();
    chart->scroll(20, 0);
}
