
#include "point.h"

#include <assert.h>

#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

TEST(PointTest, createPoint_distanceANDangle_negativeNumber)
{

    Angle angle;
    angle.value = 2.0;

    Point point = createPoint(1.0, angle);
    EXPECT_DOUBLE_EQ(point.x, -0.4161468365471424);
}
TEST(PointTest, isEqual_TwoPoints_True)
{
    Point point1;
    point1.x = 5;
    point1.y = 5;

    Point point2;
    point2.x = 5;
    point2.y = 5;

    EXPECT_EQ(point1.x, point2.x);
    EXPECT_EQ(point1.y, point2.y);
}

TEST(PointTest, getLength_HypotenuseLength_sqrt61)
{
    Point point;
    point.x = 5;
    point.y = 6;

    double length = getLength(point);
    EXPECT_DOUBLE_EQ(length, sqrt(61));
}
TEST(PointTest, distanceTo_distanceBetweenOneTwo_expectSqrt2)
{
    Point one;
    one.x = 5;
    one.y = 5;

    Point two;
    two.x = 6;
    two.y = 6;

    double distance = distanceTo(one, two);
    EXPECT_DOUBLE_EQ(distance, sqrt(2));
}

TEST(PointTest, subtractPoints_x1Minusx2_y1Minusy2_expect2)
{
    Point one;
    one.x = 8;
    one.y = 8;

    Point two;
    two.x = 6;
    two.y = 6;

    Point result = subtractPoints(one, two);
    EXPECT_EQ(result.x, 2);
    EXPECT_EQ(result.y, 2);
}

TEST(PointTest, addPoints_x1Plusx2_y1Plusy2_expect14)
{
    Point one;
    one.x = 8;
    one.y = 8;

    Point two;
    two.x = 6;
    two.y = 6;

    Point result = addPoints(one, two);
    EXPECT_EQ(result.x, 14);
    EXPECT_EQ(result.y, 14);
}

TEST(PointTest, multiplyPoint_x1Timesx2_y1Timesy2_expect10)
{
    Point point;
    point.x = 5;
    point.y = 5;

    Point result = multiplyPoint(point, 2);
    EXPECT_EQ(result.x, 10);
    EXPECT_EQ(result.y, 10);
}

TEST(PointTest, rotate_PointAngleBetweenPiAndMinusPi_0AND2sqrt2)
{
    Point point;
    point.x = 2;
    point.y = 2;

    Angle angle;
    angle.value = M_PI / 4;  // 45 degrees in radians

    Point result = rotate(point, angle);
    EXPECT_NEAR(result.x, 0, 0.00001);
    EXPECT_NEAR(result.y, 2 * sqrt(2), 0.00001);
}