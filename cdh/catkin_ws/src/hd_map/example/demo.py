#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Python includeswhich
import numpy
import random

# ROS includes
import roslib
import rospy
from geometry_msgs.msg import Pose, Point, Quaternion, Vector3, Polygon
from tf import transformations # rotation_matrix(), concatenate_matrices()

import hd_map.rviz_tools as rviz_tools

from hd_map.readpb import Divider
from hd_map.readpb import read_from_pb, read_divider

import sys
sys.path.append("..")
import hd_map.readpb as readpb

# Initialize the ROS Node
rospy.init_node('test', anonymous=False, log_level=rospy.INFO, disable_signals=False)

# Define exit handler
def cleanup_node():
    print "Shutting down node"
    markers.deleteAllMarkers()

# rospy.on_shutdown(cleanup_node)


markers = rviz_tools.RvizMarkers('/map', 'visualization_marker')
message = readpb.read_from_pb_debug()
points = readpb.read_divider(message)


while not rospy.is_shutdown():

    # Axis:

    # Publish an axis using a numpy transform matrix
    T = transformations.translation_matrix((1,0,0))
    axis_length = 0.4
    axis_radius = 0.05
    markers.publishAxis(T, axis_length, axis_radius, 5.0) # pose, axis length, radius, lifetime

    # Publish an axis using a ROS Pose Msg
    P = Pose(Point(2,0,0),Quaternion(0,0,0,1))
    axis_length = 0.4
    axis_radius = 0.05
    markers.publishAxis(P, axis_length, axis_radius, 5.0) # pose, axis length, radius, lifetime

    rviz_tools.genPublishPath_simple(points, markers)
    
    rospy.Rate(1).sleep() #1 Hz
