cmake_minimum_required(VERSION 3.14)
project(deecamp)

set(CMAKE_CXX_STANDARD 14)

add_executable(deecamp main.cpp utils.h Utils.cc Utils.h)