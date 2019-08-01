cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME hdmap)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
find_package(Protobuf REQUIRED)
#==========by hand
#protoc test.proto --cpp_out=.
set(PROTO_FILES
#        proto/test.proto
        proto/HDMap.proto
        proto/LaneMarking.proto
        proto/SourceInfo.proto
        proto/TrafficLight.proto
        proto/Divider.proto
        )

set(SRC_FILES
        src/test.cpp
        )

set(HDR_FILES
        utils/read_hdmap.h utils/calulate.h src/test.cpp src/test.h)


PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HDR ${PROTO_FILES})

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES} ${PROTO_SRC} ${PROTO_HDR} ${PROTO_FILES})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROTOBUF_INCLUDE_DIRS}
        )
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})

