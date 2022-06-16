cmake_minimum_required(VERSION 3.22)
project(Week6IO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -D_GLIBCXX_DEBUG")

add_executable(Week6IO main.cpp)
