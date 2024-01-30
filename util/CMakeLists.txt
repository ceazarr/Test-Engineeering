cmake_minimum_required(VERSION 3.16) 

add_library(util src/compare.cpp)
if(CODE_COVERAGE)
  target_code_coverage(util AUTO ALL)
endif()

target_include_directories(util PUBLIC include)
