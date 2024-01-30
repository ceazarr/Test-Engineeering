#include "circle.h"

#include <cmath>

Circle ::Circle(Point center, double radius) : center_(center), radius_(radius) {}

Point Circle::getCenter() const
{
    return center_;
}
double Circle::getRadius() const
{
    return radius_;
}
double Circle::area() const
{
    return M_PI * radius_ * radius_;
}
double Circle::periphery() const
{
    return 2 * M_PI * radius_;
}
bool Circle::isInside(Point point) const
{
    return (Point::distanceTo(center_, point) < radius_);
}
void Circle::move(Point point)
{
    center_ = point;
}
void Circle::resize(double radius)
{
    radius_ = radius;
}