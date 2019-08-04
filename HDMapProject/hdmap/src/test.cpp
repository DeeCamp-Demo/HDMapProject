//
// Created by catalina on 2019/8/1.
//
#include "test.h"
#include "utils/Utils.h"
#include "utils/pixel2enu.h"
using namespace std;

cv::Mat K;
cv::Mat distCoeffs;
cv::Mat Rcb;
cv::Mat mTcb = cv::Mat::eye(4, 4, CV_64F);
double header_former;
cv::Mat pose = cv::Mat::eye(4, 4, CV_64F);
//string scene_id = "20190123112838_3faf30bde99e0f126cda2432ec90a621_4";

int main(){
    // ------------------ test cam2enu --------------
    cout << "Welcome to Summoner's Rift" << endl;
    PointInt p;
    p.x = 1, p.y = 2, p.label = 3;

    PointDouble cam;

    cv::Mat K;
    double fx = 481.2, fy = -480.0, cx = 319.5, cy = 239.5;
    K = (cv::Mat_<double>(3, 3) <<
            fx, 0.0, cx,
            0.0, fy, cy,
            0.0, 0.0, 1.0);
    pixel2cam(p, cam, K);

    cout << "First blood." << endl;
    cout << "x: " << cam.x << "y: " << cam.y << "label: " << cam.label << endl;

    // cam2enu
    PointDepth coors_cam, coors_enu;
    coors_cam.x = cam.x;
    coors_cam.y = cam.y;
    coors_cam.z = 1.3;
    coors_cam.label = cam.label;
    cv:: Mat R, t;
    R = (cv::Mat_<double>(3, 3) <<
            1.0, 2.0, 3.0,
            4.0, 3.0, 1.0,
            2.0, 5.0, 1.2);
    t = (cv::Mat_<double>(3, 1) << 1.0, 2.0, 3.0);
    cam2enu(coors_cam, coors_enu, R, t);
    cout << "Double kill." << endl;
    cout << "x: " << coors_enu.x << "y: " << coors_enu.y << "depth: " << coors_enu.z << "label: " << coors_enu.label << endl;

    cout << "Victory" << endl;

    // ------------------ test cam2enu --------------

////----------------------------------------------------------------------------------------------------------------------
//    // 确定东北天坐标系原点和header的入口
//    Utils::new3s_PointXYZ original;
////    vector<GPSInfoEach> gpsInfo_vec;
////    bool flag = ReadHDMap::getGPSInfo(gpsInfo_vec);
////    if (flag)
////    {
////        GPSPointEach gpsPointEach = gpsInfo_vec[0].gpsPoints[0];
////        gpsPointEach.heading;
////        original.set_x(gpsPointEach.points.x);
////        original.set_y(gpsPointEach.points.y);
////        original.set_z(0);
////        header_former = gpsPointEach.heading;
////    }
//
//    double header_start_former = 77.0464;
//    original.set_x(22.68085991);
//    original.set_y(114.36478212);
//    original.set_z(0);
//
//
//    Utils::new3s_PointXYZ enu_coord_1, enu_coord_2;
//    Utils transform;
//
//    // 相机参数加载和相关参数初始化
//    const std::string strCameraPath = "../config/param.yml";
//    cv::FileStorage fSettings(strCameraPath, cv::FileStorage::READ);
//    float fx = fSettings["Camera.fx"];
//    float fy = fSettings["Camera.fy"];
//    float cx = fSettings["Camera.cx"];
//    float cy = fSettings["Camera.cy"];
//
//    float k1 = fSettings["Camera.k1"];
//    float k2 = fSettings["Camera.k2"];
//    float p1 = fSettings["Camera.p1"];
//    float p2 = fSettings["Camera.p2"];
//
//    float yaw = fSettings["Cam.yaw"];
//    float pitch = fSettings["Cam.pitch"];
//    float roll = fSettings["Cam.roll"];
//
//    // 这里的K和distCoeffs都是全局变量
//    K = (cv::Mat_<float>(3, 3) <<
//                               fx, 0.0, cx,
//            0.0, fy, cy,
//            0.0, 0.0, 1.0);
//    distCoeffs = (cv::Mat_<float>(4, 1) << k1, k2, p1, p2);
//
//    // 正常Tcb的值的初始化和计算只需进行一次，因此这里代码应该放在主函数里
//
//    cv::Mat mTbw = cv::Mat::eye(4, 4, CV_64F);
//    cv::Mat mRbw;
//    Utils poseCompute;
//
//    Eigen::Vector3d ea0(yaw,pitch,roll);
//    Eigen::Matrix3d Rcb;
//    cv::Mat mRcb;
//    Rcb = Eigen::AngleAxisd(ea0[0], Eigen::Vector3d::UnitZ())*Eigen::AngleAxisd(ea0[1], Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(ea0[2], Eigen::Vector3d::UnitX());
//    cv::eigen2cv(Rcb, mRcb);
//
//    mRcb.copyTo(mTcb.rowRange(0, 3).colRange(0, 3));
//    mTcb.row(2).col(3) = 1.32;
//
//    //////////////////////////////////////////////////////////
//
//    string scene_id = "20190123112838_3faf30bde99e0f126cda2432ec90a621_4";
//
//    //    根据scene_id显示此帧gps数据点
//    Utils::new3s_PointXYZ  scene_point_start;
//    GPSInfoEach gpsInfoEach = ReadHDMap::getGPSInfoBySceneId(scene_id);
//    vector<GPSPointEach> points = gpsInfoEach.gpsPoints;
//    vector<ImageBatch> imgs;
//    //bool flag = ReadHDMap::getImageBatchBySceneId(scene_id, imgs);
//    for (int k = 0; k < points.size(); ++k) {
//        double header_angle = points[k].heading;
//
//        // 这个是返回的NEU坐标系的点的差
//        scene_point_start.set_x(points[k].points.x);
//        scene_point_start.set_y(points[k].points.y);
//        scene_point_start.set_z(points[k].points.z);
//        transform.convertCJC02ToENU(scene_point_start, enu_coord_1, original);
//        std::cout<<"enu_coord1: "<<enu_coord_1.get_x()<<" "<<enu_coord_1.get_y()<<" "<<enu_coord_1.get_z()<<std::endl;
//
//        std::cout<<"delta_angle: "<<header_angle<<std::endl;
//        cv::Mat tempRstart = poseCompute.convertAngleToR(header_angle);
//        tempRstart.copyTo(pose.rowRange(0, 3).colRange(0, 3));
//        pose.row(0).col(3) = enu_coord_1.get_x();
//        pose.row(1).col(3) = enu_coord_1.get_y();
//        pose.row(2).col(3) = 0;
//        std::cout<<"pose: "<<pose<<std::endl;
//        cv::Mat camera_pose = mTcb * pose;
//        //std::cout<<"camera_pose: "<<camera_pose<<std::endl;
//    }
////--------------------------------------------------------------------------------------------------------------------

    return 0;
}

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



