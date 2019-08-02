; Auto-generated. Do not edit!


(cl:in-package hd_map-msg)


;//! \htmlinclude elements.msg.html

(cl:defclass <elements> (roslisp-msg-protocol:ros-message)
  ((type
    :reader type
    :initarg :type
    :type cl:fixnum
    :initform 0)
   (motor_type
    :reader motor_type
    :initarg :motor_type
    :type cl:fixnum
    :initform 0)
   (elements
    :reader elements
    :initarg :elements
    :type (cl:vector hd_map-msg:element)
   :initform (cl:make-array 0 :element-type 'hd_map-msg:element :initial-element (cl:make-instance 'hd_map-msg:element))))
)

(cl:defclass elements (<elements>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <elements>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'elements)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hd_map-msg:<elements> is deprecated: use hd_map-msg:elements instead.")))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <elements>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:type-val is deprecated.  Use hd_map-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'motor_type-val :lambda-list '(m))
(cl:defmethod motor_type-val ((m <elements>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:motor_type-val is deprecated.  Use hd_map-msg:motor_type instead.")
  (motor_type m))

(cl:ensure-generic-function 'elements-val :lambda-list '(m))
(cl:defmethod elements-val ((m <elements>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:elements-val is deprecated.  Use hd_map-msg:elements instead.")
  (elements m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <elements>) ostream)
  "Serializes a message object of type '<elements>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor_type)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'elements))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'elements))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <elements>) istream)
  "Deserializes a message object of type '<elements>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor_type)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'elements) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'elements)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'hd_map-msg:element))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<elements>)))
  "Returns string type for a message object of type '<elements>"
  "hd_map/elements")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'elements)))
  "Returns string type for a message object of type 'elements"
  "hd_map/elements")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<elements>)))
  "Returns md5sum for a message object of type '<elements>"
  "6f63926c2c2a065e0bb8b36cbc47eb9b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'elements)))
  "Returns md5sum for a message object of type 'elements"
  "6f63926c2c2a065e0bb8b36cbc47eb9b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<elements>)))
  "Returns full string definition for message of type '<elements>"
  (cl:format cl:nil "uint8 type~%uint8 motor_type~%element[] elements~%~%================================================================================~%MSG: hd_map/element~%uint8 id~%uint8 color~%uint8 element_type~%sensor_msgs/PointCloud2 pointclouds~%uint8[] direction~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'elements)))
  "Returns full string definition for message of type 'elements"
  (cl:format cl:nil "uint8 type~%uint8 motor_type~%element[] elements~%~%================================================================================~%MSG: hd_map/element~%uint8 id~%uint8 color~%uint8 element_type~%sensor_msgs/PointCloud2 pointclouds~%uint8[] direction~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <elements>))
  (cl:+ 0
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'elements) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <elements>))
  "Converts a ROS message object to a list"
  (cl:list 'elements
    (cl:cons ':type (type msg))
    (cl:cons ':motor_type (motor_type msg))
    (cl:cons ':elements (elements msg))
))
