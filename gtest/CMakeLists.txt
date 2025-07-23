cmake_minimum_required(VERSION 3.10.0)
project(test_hello VERSION 0.1.0 LANGUAGES C CXX)

add_executable(test_hello.out test_hello.cpp)
target_link_libraries(test_hello.out gtest gtest_main)
