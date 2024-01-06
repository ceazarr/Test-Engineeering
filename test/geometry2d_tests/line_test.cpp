
#include "line.h"

#include <assert.h>

#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

TEST(LineTest, createLine_xy_LineAngle_LineLength_LineTrue)
{
    Point start;
    start.x = 5;
    start.y = 5;

    Angle angle;
    angle.value = 0.0;

    Line line = createLine(start, angle, 1.0);
    EXPECT_EQ(line.start.x, 5);
    EXPECT_EQ(line.start.y, 5);
    EXPECT_EQ(line.end.x, 6);
    EXPECT_EQ(line.end.y, 5);
}

Line setupLine()
{
    Point start;
    start.x = 5;
    start.y = 5;

    Angle angle;
    angle.value = 0.0;

    return createLine(start, angle, 1.0);
}
TEST(LineTest, getDirection_line_sameAngle)
{
    Line line = setupLine();
    Angle direction = getDirection(line);
    EXPECT_EQ(direction.value, 0.0);
}

TEST(LineTest, getLength_line_lineLength)
{
    Line line = setupLine();
    double length = getLength(line);
    EXPECT_DOUBLE_EQ(length, 1.0);
}

TEST(LineTest, shiftParallel_lineANDpoint_parallelLine)
{
    Line line = setupLine();
    Point new_start;
    new_start.x = 6.0;
    new_start.y = 6.0;

    // checking if the start point is the same as the new start point
    Angle original_direction;
    original_direction = getDirection(line);
    EXPECT_EQ(line.start.x, 5);
}
TEST(LineTest, getPerpendicularPoint_Test)
{
    Line line;
    Point point;
    Point result = getPerpendicularPoint(line, point);
}

TEST(LineTest, Line_xAxisParallel_Test)
{
    Line line;
    line.start = {5, 2};
    line.end = {3, 2};

    Point point;
    point.x = 4;
    point.y = 3;

    Point result = getPerpendicularPoint(line, point);
    Point expeted_result = {4, 2};
    EXPECT_EQ(result.x, expeted_result.x);
    EXPECT_EQ(result.y, expeted_result.y);
}

TEST(LineTest, Line_yAxisParallel_Test)
{
    Line line;
    line.start = {2, 5};
    line.end = {2, 3};

    Point point;
    point.x = 3;
    point.y = 4;

    Point result = getPerpendicularPoint(line, point);
    Point expeted_result = {2, 4};
    EXPECT_EQ(result.x, expeted_result.x);
    EXPECT_EQ(result.y, expeted_result.y);
}

TEST(LineTest, Point_on_Line_Test)
{
    Line line;
    line.start = {1, 1};
    line.end = {3, 3};

    Point point;
    point.x = 2;
    point.y = 2;

    Point result = getPerpendicularPoint(line, point);
    Point expeted_result = {2, 2};
    EXPECT_EQ(result.x, expeted_result.x);
    EXPECT_EQ(result.y, expeted_result.y);
}

TEST(LineTest, General_case_Test)
{
    Line line;
    line.start = {2, 1};
    line.end = {4, 2};

    Point point;
    point.x = 10;
    point.y = 2;

    Point result = getPerpendicularPoint(line, point);
    Point expeted_result = {8.8, 4.4};
    EXPECT_EQ(result.x, expeted_result.x);
    EXPECT_EQ(result.y, expeted_result.y);
}
