#include "graph.h"

Graph::Graph(QVector<Point> points, QString name, QObject *parent)
    : QObject(parent),
      m_points(points),
      m_name(name)
{
    QVector<double> listX, listY;
    foreach (Point point, m_points) {
        listX.append(point.x());
        listY.append(point.y());

        if (getMaxX() < point.x()) {
            setMaxX(point.x());
        }
    }
    setListX(listX);
    setListY(listY);
}

QVector<Point> Graph::points() const
{
    return m_points;
}

void Graph::setPoints(const QVector<Point> &points)
{
    m_points = points;
}

QString Graph::name() const
{
    return m_name;
}

void Graph::setName(const QString &name)
{
    m_name = name;
}

QVector<double> Graph::getListX() const
{
    return listX;
}

void Graph::setListX(const QVector<double> &value)
{
    listX = value;
}

QVector<double> Graph::getListY() const
{
    return listY;
}

void Graph::setListY(const QVector<double> &value)
{
    listY = value;
}

double Graph::getMaxX() const
{
    return maxX;
}

void Graph::setMaxX(const double &value)
{
    maxX = value;
}
