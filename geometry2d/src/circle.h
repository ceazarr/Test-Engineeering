#ifndef SEL_CIRCLE_H
#define SEL_CIRCLE_H
#include "point.h"

class Point;
class Circle
{
  public:
    Circle();
    Circle(Point center, double radius);

    Point getCenter() const;
    double getRadius() const;
    void move(Point point);
    void resize(double radius);

    double area() const;
    double periphery() const;
    bool isInside(Point point) const;

  private:
    Point center_;
    double radius_;
};

#endif  // SEL_LINE_H