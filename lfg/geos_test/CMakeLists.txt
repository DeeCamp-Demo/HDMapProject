cmake_minimum_required(VERSION 3.5)
project(geos_test)
find_package(GEOS 3.8 REQUIRED)
set(CMAKE_CXX_STANDARD 11)

add_executable(geos_test main.cpp)
target_link_libraries(geos_test PRIVATE GEOS::geos)