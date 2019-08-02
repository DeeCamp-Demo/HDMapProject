// Auto-generated. Do not edit!

// (in-package hd_map.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let sensor_msgs = _finder('sensor_msgs');

//-----------------------------------------------------------

class element {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.id = null;
      this.color = null;
      this.element_type = null;
      this.pointclouds = null;
      this.direction = null;
    }
    else {
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('color')) {
        this.color = initObj.color
      }
      else {
        this.color = 0;
      }
      if (initObj.hasOwnProperty('element_type')) {
        this.element_type = initObj.element_type
      }
      else {
        this.element_type = 0;
      }
      if (initObj.hasOwnProperty('pointclouds')) {
        this.pointclouds = initObj.pointclouds
      }
      else {
        this.pointclouds = new sensor_msgs.msg.PointCloud2();
      }
      if (initObj.hasOwnProperty('direction')) {
        this.direction = initObj.direction
      }
      else {
        this.direction = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type element
    // Serialize message field [id]
    bufferOffset = _serializer.uint8(obj.id, buffer, bufferOffset);
    // Serialize message field [color]
    bufferOffset = _serializer.uint8(obj.color, buffer, bufferOffset);
    // Serialize message field [element_type]
    bufferOffset = _serializer.uint8(obj.element_type, buffer, bufferOffset);
    // Serialize message field [pointclouds]
    bufferOffset = sensor_msgs.msg.PointCloud2.serialize(obj.pointclouds, buffer, bufferOffset);
    // Serialize message field [direction]
    bufferOffset = _arraySerializer.uint8(obj.direction, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type element
    let len;
    let data = new element(null);
    // Deserialize message field [id]
    data.id = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [color]
    data.color = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [element_type]
    data.element_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [pointclouds]
    data.pointclouds = sensor_msgs.msg.PointCloud2.deserialize(buffer, bufferOffset);
    // Deserialize message field [direction]
    data.direction = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += sensor_msgs.msg.PointCloud2.getMessageSize(object.pointclouds);
    length += object.direction.length;
    return length + 7;
  }

  static datatype() {
    // Returns string type for a message object
    return 'hd_map/element';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b5b86d1178a9149c51a2d5dfef164311';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new element(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.color !== undefined) {
      resolved.color = msg.color;
    }
    else {
      resolved.color = 0
    }

    if (msg.element_type !== undefined) {
      resolved.element_type = msg.element_type;
    }
    else {
      resolved.element_type = 0
    }

    if (msg.pointclouds !== undefined) {
      resolved.pointclouds = sensor_msgs.msg.PointCloud2.Resolve(msg.pointclouds)
    }
    else {
      resolved.pointclouds = new sensor_msgs.msg.PointCloud2()
    }

    if (msg.direction !== undefined) {
      resolved.direction = msg.direction;
    }
    else {
      resolved.direction = []
    }

    return resolved;
    }
};

module.exports = element;
