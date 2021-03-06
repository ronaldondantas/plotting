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

    Graph *graphA = getGraph("Ombro");
    Graph *graphB = getGraph("Joelho");
    Graph *graphC = getGraph("Tórax");
    Graph *graphD = getGraph("Tornozelo");
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

    // Plotar marcador em um gráfico dando a posição e, caso queira, o nome do gráfico
    // Senão tiver o nome do gráfico, a linha é plotada em todos os gráficos

    plotLineInGraph(6, "Joelho");
//    plotLineInGraph(6);

    // Retorna a linha da posição do gráfico passado por parâmetro
    // Senão tiver o nome do gráfico, retorna a linha do primeiro gráfico plotado em tela

    qDebug() << getLinePosition("Ombro");
    qDebug() << getLinePosition("Joelho");

    // Muda a visibilidade do eixo X do gráfico passado por parâmetro.
    // Caso não seja passado, todos os gráficos sofrem a mudança.
    setAxisXVisible(false);
//    setAxisXVisible(false, "Joelho");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotGraphs(QList<Graph *> listGraphs)
{
    foreach (Graph *graph, listGraphs) {
        graphNamePosition.insert(graph->name(), 0);

        QCustomPlot *l_customPlot = new QCustomPlot();
        l_customPlot->setMinimumHeight(200);
        l_customPlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        ui->verticalLayout->addWidget(l_customPlot);

        l_customPlot->addGraph();
        l_customPlot->graph(0)->setData(graph->getListX(), graph->getListY());
        l_customPlot->graph(0)->setName(graph->name());

        l_customPlot->graph(0)->setBrush(QBrush(QColor(204,243,255)));
        l_customPlot->graph(0)->setPen(QPen(Qt::blue));
        l_customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));

        l_customPlot->xAxis->setLabel(graph->name());
        l_customPlot->xAxis->setRange(0, graph->getMaxX());
        l_customPlot->xAxis->setDateTimeFormat("hh:mm");
        l_customPlot->xAxis->setAutoTickStep(false);
        l_customPlot->xAxis->setTickStep(1);

        l_customPlot->yAxis->setRange(-180, 180);
        l_customPlot->yAxis->setAutoTickStep(false);
        l_customPlot->yAxis->setTickStep(90);
        l_customPlot->replot();

        listCustomPlots.append(l_customPlot);
    }
}

int MainWindow::getLinePosition(QString graphName)
{
    int position = -1;
    if (graphName.isEmpty()) {
        position = graphNamePosition.value(listCustomPlots.at(0)->graph(0)->name());
    } else {
        position = graphNamePosition.value(graphName);
    }
    return position;
}

void MainWindow::setAxisXVisible(bool visible, QString graphName)
{
    foreach (QCustomPlot *customPlot, listCustomPlots) {
        if (graphName.isEmpty() || customPlot->graph(0)->name().compare(graphName) == 0) {
            customPlot->xAxis->setVisible(visible);
            customPlot->replot();
        }
    }
}

void MainWindow::plotLineInGraph(int linePosition, QString graphName)
{
    foreach (QCustomPlot *customPlot, listCustomPlots) {
        if (graphName.isEmpty() || customPlot->graph(0)->name().compare(graphName) == 0) {
            QCPItemLine *l_itemLine = new QCPItemLine(customPlot);
            QPen pen(Qt::red);
            pen.setWidth(4);
            l_itemLine->setPen(pen);
            l_itemLine->setSelectable(true);

            customPlot->addItem(l_itemLine);

            l_itemLine->start->setCoords(linePosition, -180);
            l_itemLine->end->setCoords(linePosition, +180);

            graphNamePosition.insert(customPlot->graph(0)->name(), linePosition);

            customPlot->replot();
        }
    }
}


Graph* MainWindow::getGraph(QString a_nome)
{
    // NOTE: Criação de pontos fake para exemplificar a criação de um gráfico.

    Point pointA;
    pointA.setX(qrand() % 30 + 1);
    pointA.setY(qrand() % 181);

    Point pointB;
    pointB.setX(qrand() % 30 + 1);
    pointB.setY(qrand() % 181);

    Point pointC;
    pointC.setX(qrand() % 30 + 1);
    pointC.setY(qrand() % 181);

    Point pointD;
    pointD.setX(qrand() % 30 + 1);
    pointD.setY(qrand() % 181);

    QVector<Point> points;
    points.append(pointA);
    points.append(pointB);
    points.append(pointC);
    points.append(pointD);

    Graph *graph = new Graph(points, a_nome);

    return graph;
}
