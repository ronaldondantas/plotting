#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "graph.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cp2->setVisible(false);
    ui->cp3->setVisible(false);

    Point pointA;
    pointA.setX(10);
    pointA.setY(90);

    Point pointB;
    pointB.setX(20);
    pointB.setY(180);

    Point pointC;
    pointC.setX(30);
    pointC.setY(-90);

    Point pointD;
    pointD.setX(0);
    pointD.setY(-180);

    QVector<Point> points;
    points.append(pointA);
    points.append(pointB);
    points.append(pointC);
    points.append(pointD);

    Graph graph(points, "Gráfico 1");

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(graph.getListX(), graph.getListY());
    ui->customPlot->graph(0)->setName(graph.name());

    ui->customPlot->xAxis->setLabel("x (tempo em segundos)");
    ui->customPlot->yAxis->setLabel("y (angulação)");

    ui->customPlot->xAxis->setRange(0, graph.getMaxX());
    ui->customPlot->yAxis->setRange(-180, 180);
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
