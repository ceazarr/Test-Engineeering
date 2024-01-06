#include "line.h"

Line createLine(Point start, Angle angle, double distance)
{
    return Line{start, addPoints(start, createPoint(distance, angle))};
}

Angle getDirection(Line line)
{
    return createAngle(line.start, line.end);
}

double getLength(Line line)
{
    return distanceTo(line.start, line.end);
}

void shiftParallel(Line& line, Point point)
{
    Point direction = subtractPoints(line.end, line.start);
    line.start = point;
    line.end = addPoints(line.start, direction);
}
Point getPerpendicularPoint(Line line, Point point)
{
    if (line.start.x == line.end.x)
    {
        // Point result = {line.start.x, point.y};
        return {line.start.x, point.y};
    }
    if (line.start.y == line.end.y)
    {
        // Point result = {point.x, line.start.y};
        return {point.x, line.start.y};
    }

    // if (line.start.x == line.end.x || line.start.y == line.end.y)
    // {
    //     return {line.start.x == line.end.x ? line.start.x : point.x, line.start.y == line.end.y ? line.start.y : point.y};
    // }

    double m = (line.end.y - line.start.y) / (line.end.x - line.start.x);
    double b = line.start.y - m * line.start.x;
    Point result;
    if (point.y == m * point.x + b)
    {
        result = {point.x, point.y};
    }
    else
    {
        double mPerp = -1 / m;
        double bPerp = point.y - mPerp * point.x;
        double x = (bPerp - b) / (m - mPerp);
        double y = m * x + b;
        result = {x, y};
    }
    return result;
}
