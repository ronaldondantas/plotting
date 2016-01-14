#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /** NOTE:
     * A entrada do programa é uma lista de gráficos.
     * Um gráfico contém uma lista de pontos e o nome do gráfico.
     *
     * O código a seguir exemplifica como criar uma lista de gráficos
     * usando a classe Graph e a classe Point.
     *
     * INÍCIO
     */

    Graph *graphA = getGraph("Gráfico 1");
    Graph *graphB = getGraph("Gráfico 2");
    Graph *graphC = getGraph("Gráfico 3");
    Graph *graphD = getGraph("Gráfico 4");
    Graph *graphE = getGraph("Gráfico 5");
    Graph *graphF = getGraph("Gráfico 6");
    Graph *graphG = getGraph("Gráfico 7");
    Graph *graphH = getGraph("Gráfico 8");

    QList<Graph *> listGraphs;
    listGraphs.append(graphA);
    listGraphs.append(graphB);
    listGraphs.append(graphC);
    listGraphs.append(graphD);
    listGraphs.append(graphE);
    listGraphs.append(graphF);
    listGraphs.append(graphG);
    listGraphs.append(graphH);

    /** FIM **/

    /**
     * A função plotGraphs() recebe a lista dos gráficos que você
     * deseja que sejam plotados. (QList<Graph>)
     */
    plotGraphs(listGraphs);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotGraphs(QList<Graph *> listGraphs)
{
    foreach (Graph *graph, listGraphs) {
        QCustomPlot *l_customPlot = new QCustomPlot();
        l_customPlot->setMinimumHeight(200);
        l_customPlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        ui->verticalLayout->addWidget(l_customPlot);

        l_customPlot->addGraph();
        l_customPlot->graph(0)->setData(graph->getListX(), graph->getListY());
        l_customPlot->graph(0)->setName(graph->name());

        l_customPlot->xAxis->setLabel("x (tempo em segundos)");
        l_customPlot->yAxis->setLabel("y (angulação)");

        l_customPlot->xAxis->setRange(0, graph->getMaxX());
        l_customPlot->yAxis->setRange(-180, 180);
        l_customPlot->replot();
    }
}


Graph* MainWindow::getGraph(QString a_nome)
{
    // NOTE: Criação de pontos fake para exemplificar a criação de um gráfico.

    Point pointA;
    pointA.setX(qrand() % 577);
    pointA.setY(qrand() % 181);

    Point pointB;
    pointB.setX(qrand() % 577);
    pointB.setY(qrand() % 181);

    Point pointC;
    pointC.setX(qrand() % 577);
    pointC.setY(qrand() % 181);

    Point pointD;
    pointD.setX(qrand() % 577);
    pointD.setY(qrand() % 181);

    QVector<Point> points;
    points.append(pointA);
    points.append(pointB);
    points.append(pointC);
    points.append(pointD);

    Graph *graph = new Graph(points, a_nome);

    return graph;
}
