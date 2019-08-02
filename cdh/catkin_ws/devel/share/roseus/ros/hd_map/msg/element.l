;; Auto-generated. Do not edit!


(when (boundp 'hd_map::element)
  (if (not (find-package "HD_MAP"))
    (make-package "HD_MAP"))
  (shadow 'element (find-package "HD_MAP")))
(unless (find-package "HD_MAP::ELEMENT")
  (make-package "HD_MAP::ELEMENT"))

(in-package "ROS")
;;//! \htmlinclude element.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(defclass hd_map::element
  :super ros::object
  :slots (_id _color _element_type _pointclouds _direction ))

(defmethod hd_map::element
  (:init
   (&key
    ((:id __id) 0)
    ((:color __color) 0)
    ((:element_type __element_type) 0)
    ((:pointclouds __pointclouds) (instance sensor_msgs::PointCloud2 :init))
    ((:direction __direction) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _color (round __color))
   (setq _element_type (round __element_type))
   (setq _pointclouds __pointclouds)
   (setq _direction __direction)
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:element_type
   (&optional __element_type)
   (if __element_type (setq _element_type __element_type)) _element_type)
  (:pointclouds
   (&rest __pointclouds)
   (if (keywordp (car __pointclouds))
       (send* _pointclouds __pointclouds)
     (progn
       (if __pointclouds (setq _pointclouds (car __pointclouds)))
       _pointclouds)))
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ;; uint8 _color
    1
    ;; uint8 _element_type
    1
    ;; sensor_msgs/PointCloud2 _pointclouds
    (send _pointclouds :serialization-length)
    ;; uint8[] _direction
    (* 1    (length _direction)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;; uint8 _color
       (write-byte _color s)
     ;; uint8 _element_type
       (write-byte _element_type s)
     ;; sensor_msgs/PointCloud2 _pointclouds
       (send _pointclouds :serialize s)
     ;; uint8[] _direction
     (write-long (length _direction) s)
     (princ _direction s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _color
     (setq _color (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _element_type
     (setq _element_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; sensor_msgs/PointCloud2 _pointclouds
     (send _pointclouds :deserialize buf ptr-) (incf ptr- (send _pointclouds :serialization-length))
   ;; uint8[] _direction
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _direction (make-array n :element-type :char))
     (replace _direction buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get hd_map::element :md5sum-) "b5b86d1178a9149c51a2d5dfef164311")
(setf (get hd_map::element :datatype-) "hd_map/element")
(setf (get hd_map::element :definition-)
      "uint8 id
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



(provide :hd_map/element "b5b86d1178a9149c51a2d5dfef164311")


