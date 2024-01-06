
#include "pose.h"

#include <assert.h>

#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

TEST(PoseTest, distanceTo_distanceBetweenOneAndTwo_sqrt2)
{
    Pose one;
    one.position.x = 5;
    one.position.y = 5;
    one.orientation.value = 2.0;

    Pose two;
    two.position.x = 6;
    two.position.y = 6;
    two.orientation.value = 2.0;

    EXPECT_NEAR(distanceTo(one, two), sqrt(2), 0.00001);
}
TEST(PoseTest, getRelativeOrientationTo_PoseANDpoint_relativeOrientation)
{
    Pose pose;
    pose.position.x = 5;
    pose.position.y = 5;
    pose.orientation.value = 2.0;  // This is in radians

    Point point;
    point.x = 6;
    point.y = 6;

    Angle angle = getRelativeOrientationTo(pose, point);
    EXPECT_NEAR(angle.value, -1.2146018366, 0.00001);
}
TEST(PoseTest, isEqual_TwoPoses_true)
{
    Pose pose1;
    pose1.position.x = 5;
    pose1.position.y = 5;
    pose1.orientation.value = 2.0;

    Pose pose2;
    pose2.position.x = 5;
    pose2.position.y = 5;
    pose2.orientation.value = 2.0;

    EXPECT_EQ(isEqual(pose1, pose2), true);
}
TEST(PoseTest, addPoses_positionANDorientation_pose_10ANDnegativeValue)
{
    Pose pose1;
    pose1.position.x = 8;
    pose1.position.y = 9;
    pose1.orientation.value = 2.0;

    Pose pose2;
    pose2.position.x = 2;
    pose2.position.y = 1;
    pose2.orientation.value = 2.0;

    Pose pose = addPoses(pose1, pose2);
    EXPECT_EQ(pose.position.x, 10);
    EXPECT_EQ(pose.position.y, 10);
    EXPECT_NEAR(pose.orientation.value, -2.28318530718, 0.00001);
}
TEST(PoseTest, subtractPoses_Pose1Pose2_6AND8AND0)
{
    Pose pose1;
    pose1.position.x = 8;
    pose1.position.y = 9;
    pose1.orientation.value = 2.0;

    Pose pose2;
    pose2.position.x = 2;
    pose2.position.y = 1;
    pose2.orientation.value = 2.0;

    Pose pose = subtractPoses(pose1, pose2);
    EXPECT_EQ(pose.position.x, 6);
    EXPECT_EQ(pose.position.y, 8);
    EXPECT_NEAR(pose.orientation.value, 0.0, 0.00001);  // The expected value should be close to 0.0
}
