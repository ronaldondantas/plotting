#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QVector>
#include "point.h"

class Graph : public QObject
{
    Q_OBJECT
public:
    explicit Graph(QVector<Point> points, QString name, QObject *parent = 0);

    QVector<Point> points() const;
    void setPoints(const QVector<Point> &points);

    QString name() const;
    void setName(const QString &name);


    QVector<double> getListX() const;
    void setListX(const QVector<double> &value);

    QVector<double> getListY() const;
    void setListY(const QVector<double> &value);

    double getMaxX() const;
    void setMaxX(const double &value);

private:
    QString m_name;
    QVector<Point> m_points;

    QVector<double> listX;
    QVector<double> listY;

    double maxX;
};

#endif // GRAPH_H
