# 接口说明文档


> hdmap :项目工程总目录
>
> 将proto目录,utils目录下三个.h头文件全部拷贝到自己的工程目录里面,并此目录下的删除.h和.cc文件.
>
> 安装protobuf,在此目录下执行 protoc --cpp-out=.  *.proto生成.h和.cc文件
>
> data目录下的文件夹需要严格保持一致.
>
> read_map中定义了以下接口标准
>

```c++
HDMAP getHDMAP() //读取整张高精地图所有元素位置
GPSInfoEach getGPSInfoBySceneId; //根据scene_id获取指定的GPS帧数据信息
vector<ImageBatch> getAllImageBatch() //获取高精地图每一帧GPS及其对应的图像集合,按顺序取
ImageBatch getImageBatchBySceneId(string scene_id2)//根据scene_id获取帧GPS及其对应的兔相机和
GpsImageBatch getGpsImageBatchByImageId(string scene_id2, int index);//根据图片的scene_id和index获取指定的GPS点及headiing信息
vector<GpsImageBatch> getAllGpsImageBatch() //获取所有的GPS点及其对应的一帧图像
```

### 接口调用示例

在test.cpp里面写了接口的调用方法

- 1.在main.cpp里面 #include "read_hdmap.h"

- 2.在main.cpp中即可调用指定的方法获取高精地图数据

```c++
//    test测试
    string scene_id = "20190123112838_3faf30bde99e0f126cda2432ec90a621_4";

//    根据scene_id获取GPS数据
    GPSInfoEach gpsInfoEach = ReadHDMap::getGPSInfoBySceneId(scene_id);
    vector<GPSPointEach> points = gpsInfoEach.gpsPoints;
    for (int k = 0; k < points.size(); ++k) {
//        cout << " points:" << points[k].points.x<<"," << points[k].points.y << "," << points[k].points.z << endl;
//        cout << " heading:" << points[k].heading << endl;
    }

//    读取hdMap
    HDMAP readMap = ReadHDMap::getHDMAP();
    vector<DividerEach> dividerEach = readMap.dividers;
    for (int j = 0; j < dividerEach.size(); ++j) {
//        std::cout << "test hd map:" << readMap.dividers[19].divider_vec[5].x << endl;
    }

//    根据scene_id获取相应图片名称集合,按顺序存储
    vector<ImageBatch> dataFiles = ReadHDMap::getAllImageBatch();
//    cout << "dfgfb:"<< dataFiles.size()<<" dfgfd:"<< dataFiles[100].images_vec.size()<< endl;

    const string  gps_file_folder = "../data/gps";
    vector<string> gps_files;
    bool flag = calulate::getAllFiles(gps_file_folder,gps_files);
//  需要自行判断fileName是否存在 flag 0正确查询  -1 错误查询
    calulate::sortedVector(gps_files);
    if (flag == 0)
    {
        for (int i = 0; i < gps_files.size(); ++i) {
//            cout << "gps files:" << gps_files[i]<<endl;
        }
    }

    int num = gps_files[10].find_last_of(".");
    string id = gps_files[10].substr(0, num-14);

    //    imageBatch要判空
    ImageBatch imageBatch = ReadHDMap::getImageBatchBySceneId(id);
    for (int i = 0; i < imageBatch.images_vec.size(); ++i) {
//        cout << "image batch " << imageBatch.images_vec[i] << endl;
    }

//    获取gps点与对应一张图片
    vector<GpsImageBatch> gpsImageBatch_vec = ReadHDMap::getAllGpsImageBatch();
    GpsImageBatch gpsImageBatch = ReadHDMap::getGpsImageBatchByImageId(scene_id, 2);
    cout << "gps heading"<<gpsImageBatch.gpsPoint.heading<<endl;
}

```

## 数据结构

```c++
//点位置
typedef struct PointT{
    int id;
    double x;
    double y;
    double z;
};

//HDMap
typedef struct HDMAP{
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
typedef struct DividerEach{
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

typedef struct TrafficLightEach{
//编号
    int32  id;
//位置WKT
    struct PointT point;
//类型，1：车辆；2：行人

    int32  motor_type;
//灯
   vector<struct LightEach> lights;
};

typedef struct LightEach{
//编号
    int32  id;
//位置WKT
//    string  geometry;
//类型，1：竖排；2：横排
    struct PointT points;
    int32  direction;
};
//地面标识
typedef struct LaneMarkingEach{
//编号
    int32 id;
//位置 WKT
//    vector<struct PointT> points;
    struct PointT points[5];
//类型，1：人行道；2：停止线；3：地面标识
    int32 type;
};

// GPS
typedef struct GPSInfoEach{
    string scene_id;
//设备名称
    string device_id;
//GPS点集合
    vector<struct GPSPointEach> gpsPoints;
};

//GPS point
typedef struct GPSPointEach{
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

struct ImageBatch{
//    GPS帧id
    string scene_id;
//    对应image帧集合
    vector<string> images_vec;

};

struct GpsImageBatch{
//    gps帧id
    string scene_id;
//    对应图片文件名
    string image_name;
    GPSPointEach gpsPoint;
};
```

