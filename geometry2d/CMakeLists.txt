cmake_minimum_required(VERSION 3.16) 

add_library(geometry2d src/angle.cpp src/geo_compare.cpp src/line.cpp src/point.cpp src/pose.cpp)

target_include_directories(geometry2d PUBLIC include)
target_link_libraries(geometry2d PUBLIC util)

