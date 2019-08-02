; Auto-generated. Do not edit!


(cl:in-package hd_map-msg)


;//! \htmlinclude element.msg.html

(cl:defclass <element> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (color
    :reader color
    :initarg :color
    :type cl:fixnum
    :initform 0)
   (element_type
    :reader element_type
    :initarg :element_type
    :type cl:fixnum
    :initform 0)
   (pointclouds
    :reader pointclouds
    :initarg :pointclouds
    :type sensor_msgs-msg:PointCloud2
    :initform (cl:make-instance 'sensor_msgs-msg:PointCloud2))
   (direction
    :reader direction
    :initarg :direction
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass element (<element>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <element>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'element)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hd_map-msg:<element> is deprecated: use hd_map-msg:element instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <element>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:id-val is deprecated.  Use hd_map-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <element>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:color-val is deprecated.  Use hd_map-msg:color instead.")
  (color m))

(cl:ensure-generic-function 'element_type-val :lambda-list '(m))
(cl:defmethod element_type-val ((m <element>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:element_type-val is deprecated.  Use hd_map-msg:element_type instead.")
  (element_type m))

(cl:ensure-generic-function 'pointclouds-val :lambda-list '(m))
(cl:defmethod pointclouds-val ((m <element>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:pointclouds-val is deprecated.  Use hd_map-msg:pointclouds instead.")
  (pointclouds m))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <element>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hd_map-msg:direction-val is deprecated.  Use hd_map-msg:direction instead.")
  (direction m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <element>) ostream)
  "Serializes a message object of type '<element>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'color)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'element_type)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointclouds) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'direction))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'direction))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <element>) istream)
  "Deserializes a message object of type '<element>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'color)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'element_type)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointclouds) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'direction) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'direction)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<element>)))
  "Returns string type for a message object of type '<element>"
  "hd_map/element")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'element)))
  "Returns string type for a message object of type 'element"
  "hd_map/element")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<element>)))
  "Returns md5sum for a message object of type '<element>"
  "b5b86d1178a9149c51a2d5dfef164311")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'element)))
  "Returns md5sum for a message object of type 'element"
  "b5b86d1178a9149c51a2d5dfef164311")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<element>)))
  "Returns full string definition for message of type '<element>"
  (cl:format cl:nil "uint8 id~%uint8 color~%uint8 element_type~%sensor_msgs/PointCloud2 pointclouds~%uint8[] direction~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'element)))
  "Returns full string definition for message of type 'element"
  (cl:format cl:nil "uint8 id~%uint8 color~%uint8 element_type~%sensor_msgs/PointCloud2 pointclouds~%uint8[] direction~%~%================================================================================~%MSG: sensor_msgs/PointCloud2~%# This message holds a collection of N-dimensional points, which may~%# contain additional information such as normals, intensity, etc. The~%# point data is stored as a binary blob, its layout described by the~%# contents of the \"fields\" array.~%~%# The point cloud data may be organized 2d (image-like) or 1d~%# (unordered). Point clouds organized as 2d images may be produced by~%# camera depth sensors such as stereo or time-of-flight.~%~%# Time of sensor data acquisition, and the coordinate frame ID (for 3d~%# points).~%Header header~%~%# 2D structure of the point cloud. If the cloud is unordered, height is~%# 1 and width is the length of the point cloud.~%uint32 height~%uint32 width~%~%# Describes the channels and their layout in the binary data blob.~%PointField[] fields~%~%bool    is_bigendian # Is this data bigendian?~%uint32  point_step   # Length of a point in bytes~%uint32  row_step     # Length of a row in bytes~%uint8[] data         # Actual point data, size is (row_step*height)~%~%bool is_dense        # True if there are no invalid points~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/PointField~%# This message holds the description of one point entry in the~%# PointCloud2 message format.~%uint8 INT8    = 1~%uint8 UINT8   = 2~%uint8 INT16   = 3~%uint8 UINT16  = 4~%uint8 INT32   = 5~%uint8 UINT32  = 6~%uint8 FLOAT32 = 7~%uint8 FLOAT64 = 8~%~%string name      # Name of field~%uint32 offset    # Offset from start of point struct~%uint8  datatype  # Datatype enumeration, see above~%uint32 count     # How many elements in the field~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <element>))
  (cl:+ 0
     1
     1
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointclouds))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'direction) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <element>))
  "Converts a ROS message object to a list"
  (cl:list 'element
    (cl:cons ':id (id msg))
    (cl:cons ':color (color msg))
    (cl:cons ':element_type (element_type msg))
    (cl:cons ':pointclouds (pointclouds msg))
    (cl:cons ':direction (direction msg))
))
