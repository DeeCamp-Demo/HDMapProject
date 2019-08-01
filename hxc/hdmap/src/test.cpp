//
// Created by catalina on 2019/8/1.
//
#include "test.h"
int main(){
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

// 根据指定id
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

