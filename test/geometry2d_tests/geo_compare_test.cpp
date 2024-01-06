#include "geo_compare.h"

#include <assert.h>

#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

#include "angle.h"
#include "pose.h"

TEST(GeoCompareTest, isFuzzyEqual_PointTest_expectFalse)  // epsiolon too small
{
    Point point1_test = {1, 1};
    Point point2_test = {1, 1.00001};
    double epsilon_test = 10e-7;
    bool result = isFuzzyEqual(point1_test, point2_test, epsilon_test);
    EXPECT_FALSE(result);
}

TEST(GeoCompareTest, isFuzzyEqual_PointTest_expectTrue)  // epsilon too big
{
    Point point1_test = {1, 1};
    Point point2_test = {1, 1.00000001};
    double epsilon_test = 10e-7;
    bool result = isFuzzyEqual(point1_test, point2_test, epsilon_test);
    EXPECT_TRUE(result);
}

TEST(GeoCompareTest, isFuzzyEqual_AngleTest_expectFalse)
{
    Angle angle1_test = {4 * M_PI};
    Angle angle2_test = {-M_PI};
    double epsilon_test = 10e-7;
    bool result = isFuzzyEqual(angle1_test, angle2_test, epsilon_test);
    EXPECT_FALSE(result);
}

TEST(GeoCompareTest, isFuzzyEqual_AngleTest_expectTrue)
{
    Angle angle1_test = {3 * M_PI};
    Angle angle2_test = {-M_PI};
    double epsilon_test = 10e-7;
    bool result = isFuzzyEqual(angle1_test, angle2_test, epsilon_test);
    EXPECT_TRUE(result);
}

TEST(GeoCompareTest, isFuzzyEqual_PoseTest_expectFalse)
{
    Angle angle1_test = {7};
    Angle angle2_test = {-M_PI};
    Point point1_test = {1, 1};
    Point point2_test = {1, 1001};
    Pose pose1_test = {point1_test, angle1_test};
    Pose pose2_test = {point2_test, angle2_test};

    double epsilon_test = 10e-7;
    bool result = isFuzzyEqual(pose1_test, pose2_test, epsilon_test);
    EXPECT_FALSE(result);
}

TEST(GeoCompareTest, isFuzzyEqual_PoseTest_expectTrue)  // epsilon too big
{
    Angle angle1_test = {3 * M_PI};
    Angle angle2_test = {-M_PI};
    Point point1_test = {1, 1};
    Point point2_test = {1, 1.0000001};
    Pose pose1_test = {point1_test, angle1_test};
    Pose pose2_test = {point2_test, angle2_test};

    double epsilon_test = 10e-7;
    bool result = isFuzzyEqual(pose1_test, pose2_test, epsilon_test);
    EXPECT_TRUE(result);
}