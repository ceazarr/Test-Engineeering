#include "circle.h"

#include <cassert>
#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

TEST(CircleTest, getCenter_forCenter_expectCenter)
{
    Point testPoint(1, 2);
    Circle testCircle(testPoint, 3);
    Point result = testCircle.getCenter();
    EXPECT_EQ(result, testPoint);
}
TEST(CircleTest, getRadius_forRadius_expectRadius)
{
    double testRadius = 3;
    Circle testCircle(Point(1, 2), testRadius);
    double result = testCircle.getRadius();
    EXPECT_EQ(result, testRadius);
}
TEST(CircleTest, getArea_forRad3_expectAreaPiTimes9)
{
    double testRadius = 3;
    Circle testCircle(Point(1, 2), testRadius);
    double result = testCircle.area();
    double expected = M_PI * testRadius * testRadius;
    EXPECT_EQ(result, expected);
}
TEST(CircleTest, getPeriphery_forRad3_expectPiTimes6)
{
    double testRadius = 3;
    Circle testCircle(Point(1, 2), testRadius);
    double result = testCircle.periphery();
    double expected = 2 * M_PI * testRadius;
    EXPECT_EQ(result, 2 * M_PI * testRadius);
}

TEST(CircleTest, isInside_forPointInside_expectTrue)
{
    Circle testCircle(Point(1, 2), 3);
    Point testPoint(2, 2);
    bool result = testCircle.isInside(testPoint);
    EXPECT_TRUE(result);
}
TEST(CircleTest, move_CentreToNewPoint_expect_3_3)
{
    Circle testCircle(Point(1, 2), 3);
    Point testPoint(3, 3);
    testCircle.move(testPoint);
    EXPECT_TRUE(testCircle.getCenter() == testPoint);
}
TEST(CircleTest, resize_RadiusToNewRadius_expect_7)
{
    Circle testCircle(Point(1, 2), 7);
    double testRadius = 7;
    testCircle.resize(testRadius);
    EXPECT_TRUE(testCircle.getRadius() == testRadius);
}
