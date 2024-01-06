#include "angle.h"

#include <cassert>
#include <cmath>
#include <iostream>

#include <gtest/gtest.h>
using namespace std;

TEST(AngleTest, fixAngleRange_forPi_expectPi)
{
    double testAngle = M_PI;
    double result = fixAngleRange(testAngle);
    EXPECT_DOUBLE_EQ(result, M_PI);
}

TEST(AngleTest, fixAngleRange_for7_expect7Minus2Pi)
{
    double testAngle = 7;
    double result = fixAngleRange(testAngle);
    EXPECT_DOUBLE_EQ(result, (7 - 2 * M_PI));
}

TEST(AngleTest, fixAngleRange_forNeg1_expectNeg1)
{
    double testAngle = -1;
    double result = fixAngleRange(testAngle);
    EXPECT_DOUBLE_EQ(result, -1);
}

TEST(AngleTest, fixAngleRange_forNeg7_expectNeg7Plus2Pi)
{
    double testAngle = -7;
    double result = fixAngleRange(testAngle);
    EXPECT_DOUBLE_EQ(result, -7 + 2 * M_PI);
}

TEST(AngleTest, convertFromDegreeToRadiant_for30_expectPiDiv6)
{
    Angle testAngle = {30};
    Angle result = {convertFromDegreeToRadiant(testAngle.value)};
    EXPECT_DOUBLE_EQ(result.value, M_PI / 6);
}

TEST(AngleTest, getHalfRotation_test)
{
    Angle testAngle = {M_PI};
    Angle result = {getHalfRotation()};
    EXPECT_DOUBLE_EQ(result.value, testAngle.value);
}

TEST(AngleTest, getQuarterRotation_test)
{
    Angle testAngle = {M_PI_2};
    Angle result = {getQuarterRotation()};
    EXPECT_DOUBLE_EQ(result.value, testAngle.value);
}

TEST(AngleTest, getFullRotation_test)
{
    Angle testAngle;
    Angle result = {getFullRotation()};
    EXPECT_DOUBLE_EQ(result.value, testAngle.value);
}

TEST(AngleTest, getEighthRotation_test)
{
    Angle testAngle = {M_PI_4};
    Angle result = {getEighthRotation()};
    EXPECT_DOUBLE_EQ(result.value, testAngle.value);
}

TEST(AngleTest, getValueBetweenMinusPiAndPi_for7_expect7Minus2Pi)
{
    Angle testAngle = {7};
    Angle result = {getValueBetweenMinusPiAndPi(testAngle)};
    EXPECT_DOUBLE_EQ(result.value, 7 - 2 * M_PI);
}

TEST(AngleTest, getValueBetweenZeroAndTwoPi_for9_expect9Minus2Pi)
{
    Angle testAngle = {9};
    Angle result = {getValueBetweenZeroAndTwoPi(testAngle)};
    EXPECT_DOUBLE_EQ(result.value, 9 - 2 * M_PI);
}

TEST(AngleTest, multiplyAngle_for7_expect_21Minus6Pi)
{
    Angle testAngle = {7};
    double test_factor = 3;
    Angle result = {multiplyAngle(testAngle, test_factor)};
    EXPECT_DOUBLE_EQ(result.value, 21 - 6 * M_PI);
}

TEST(AngleTest, addAngles_for4and3_expect7Minus2Pi)
{
    Angle testAngle1 = {4};
    Angle testAngle2 = {3};
    Angle result = {addAngles(testAngle1, testAngle2)};
    EXPECT_DOUBLE_EQ(result.value, 7 - 2 * M_PI);
}

TEST(AngleTest, subtractAngles_for18point5and11point5_expect7Minus2Pi)
{
    Angle testAngle1 = {18.5};
    Angle testAngle2 = {11.5};
    Angle result = {subtractAngles(testAngle1, testAngle2)};
    EXPECT_DOUBLE_EQ(result.value, 7 - 2 * M_PI);
}

TEST(AngleTest, createAngle_forPoints_expectAtan2of2div1)
{
    Point test_start = {2, 1};
    Point test_end = {3, 3};
    Angle result = {createAngle(test_start, test_end)};
    EXPECT_DOUBLE_EQ(result.value, atan2(2, 1));
}

TEST(AngleTest, isEqual_test_forDifferentAngles_expectFalse)
{
    Angle testAngle1 = {18.5};
    Angle testAngle2 = {11.5};
    bool result = isEqual(testAngle1, testAngle2);
    EXPECT_FALSE(result);
}

TEST(AngleTest, isEqual_test_forSameAngles_expectTrue)
{
    Angle testAngle1 = {45678.9};
    Angle testAngle2 = {45678.9};
    bool result = isEqual(testAngle1, testAngle2);
    EXPECT_TRUE(result);
}

TEST(AngleTest, isObtuse_for456_expectTrue)
{
    Angle testAngle = {456};
    bool result = isObtuse(testAngle);
    assert(result == true);
    EXPECT_TRUE(result);
}

TEST(AngleTest, isObtuse_for458_expectFalse)
{
    Angle testAngle = {458};
    bool result = isObtuse(testAngle);
    EXPECT_FALSE(result);
}

TEST(AngleTest, abs_forMinus2)
{
    Angle testAngle = {-2};
    Angle result = {abs(testAngle)};
    EXPECT_EQ(result.value, 2);
}

// //90 degree angle
TEST(AngleTest, createAngle_forRightAngle_expectPiDiv2)
{
    Point source_test = {0, 0};
    Point target1_test = {1, 0};
    Point target2_test = {0, 1};
    Angle result = {createAngle(source_test, target1_test, target2_test)};
    EXPECT_DOUBLE_EQ(result.value, M_PI / 2);
}