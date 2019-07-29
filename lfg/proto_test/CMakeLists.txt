cmake_minimum_required(VERSION 3.5)
project(proto_test)
set(CMAKE_CXX_STANDARD 11)

add_executable(prototest prototest.cpp)
target_link_libraries(prototest)