#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Graph *getGraph(QString a_nome);

    void plotGraphs(QList<Graph *> listGraphs);

    int getLinePositionByGraph(QString graphName);

public slots:
    void plotLineInGraph(QString graphName, int linePosition);

private:
    Ui::MainWindow *ui;
    QList<QCustomPlot *> listCustomPlots;
    QHash<QString, int> graphNamePosition;
};

#endif // MAINWINDOW_H
