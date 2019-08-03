//
// Created by catalina on 2019/8/1.
//
#include "test.h"
#include "utils/Utils.h"
#include<pcl/visualization/pcl_visualizer.h>
#include<pcl/point_types.h>
using namespace std;
typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

cv::Mat K;
cv::Mat distCoeffs;
cv::Mat Rcb;
cv::Mat mTcb = cv::Mat::eye(4, 4, CV_64F);
string scene_id = "20190123112838_3faf30bde99e0f126cda2432ec90a621_4";

int main(){

  /*  // 坐标转换部分
    Utils::new3s_PointXYZ original;
    Utils::new3s_PointXYZ object1, object2, object3, object4;

    original.set_x(22.68253240);
    original.set_y(114.37142933);
    original.set_z(0);
    // lon是经度 lat是纬度
    object1.set_x(22.68253905);
    object1.set_y(114.37144419);
    object1.set_z(0);

    Utils::new3s_PointXYZ enu_coord_1;
    Utils transform;
    transform.convertCJC02ToENU(object1, enu_coord_1, original);

    //    位姿解算
    std::cout<<std::setprecision(11)<<enu_coord_1.get_x()<<" "<<enu_coord_1.get_y()<<" "<<enu_coord_1.get_z()<<std::endl;

    const std::string strCameraPath = "../config/param.yml";
    cv::FileStorage fSettings(strCameraPath, cv::FileStorage::READ);
    float fx = fSettings["Camera.fx"];
    float fy = fSettings["Camera.fy"];
    float cx = fSettings["Camera.cx"];
    float cy = fSettings["Camera.cy"];

    float k1 = fSettings["Camera.k1"];
    float k2 = fSettings["Camera.k2"];
    float p1 = fSettings["Camera.p1"];
    float p2 = fSettings["Camera.p2"];

    float yaw = fSettings["Cam.yaw"];
    float pitch = fSettings["Cam.pitch"];
    float roll = fSettings["Cam.roll"];

    // 这里的K和distCoeffs都是全局变量
    K = (cv::Mat_<float>(3, 3) <<
                               fx, 0.0, cx,
            0.0, fy, cy,
            0.0, 0.0, 1.0);
    distCoeffs = (cv::Mat_<float>(4, 1) << k1, k2, p1, p2);

    // 正常Tcb的值的初始化和计算只需进行一次，因此这里代码应该放在主函数里
    Eigen::Vector3d ea0(yaw,pitch,roll);
    Eigen::Matrix3d Rcb;
    cv::Mat mRcb;
    Rcb = Eigen::AngleAxisd(ea0[0], Eigen::Vector3d::UnitZ())*Eigen::AngleAxisd(ea0[1], Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(ea0[2], Eigen::Vector3d::UnitX());
    cv::eigen2cv(Rcb, mRcb);

    mRcb.copyTo(mTcb.rowRange(0, 3).colRange(0, 3));
    mTcb.row(2).col(3) = 1.32;

    std::cout<<"mTcb: "<<mTcb<<std::endl;*/

//    string scene_id = "20190123112838_3faf30bde99e0f126cda2432ec90a621_4";

    //    获取gps点与对应一张图片
/*    vector<GpsImageBatch> gpsImageBatch_vec = ReadHDMap::getAllGpsImageBatch();
    GpsImageBatch gpsImageBatch = ReadHDMap::getGpsImageBatchByImageId(scene_id, 2);
    cout << "gps heading"<<gpsImageBatch.gpsPoint.heading<<endl;
    cv::Mat mTbw = cv::Mat::eye(4, 4, CV_64F);
    cv::Mat mRbw;
    Utils poseCompute;*/
//    // 这里读取到第一个帧的车的偏角
//    double header_former;
//    mRbw = poseCompute.convertAngleToR(header_former);
//    mRbw.copyTo(mTbw.rowRange(0, 3).colRange(0, 3));
//    // 这里假定我得到了第二个帧的车的偏角
//    double header_now;
//    // 这个是返回的NEU坐标系的点的差
//    double add_t[3];
//    // 对于初始的pose
//    cv::Mat pose = mTbw;

//    cv::Mat now_pose = poseCompute.updatePose(pose, header_former, header_now, add_t);
//    cv::Mat camera_pose = mTcb * now_pose;
/************************************************************************************************************
 *    根据scene_id获取GPS数据
 ************************************************************************************************************/
//    取GPS第一个点 (起始位置)
    /*  vector<GPSInfoEach> gpsInfo_vec;
      bool flag = ReadHDMap::getGPSInfo(gpsInfo_vec);
      if (flag)
      {
          GPSPointEach gpsPointEach = gpsInfo_vec[0].gpsPoints[0];
          cout<< "gpsPointEach:"<<gpsPointEach.points.x << " y, " << gpsPointEach.points.y<< " z, " << gpsPointEach.points.z << endl;
      }*/
/************************************************************************************************************
 *    根据scene_id获取GPS数据
 ************************************************************************************************************/
/*    GPSInfoEach gpsInfoEach = ReadHDMap::getGPSInfoBySceneId(scene_id);
    vector<GPSPointEach> points = gpsInfoEach.gpsPoints;
    for (int k = 0; k < points.size(); ++k) {
        cout << " points:" << points[k].points.x<<"," << points[k].points.y << "," << points[k].points.z << endl;
        cout << " heading:" << points[k].heading << endl;
    }*/
/************************************************************************************************************
*    读取整张hdmap高精地图元素
************************************************************************************************************/
    /*HDMAP readMap = ReadHDMap::getHDMAP();
    vector<DividerEach> dividerEach = readMap.dividers;
    for (int j = 0; j < dividerEach.size(); ++j) {
        std::cout << "test hd map:" << readMap.dividers[19].divider_vec[5].x << endl;
    }*/

/************************************************************************************************************
 *    获取每一帧GPS及其对应的图片名称集合,按顺序存储
 ************************************************************************************************************/
/*    vector<ImageBatch> imageBatch_vec;
    bool flag3 = ReadHDMap::getAllImageBatch(imageBatch_vec);
//    cout << "dfgfb:"<< dataFiles.size()<<" dfgfd:"<< dataFiles[100].images_vec.size()<< endl;

    if(flag3)
    {
        cout << "image batch ok" << endl;
    }*/

/************************************************************************************************************
 *    // 根据指定scene_id查询此帧gps数据点,按顺序输出
 ************************************************************************************************************/
/*    const string  gps_file_folder = "../data/gps";
    vector<string> gps_vec;
    bool flag = calulate::getAllFiles(gps_file_folder,gps_vec);
//  需要自行判断fileName是否存在 flag 0正确查询  -1 错误查询
    calulate::sortedVector(gps_vec);
    if (flag)
    {
        for (int i = 0; i < gps_vec.size(); ++i) {
//            cout << "gps files:" << gps_files[i]<<endl;
        }
    }
    int num = gps_vec[10].find_last_of(".");
    string id = gps_vec[10].substr(0, num-14);
    ImageBatch imageBatch;
    bool flag4 = ReadHDMap::getImageBatchBySceneId(id, imageBatch);
    if (flag4)
    {
        for (int i = 0; i < imageBatch.images_vec.size(); ++i) {
//        cout << "image batch " << imageBatch.images_vec[i] << endl;
        }
    }*/
/************************************************************************************************************
 *    获取每一个gps点+对应一张图片
 ************************************************************************************************************/
//    vector<GpsImageBatch> gpsImageBatch_vec;
//    bool flag5= ReadHDMap::getAllGpsImageBatch(gpsImageBatch_vec);
//    GpsImageBatch gpsImageBatch;
//    bool flag6= ReadHDMap::getGpsImageBatchByImageId(scene_id, 2, gpsImageBatch);
//    cout << "gps heading"<<gpsImageBatch.gpsPoint.heading<<endl;

/************************************************************************************************************
 *    根据scene_id获取车道线检测的中间结果,中间结果是像素坐标(仅x,y有效),需要转换
 ************************************************************************************************************/
    /* DetectionDividerPerCapture detectionDividerPerCapture;
     bool flag7= ReadHDMap::getDetectionBatchBySceneId(scene_id, detectionDividerPerCapture);
 */
/************************************************************************************************************
  *    根据scene_id获取车道线检测的中间结果,中间结果是像素坐标(仅x,y有效),需要转换
  *    1帧scene_id 对应一个TrafficPerCapture,多个TrafficPerFrame,一个Frame对应多个TrafficLight ,一个Tflight对应多个light
  ************************************************************************************************************/
  /*  DetectionTrafficPerCapture detectionTrafficPerCapture;
    bool flag8 = ReadHDMap::getDetctionTrafficlights("20190130161123_c6a0dc163825d772bed42152c9e9b9f0_4", detectionTrafficPerCapture);
    TrafficLightEachShow &trafficLightEachShow = detectionTrafficPerCapture.trafficPerFrame_vec[0].trafficLight_vec[0];
    cout<<"traffic_light geomery:" <<trafficLightEachShow.point_vec.size() << endl;*/

    return 0;
}

