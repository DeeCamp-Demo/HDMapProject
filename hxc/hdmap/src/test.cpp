//
// Created by catalina on 2019/8/1.
//
#include "test.h"
int main(){

//    test测试
//    std::string gps_file_name = "../data/gps/20190123112838_3faf30bde99e0f126cda2432ec90a621_4deecamp_gps.pb";
    string scene_id = "20190123112838_3faf30bde99e0f126cda2432ec90a621_4";
//    std::cout << "input scene_id: " << scene_id << endl;

//    根据scene_id获取相应的图像数据
    GPSInfoEach gpsInfoEach = ReadHDMap::getGPSInfoBySceneId(scene_id);
//      读取所有gpsInfo
//    std::cout << "get size: " << gpsInfoEach.gpsPoints.size() << endl;
//    读取hdMap
    HDMAP readMap = ReadHDMap::getHDMAP();
//    std::cout << "test hd map:" << readMap.tafficlights.data()->id << endl;

//    遍历gps文件,获取其文件名/scene_id/日期，根据日期大小编号存入数组
//      根据gps文件名，遍历image文件夹，取出指定图片名称集合
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
            cout << "gps files:" << gps_files[i]<<endl;
        }
    }

    int num = gps_files[10].find_last_of(".");
    string id = gps_files[10].substr(0, num-14);

    //    imageBatch要判空
    ImageBatch imageBatch = ReadHDMap::getImageBatchBySceneId(id);
    for (int i = 0; i < imageBatch.images_vec.size(); ++i) {
        cout << "image batch " << imageBatch.images_vec[i] << endl;
    }
}

