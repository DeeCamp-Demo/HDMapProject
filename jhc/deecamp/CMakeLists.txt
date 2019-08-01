cmake_minimum_required(VERSION 3.14)
project(deecamp)

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "g++" )

find_package(Eigen3 REQUIRED)
find_package(OpenCV 3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR})
add_executable(deecamp main.cpp Utils.cc Utils.h)
target_link_libraries(deecamp ${OpenCV_LIBS} ${EvoBinoSDK_LIBRARIES} ${EIGEN3_LIBS})