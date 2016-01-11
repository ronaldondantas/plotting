#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int maxTime = 0;
    int numberValues = 5;
    QVector<double> x(numberValues), y(numberValues); // 0..100
    QList<QPair<double, double> > listPoints;

    QPair<double, double> pairPoints;
    int i=0;
    while(i<5) {
        pairPoints.first = 15;
        pairPoints.second = 30;
        i++;
    }

    listPoints.append(pairPoints);

    for (int i=0; i<listPoints.size(); ++i)
    {
      x[i] = listPoints.at(i).first;
      y[i] = listPoints.at(i).second;

      if (y[i] > maxTime) maxTime = y[i];
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("y (angulação)");
    ui->customPlot->yAxis->setLabel("x (tempo em segundos)");

    ui->customPlot->xAxis->setRange(-180, 180);
    ui->customPlot->yAxis->setRange(0, maxTime);
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
