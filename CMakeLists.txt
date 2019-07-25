cmake_minimum_required(VERSION 3.8)
project(sort_algorithm CXX)

add_executable(sort test.cpp)
target_compile_features(sort PUBLIC cxx_std_14)
target_compile_options(sort PUBLIC -Wall -Wextra -Wpedantic)