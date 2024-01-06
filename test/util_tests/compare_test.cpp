#include "compare.h"

#include <assert.h>

#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

TEST(CompareTest, isFuzzyEqual_test_expectTrue)
{
    double test_val1 = 1.0;
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-20;
    bool result = isFuzzyEqual(test_val1, test_val2, test_epsilon);
    EXPECT_TRUE(result);
}

TEST(CompareTest, isFuzzyEqual_test_expectFalse)
{
    double test_val1 = 1.1;
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-20;
    bool result = isFuzzyEqual(test_val1, test_val2, test_epsilon);
    EXPECT_FALSE(result);
}

TEST(CompareTest, isFuzzyGreater_test_expectTrue)
{
    double test_val1 = 1.0;
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-15;
    bool result = isFuzzyGreater(test_val1, test_val2, test_epsilon);
    EXPECT_TRUE(result);
}

TEST(CompareTest, isFuzzyGreater_test_expectFalse)
{
    double test_val1 = 1.0;
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-16;  // one more zero than above
    bool result = isFuzzyGreater(test_val1, test_val2, test_epsilon);
    EXPECT_FALSE(result);
}

TEST(CompareTest, isFuzzySmaller_test_expectTrue)  // same values as isFuzzyGreater_test_expectTrue
{
    double test_val1 = 1.0;
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-15;
    bool result = isFuzzySmaller(test_val1, test_val2, test_epsilon);
    EXPECT_TRUE(result);
}

TEST(CompareTest, isFuzzySmaller_test_expectFalse)  // same values as isFuzzyGreater_test_expectFalse
{
    double test_val1 = 1.0;
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-16;  // one more zero than above
    bool result = isFuzzySmaller(test_val1, test_val2, test_epsilon);
    EXPECT_FALSE(result);
}

// void isStrictFuzzyGreater_test_expectTrue()
TEST(CompareTest, isStrictFuzzyGreater_test_expectTrue)
{
    double test_val1 = 1.0;
    double test_val2 = 0.99999999999;  // 11 after comma
    double test_epsilon = 1.0E-13;
    bool result = isStrictFuzzyGreater(test_val1, test_val2, test_epsilon);
    // assert(result==true);
    EXPECT_TRUE(result);
}

// void isStrictFuzzyGreater_test_expectFalse()
TEST(CompareTest, isStrictFuzzyGreater_test_expectFalse)
{
    double test_val1 = 1.0;
    double test_val2 = 0.99999999999;  // 11 after comma
    double test_epsilon = 1.0E-11;
    bool result = isStrictFuzzyGreater(test_val1, test_val2, test_epsilon);
    // assert(result==false);
    EXPECT_FALSE(result);
}

// void isStrictFuzzySmaller_test_expectTrue()
TEST(CompareTest, isStrictFuzzySmaller_test_expectTrue)
{
    double test_val1 = 0.99999999999;  // 11 after comma
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-13;
    bool result = isStrictFuzzySmaller(test_val1, test_val2, test_epsilon);
    // assert(result==true);
    EXPECT_TRUE(result);
}

// void isStrictFuzzySmaller_test_expectFalse()
TEST(CompareTest, isStrictFuzzySmaller_test_expectFalse)
{
    double test_val1 = 0.99999999999;  // 11
    double test_val2 = 1.0;
    double test_epsilon = 1.0E-11;  // 11 with the one
    bool result = isStrictFuzzySmaller(test_val1, test_val2, test_epsilon);
    // assert(result==false);
    EXPECT_FALSE(result);
}

// int main()
// {
//     isFuzzyEqual_test_expectTrue();
//     isFuzzyEqual_test_expectFalse();

//     isFuzzyGreater_test_expectTrue();
//     isFuzzyGreater_test_expectFalse();

//     isFuzzySmaller_test_expectTrue();
//     isFuzzySmaller_test_expectFalse();

//     isStrictFuzzyGreater_test_expectTrue();
//     isStrictFuzzyGreater_test_expectFalse();

//     isStrictFuzzySmaller_test_expectTrue();
//     isStrictFuzzySmaller_test_expectFalse();
// }
