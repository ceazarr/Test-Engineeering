cmake_minimum_required(VERSION 3.16) 

project(Software_engineering1)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CODE_COVERAGE ON)
  include(CodeCoverage)
  add_code_coverage_all_targets(EXCLUDE /usr/* /Library/*
                                ${PROJECT_BINARY_DIR}/_deps/*)
  add_custom_target(coverage DEPENDS ccov-all)
endif()


include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG origin/main)

FetchContent_MakeAvailable(googletest)
# Now these targets are available:
# gtest
# gtest_main

include(GoogleTest)
include(ClangTidy)

add_subdirectory(geometry2d)
add_subdirectory(util)

file(GLOB TEST_FILES
    "test/geometry2d_tests/*.cpp"
    "test/util_tests/*.cpp"
)

add_executable(all_tests ${TEST_FILES})
target_link_libraries(all_tests PUBLIC geometry2d gtest_main)
# target_include_directories(all_tests PUBLIC gtest_main)
# add_test( NAME AllTests COMMAND all_tests)
gtest_discover_tests(all_tests)

if(CODE_COVERAGE)
  target_code_coverage(all_tests AUTO ALL)
endif()
