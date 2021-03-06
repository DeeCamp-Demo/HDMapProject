cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME hdmap)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
find_package(Protobuf REQUIRED)
find_package(Eigen3)
find_package(OpenCV REQUIRED)
find_package(PCL 1.7 REQUIRED)
#==========by hand
set(PROTO_FILES
        proto/HDMap.proto
        proto/LaneMarking.proto
        proto/SourceInfo.proto
        proto/TrafficLight.proto
        proto/Divider.proto
        )
set(SRC_FILES
        src/test.cpp
        src/Utils.cc
        )

set(HDR_FILES
        utils/read_hdmap.h utils/calulate.h src/test.h utils/Utils.h)


add_definitions(${PCL_DEFINITIONS})
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HDR ${PROTO_FILES})
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR} ${OpenCV_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES} ${PROTO_SRC} ${PROTO_HDR} ${PROTO_FILES})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROTOBUF_INCLUDE_DIRS}
        )
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES} ${OpenCV_LIBS} ${PCL_LIBRARY_DIRS} ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})

