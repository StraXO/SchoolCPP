cmake_minimum_required(VERSION 3.22)
project(week3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -D_GLIBCXX_DEBUG")

add_executable(week3 main.cpp)