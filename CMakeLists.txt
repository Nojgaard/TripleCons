cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(gt2st VERSION 0.1 LANGUAGES CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_CXX_STANDARD 14)

add_executable(is_consistent
	src/main.cpp
	src/Triple.cpp
)
