# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "hd_map: 2 messages, 0 services")

set(MSG_I_FLAGS "-Ihd_map:/home/apple/catkin_ws/src/hd_map/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(hd_map_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/elements.msg" NAME_WE)
add_custom_target(_hd_map_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "hd_map" "/home/apple/catkin_ws/src/hd_map/msg/elements.msg" "sensor_msgs/PointField:hd_map/element:std_msgs/Header:sensor_msgs/PointCloud2"
)

get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/element.msg" NAME_WE)
add_custom_target(_hd_map_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "hd_map" "/home/apple/catkin_ws/src/hd_map/msg/element.msg" "sensor_msgs/PointField:std_msgs/Header:sensor_msgs/PointCloud2"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/elements.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/apple/catkin_ws/src/hd_map/msg/element.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hd_map
)
_generate_msg_cpp(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/element.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hd_map
)

### Generating Services

### Generating Module File
_generate_module_cpp(hd_map
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hd_map
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(hd_map_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(hd_map_generate_messages hd_map_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/elements.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_cpp _hd_map_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/element.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_cpp _hd_map_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hd_map_gencpp)
add_dependencies(hd_map_gencpp hd_map_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hd_map_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/elements.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/apple/catkin_ws/src/hd_map/msg/element.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hd_map
)
_generate_msg_eus(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/element.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hd_map
)

### Generating Services

### Generating Module File
_generate_module_eus(hd_map
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hd_map
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(hd_map_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(hd_map_generate_messages hd_map_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/elements.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_eus _hd_map_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/element.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_eus _hd_map_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hd_map_geneus)
add_dependencies(hd_map_geneus hd_map_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hd_map_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/elements.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/apple/catkin_ws/src/hd_map/msg/element.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hd_map
)
_generate_msg_lisp(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/element.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hd_map
)

### Generating Services

### Generating Module File
_generate_module_lisp(hd_map
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hd_map
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(hd_map_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(hd_map_generate_messages hd_map_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/elements.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_lisp _hd_map_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/element.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_lisp _hd_map_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hd_map_genlisp)
add_dependencies(hd_map_genlisp hd_map_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hd_map_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/elements.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/apple/catkin_ws/src/hd_map/msg/element.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hd_map
)
_generate_msg_nodejs(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/element.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hd_map
)

### Generating Services

### Generating Module File
_generate_module_nodejs(hd_map
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hd_map
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(hd_map_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(hd_map_generate_messages hd_map_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/elements.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_nodejs _hd_map_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/element.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_nodejs _hd_map_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hd_map_gennodejs)
add_dependencies(hd_map_gennodejs hd_map_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hd_map_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/elements.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/apple/catkin_ws/src/hd_map/msg/element.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map
)
_generate_msg_py(hd_map
  "/home/apple/catkin_ws/src/hd_map/msg/element.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map
)

### Generating Services

### Generating Module File
_generate_module_py(hd_map
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(hd_map_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(hd_map_generate_messages hd_map_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/elements.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_py _hd_map_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/apple/catkin_ws/src/hd_map/msg/element.msg" NAME_WE)
add_dependencies(hd_map_generate_messages_py _hd_map_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(hd_map_genpy)
add_dependencies(hd_map_genpy hd_map_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hd_map_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hd_map)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hd_map
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(hd_map_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(hd_map_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hd_map)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/hd_map
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(hd_map_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(hd_map_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hd_map)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hd_map
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(hd_map_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(hd_map_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hd_map)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/hd_map
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(hd_map_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(hd_map_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map)
  install(CODE "execute_process(COMMAND \"/home/apple/anaconda3/envs/py27/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hd_map/.+/__init__.pyc?$"
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(hd_map_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(hd_map_generate_messages_py sensor_msgs_generate_messages_py)
endif()
