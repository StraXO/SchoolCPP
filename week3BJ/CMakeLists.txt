cmake_minimum_required(VERSION 3.22)
project(week3BJ)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -D_GLIBCXX_DEBUG")

add_executable(week3BJ main.cpp classes/Card/cardRank.h classes/Card/cardSuit.h classes/Card/Card.h classes/Blackjack.cpp classes/Blackjack.h)
