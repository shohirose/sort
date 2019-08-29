cmake_minimum_required(VERSION 3.8)
project(sort_algorithm CXX)

find_package(GTest REQUIRED)

enable_testing()

add_executable(sort test.cpp)
target_compile_features(sort PUBLIC cxx_std_14)
target_compile_options(sort PUBLIC -Wall -Wextra -Wpedantic)
target_link_libraries(sort PUBLIC GTest::GTest GTest::Main)

add_test(
  NAME sort
  COMMAND $<TARGET_FILE:sort>
  )
