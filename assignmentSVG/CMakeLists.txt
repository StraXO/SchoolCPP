cmake_minimum_required(VERSION 3.10)
project(assignmentSVG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
add_executable(assignmentSVG main.cpp AllocateStatistics.cpp  ${CMAKE_CURRENT_BINARY_DIR}/graph.tpl  ${CMAKE_CURRENT_BINARY_DIR}/dygraph.min.js ${CMAKE_CURRENT_BINARY_DIR}/dygraph.css ${CMAKE_CURRENT_BINARY_DIR}/figure.txt shape/Shape.h shape/Circle.cpp shape/Circle.h shape/Line.cpp shape/Line.h)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/graph.tpl
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/graph.tpl ${CMAKE_CURRENT_BINARY_DIR}/graph.tpl)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/dygraph.min.js
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/dygraph.min.js  ${CMAKE_CURRENT_BINARY_DIR}/dygraph.min.js )
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/dygraph.css
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/dygraph.css ${CMAKE_CURRENT_BINARY_DIR}/dygraph.css)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/figure.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/figure.txt ${CMAKE_CURRENT_BINARY_DIR}/figure.txt)
