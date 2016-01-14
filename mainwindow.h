#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
