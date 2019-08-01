#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/apple/catkin_ws/src/hd_map"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/apple/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/apple/catkin_ws/install/lib/python2.7/dist-packages:/home/apple/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/apple/catkin_ws/build" \
    "/home/apple/anaconda3/envs/py27/bin/python" \
    "/home/apple/catkin_ws/src/hd_map/setup.py" \
    build --build-base "/home/apple/catkin_ws/build/hd_map" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/apple/catkin_ws/install" --install-scripts="/home/apple/catkin_ws/install/bin"
