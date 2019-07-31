//
// Created by catalina on 2019/7/30.
//

#include "ReadHDMap.h"
GPSInfoEach getGPSInfoBySceneId(string scene_id) {
    std::cout << "scene_id: " << scene_id << endl;
    string file_name = "../data/gps/"+scene_id+"deecamp_gps.pb";
    std::cout << "file_name: " << file_name << endl;

    fstream input_gps(file_name, ios::in | ios::binary);
    source::GPSInfo gpsInfo;

    if (gpsInfo.scene_id().compare(scene_id))
    {
        gpsInfo.ParseFromIstream(&input_gps);
        source::GPSPoint gpsPoint;
        gpsPoint.ParseFromIstream(&input_gps);

//        一帧GPS数据信息
        GPSInfoEach gpsInfoEach;
        gpsInfoEach.scene_id = gpsInfo.scene_id();

        for (int l = 0; l < gpsInfo.pts_size(); ++l) {
            source::GPSPoint pts = gpsInfo.pts(l);
            GPSPointEach gpsPointEach;
            gpsPointEach.heading = pts.heading();
            gpsPointEach.id = pts.id();
            gpsPointEach.gpstime = pts.gpstime();
            gpsPointEach.speed = pts.speed();
//        处理geometry
            vector<double> geom;
            calulate::extractFiguresFromStr2Vec(pts.geometry(),geom);
            gpsPointEach.points.x = geom[0];
            gpsPointEach.points.y = geom[1];
            gpsPointEach.points.z = geom[2];
            gpsInfoEach.gpsPoints.push_back(gpsPointEach);

//            std::cout << std::setprecision(14) <<geom[0] << " " << geom[1] << " " <<geom[2]<<endl;
//            std::cout << "pts:" << pts.geometry().substr(9, 34)<< endl;
            //        gpsInfoEach.gpsPoints.push_back(gpsPointEach);
        }
        return gpsInfoEach;
    } else{
        std::cout << "不存在此帧数据: " << endl;
    }


}

HDMAP getLandMarkingInHDMAP() {
    std::string file_name = "../data/hdmap/hdmap_deecamp.pb";

    fstream input(file_name, ios::in | ios::binary);
    hdmap::HDMap map;
    map.ParseFromIstream(&input);

    HDMAP readMap; //高精地图所有数据
    readMap.version = map.version();
    readMap.scene_id = map.scene_id();

    LaneMarkingEach laneMarkingEach; //高精地图中的所有路标
    TrafficLightEach trafficLightEach;//高精地图中的所有交通灯
    DividerEach dividerEach;//高精地图中的所有车道线

    cout<<"lanemarkings_size size:"<<map.lanemarkings_size() << endl;
    //    读取所有的地面标识
    for (int i = 0; i < map.lanemarkings_size(); ++i) {
        hdmap::LaneMarking laneMarking = map.lanemarkings(i);
        string geometry = laneMarking.geometry();

        laneMarkingEach.id = laneMarking.id();
        laneMarkingEach.type = laneMarking.type();

//        提取geomery字段中的坐标数据
        vector<double> geom;
        calulate::extractFiguresFromStr2Vec(laneMarking.geometry(), geom);

//        cout << std::setprecision(14) << laneMarkingEach.id <<"--------- "<< endl;
        if (geom.size() == 15) {
//            cout << geom[0] << " " << geom[1] << " " << geom[2] << endl;
            for (int j = 0; j < 5; ++j) {
                laneMarkingEach.points[j].x = geom[3 * j];
                laneMarkingEach.points[j].y = geom[3 * j + 1];
                laneMarkingEach.points[j].z = geom[3 * j + 2];
//                cout << std::setprecision(14)<<  laneMarkingEach.points[j].x << " " << laneMarkingEach.points[j].y
//                     << " " << laneMarkingEach.points[j].z << endl;
            }
            readMap.lanemarkings.push_back(laneMarkingEach);
        } else
        {
              cout <<  "laneMarking 位置读取有误 "<< endl;
        }
    }

    cout<<"tafficlights_size size:"<<map.tafficlights_size() << endl;
//    读取所有的交通灯
    for (int k = 0; k < map.tafficlights_size(); ++k) {
        hdmap::TrafficLight trafficLight = map.tafficlights(k);
        trafficLightEach.id = trafficLight.id();
        trafficLightEach.motor_type = trafficLight.motor_type();
        string geometry = trafficLight.geometry();
        cout << "traffic light:" << geometry <<endl;
        vector<double> geom;
        calulate::extractFiguresFromStr2Vec(geometry, geom);

        if(geom.size() == 3)
        {
            trafficLightEach.point.x = geom[0];
            trafficLightEach.point.y = geom[1];
            trafficLightEach.point.z = geom[2];

//            cout << std::setprecision(14)<<  trafficLightEach.point.x << " " << trafficLightEach.point.y
//                 << " " << trafficLightEach.point.z << endl;
//            Light 里面的数据继续查询

            LightEach lightEach; //第二次进来，lightEach归0
            for (int i = 0; i < trafficLight.lights_size(); ++i) {
                lightEach.id = trafficLight.lights(i).id();
                lightEach.direction = trafficLight.lights(i).direction();

                vector<LightEach> lights_vector;
                vector<double > geom2;
                calulate::extractFiguresFromStr2Vec(trafficLight.lights(i).geometry(), geom2);
                if (geom2.size()==3)
                {
                    PointT point;
                    point.x = geom2[0];
                    point.y = geom2[1];
                    point.z = geom2[2];

                    lightEach.points.x = geom2[0];
                    lightEach.points.y = geom2[1];
                    lightEach.points.z = geom2[2];
                    lights_vector.push_back(lightEach);
                }
                trafficLightEach.lights = lights_vector;
            }
            trafficLightEach.lights.push_back(lightEach);
        } else{
            cout <<  "trafficLights 位置读取有误 "<< endl;
        }
        readMap.tafficlights.push_back(trafficLightEach);
    }

    cout<<"dividers_size size:"<<map.dividers_size() << endl;
    for (int l = 0; l < map.dividers_size(); ++l) {
        hdmap::Divider divider = map.dividers(l);
        dividerEach.id = divider.id();
        dividerEach.type = divider.type();
        dividerEach.color = divider.color();
        dividerEach.occlusion = divider.occlusion();

        vector<double > geom;
        calulate::extractFiguresFromStr2Vec(divider.geometry(), geom);
//        cout << "geom----"<<geom.size()/3 <<" ----" << geom[0] << " " << geom[1] << " " << geom[2] << endl;
        int pointsNum = geom.size()/3;
//        cout << "----id----"<< dividerEach.id <<"-----" <<pointsNum << "------"<<endl;
        vector<PointT> vetor;
        for (int i = 0; i < geom.size(); ++i) {
            PointT point;
            point.x = geom[i*3];
            point.y = geom[i*3+1];
            point.z = geom[i*3+2];
            if (i%3==0)
            {
                vetor.push_back(point);
            }
//            cout <<std::setprecision(14) << geom[i*3] <<" " << geom[i*3+1] << " " << geom[i*3+2] << endl;
        }
        dividerEach.divider_vec = vetor;

//        cout << "----id----"<< dividerEach.id << endl;
        readMap.dividers.push_back(dividerEach);
    }
    return readMap;
}
int main(){

//    test测试
    std::string file_name = "../data/hdmap/hdmap_deecamp.pb";
    std::string file_name2 = "../data/gps/20190123112838_3faf30bde99e0f126cda2432ec90a621_4deecamp_gps.pb";

    string scene_id = file_name2.substr(12, 49);
    std::cout << "input scene_id: " << scene_id << endl;

//    根据scene_id获取相应的图像数据
    GPSInfoEach gpsInfoEach = getGPSInfoBySceneId(scene_id);
//      读取所有gpsInfo
//    std::cout << "get size: " << gpsInfoEach.gpsPoints.size() << endl;
//    读取hdMap
    HDMAP readMap = getLandMarkingInHDMAP();


}