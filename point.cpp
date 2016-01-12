#include "point.h"

Point::Point()
{
}

double Point::x() const
{
    return m_x;
}

double Point::y() const
{
    return m_y;
}

void Point::setX(double x)
{
    m_x = x;
}

void Point::setY(double y)
{
    m_y = y;
}

