#ifndef POINT_H
#define POINT_H

#include <QObject>

class Point
{
public:
    explicit Point();

    double x() const;
    double y() const;

    void setX(double x);
    void setY(double y);

private:
    double m_x, m_y;
};

#endif // POINT_H
