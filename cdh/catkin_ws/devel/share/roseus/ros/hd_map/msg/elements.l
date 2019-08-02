;; Auto-generated. Do not edit!


(when (boundp 'hd_map::elements)
  (if (not (find-package "HD_MAP"))
    (make-package "HD_MAP"))
  (shadow 'elements (find-package "HD_MAP")))
(unless (find-package "HD_MAP::ELEMENTS")
  (make-package "HD_MAP::ELEMENTS"))

(in-package "ROS")
;;//! \htmlinclude elements.msg.html


(defclass hd_map::elements
  :super ros::object
  :slots (_type _motor_type _elements ))

(defmethod hd_map::elements
  (:init
   (&key
    ((:type __type) 0)
    ((:motor_type __motor_type) 0)
    ((:elements __elements) (let (r) (dotimes (i 0) (push (instance hd_map::element :init) r)) r))
    )
   (send-super :init)
   (setq _type (round __type))
   (setq _motor_type (round __motor_type))
   (setq _elements __elements)
   self)
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:motor_type
   (&optional __motor_type)
   (if __motor_type (setq _motor_type __motor_type)) _motor_type)
  (:elements
   (&rest __elements)
   (if (keywordp (car __elements))
       (send* _elements __elements)
     (progn
       (if __elements (setq _elements (car __elements)))
       _elements)))
  (:serialization-length
   ()
   (+
    ;; uint8 _type
    1
    ;; uint8 _motor_type
    1
    ;; hd_map/element[] _elements
    (apply #'+ (send-all _elements :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _type
       (write-byte _type s)
     ;; uint8 _motor_type
       (write-byte _motor_type s)
     ;; hd_map/element[] _elements
     (write-long (length _elements) s)
     (dolist (elem _elements)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _type
     (setq _type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _motor_type
     (setq _motor_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; hd_map/element[] _elements
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _elements (let (r) (dotimes (i n) (push (instance hd_map::element :init) r)) r))
     (dolist (elem- _elements)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get hd_map::elements :md5sum-) "6f63926c2c2a065e0bb8b36cbc47eb9b")
(setf (get hd_map::elements :datatype-) "hd_map/elements")
(setf (get hd_map::elements :definition-)
      "uint8 type
uint8 motor_type
element[] elements

================================================================================
MSG: hd_map/element
uint8 id
uint8 color
uint8 element_type
sensor_msgs/PointCloud2 pointclouds
uint8[] direction

================================================================================
MSG: sensor_msgs/PointCloud2
# This message holds a collection of N-dimensional points, which may
# contain additional information such as normals, intensity, etc. The
# point data is stored as a binary blob, its layout described by the
# contents of the \"fields\" array.

# The point cloud data may be organized 2d (image-like) or 1d
# (unordered). Point clouds organized as 2d images may be produced by
# camera depth sensors such as stereo or time-of-flight.

# Time of sensor data acquisition, and the coordinate frame ID (for 3d
# points).
Header header

# 2D structure of the point cloud. If the cloud is unordered, height is
# 1 and width is the length of the point cloud.
uint32 height
uint32 width

# Describes the channels and their layout in the binary data blob.
PointField[] fields

bool    is_bigendian # Is this data bigendian?
uint32  point_step   # Length of a point in bytes
uint32  row_step     # Length of a row in bytes
uint8[] data         # Actual point data, size is (row_step*height)

bool is_dense        # True if there are no invalid points

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: sensor_msgs/PointField
# This message holds the description of one point entry in the
# PointCloud2 message format.
uint8 INT8    = 1
uint8 UINT8   = 2
uint8 INT16   = 3
uint8 UINT16  = 4
uint8 INT32   = 5
uint8 UINT32  = 6
uint8 FLOAT32 = 7
uint8 FLOAT64 = 8

string name      # Name of field
uint32 offset    # Offset from start of point struct
uint8  datatype  # Datatype enumeration, see above
uint32 count     # How many elements in the field

")



(provide :hd_map/elements "6f63926c2c2a065e0bb8b36cbc47eb9b")


