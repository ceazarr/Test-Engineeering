cmake_minimum_required(VERSION 3.16) 

add_library(util src/compare.cpp)

target_include_directories(util PUBLIC include)
