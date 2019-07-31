//
// Created by catalina on 2019/7/30.
//

#ifndef PROTO_TEST_MAP_READ_H
#define PROTO_TEST_MAP_READ_H
#include "utils/io.h"
#include "utils/calulate.h"
#include "proto/HDMap.pb.h"
#include "proto/LaneMarking.pb.h"
#include "proto/SourceInfo.pb.h"
#include "proto/TrafficLight.pb.h"
#include "tiff.h"
#include <vector>

//点位置
struct PointT{
    int id;
    double x;
    double y;
    double z;
};

//HDMap
struct HDMAP{
    //场景id，视频文件名
    string  scene_id;
//车道线
    vector<struct DividerEach> dividers;
//交通灯
   vector<struct TrafficLightEach> tafficlights;
//地面标识
    vector<struct LaneMarkingEach> lanemarkings;
    string  version;
};
//车道线
struct DividerEach{
    //编号
    int32  id;
//位置WKT
    vector <struct PointT>  divider_vec;
//    string geometry;
//颜色，0：未知；1：白色；2：黄色
    int32  color;
//类型 0:未知； 1：单虚线；2：单实线；3：双实线；4：左实右虚；5：左虚右实,；6:不可通行减速线；7：可通行减速线
    int32  type;
//遮挡程度，1：无；2：部分遮挡；3：全部遮挡(invalid)
    int32  occlusion;
};

struct TrafficLightEach{
//编号
    int32  id;
//位置WKT
    struct PointT point;
//类型，1：车辆；2：行人

    int32  motor_type;
//灯
   vector<struct LightEach> lights;
};

struct LightEach{
//编号
    int32  id;
//位置WKT
//    string  geometry;
//类型，1：竖排；2：横排
    struct PointT points;
    int32  direction;
};
//地面标识
struct LaneMarkingEach{
//编号
    int32 id;
//位置 WKT
//    vector<struct PointT> points;
    struct PointT points[5];
//类型，1：人行道；2：停止线；3：地面标识
    int32 type;
};

// GPS
struct GPSInfoEach{
    string scene_id;
//设备名称
    string device_id;
//GPS点集合
    vector<struct GPSPointEach> gpsPoints;
};

//GPS point
struct GPSPointEach{
    //编号
    int32 id;
//时间
    int64 gpstime;
//航向
    double heading;
//速度
    double speed;
//坐标 WKT
    struct PointT points;
};

class ReadHDMap {
protected:

public:
    GPSInfoEach getGPSInfoBySceneId(string scene_id);
    HDMAP getLandMarkingInHDMAP();
};


#endif //PROTO_TEST_MAP_READ_H
