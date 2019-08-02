// Auto-generated. Do not edit!

// (in-package hd_map.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let element = require('./element.js');

//-----------------------------------------------------------

class elements {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.type = null;
      this.motor_type = null;
      this.elements = null;
    }
    else {
      if (initObj.hasOwnProperty('type')) {
        this.type = initObj.type
      }
      else {
        this.type = 0;
      }
      if (initObj.hasOwnProperty('motor_type')) {
        this.motor_type = initObj.motor_type
      }
      else {
        this.motor_type = 0;
      }
      if (initObj.hasOwnProperty('elements')) {
        this.elements = initObj.elements
      }
      else {
        this.elements = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type elements
    // Serialize message field [type]
    bufferOffset = _serializer.uint8(obj.type, buffer, bufferOffset);
    // Serialize message field [motor_type]
    bufferOffset = _serializer.uint8(obj.motor_type, buffer, bufferOffset);
    // Serialize message field [elements]
    // Serialize the length for message field [elements]
    bufferOffset = _serializer.uint32(obj.elements.length, buffer, bufferOffset);
    obj.elements.forEach((val) => {
      bufferOffset = element.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type elements
    let len;
    let data = new elements(null);
    // Deserialize message field [type]
    data.type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [motor_type]
    data.motor_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [elements]
    // Deserialize array length for message field [elements]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.elements = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.elements[i] = element.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.elements.forEach((val) => {
      length += element.getMessageSize(val);
    });
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'hd_map/elements';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6f63926c2c2a065e0bb8b36cbc47eb9b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 type
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
    # contents of the "fields" array.
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new elements(null);
    if (msg.type !== undefined) {
      resolved.type = msg.type;
    }
    else {
      resolved.type = 0
    }

    if (msg.motor_type !== undefined) {
      resolved.motor_type = msg.motor_type;
    }
    else {
      resolved.motor_type = 0
    }

    if (msg.elements !== undefined) {
      resolved.elements = new Array(msg.elements.length);
      for (let i = 0; i < resolved.elements.length; ++i) {
        resolved.elements[i] = element.Resolve(msg.elements[i]);
      }
    }
    else {
      resolved.elements = []
    }

    return resolved;
    }
};

module.exports = elements;
