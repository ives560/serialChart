#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCharts/QChart>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>

#include "customtablemodel.h"
#include "customchart.h"
#include "settingsdialog.h"

QT_CHARTS_USE_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initActionsConnections();

private:
    Ui::MainWindow *ui;
    QSplineSeries *m_series;
    QChart *chart;
    QValueAxis *m_axis;
    CustomTableModel *customModel;
    SettingsDialog *settings;
};

#endif // MAINWINDOW_H
