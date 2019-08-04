// for sophus
//#include <sophus/se3.h>
//using Sophus::SE3;
//
// for eigen
//#include <Eigen/Core>
//#include <Eigen/Geometry>
//using namespace Eigen;
//
//#include <iostream>
//#include "Utils.h"
//#include <math.h>
//#include <iomanip>

#include "container.h"


cv::Mat K;
cv::Mat distCoeffs;
cv::Mat Rcb;
//cv::Mat mTcb = cv::Mat::eye(4, 4, CV_64F);
double header_former;
//cv::Mat pose = cv::Mat::eye(4, 4, CV_64F);


int main() {
    // 确定东北天坐标系原点和header的入口
    Utils::new3s_PointXYZ original;
    double header_start_former = 77.0464;
    original.set_x(22.68085991);
    original.set_y(114.36478212);
    original.set_z(0);

    // 这里的K和distCoeffs都是全局变量
    K = (cv::Mat_<float>(3, 3) << fx, 0.0, cx, 0.0, fy, cy, 0.0, 0.0, 1.0);
    distCoeffs = (cv::Mat_<float>(4, 1) << k1, k2, p1, p2);

    // 正常Tcb的值的初始化和计算只需进行一次，因此这里代码应该放在主函数里
    cv::Mat mTbw = cv::Mat::eye(4, 4, CV_64F);
    cv::Mat mRbw;
    Eigen::Vector3d ea0(yaw, pitch, roll);
    Eigen::Matrix3d Rcb;
    cv::Mat mRcb;
    Rcb = Eigen::AngleAxisd(ea0[0], Eigen::Vector3d::UnitZ()) * Eigen::AngleAxisd(ea0[1], Eigen::Vector3d::UnitY()) * Eigen::AngleAxisd(ea0[2], Eigen::Vector3d::UnitX());
    cv::eigen2cv(Rcb, mRcb);
    mRcb.copyTo(mTcb.rowRange(0, 3).colRange(0, 3));
    mTcb.row(2).col(3) = 1.32;

    /************ TEST on single image: get depth map by gps_index & ref_img_index *********/
    vector<ImageBatch> imageBatch_vec;
    bool flag = ReadHDMap::getAllImageBatch(imageBatch_vec);
    cout << "imageBatch_vec size: " << imageBatch_vec.size() << endl;

//    int gps_index = 23, ref_img_index = 3;
//    cv::Mat depth( image_height, image_width, CV_64F, init_depth );             // 初始化深度图
//    cv::Mat depth_cov( image_height, image_width, CV_64F, init_cov2 );          // 初始化深度方差图
//    Image3D image3D;
//    getDepthMapOfSingleImage(gps_index, ref_img_index, imageBatch_vec, original, depth, depth_cov, image3D);

    /************ TEST on single scene: get all depth maps by gps_index ********/
    vector<Image3D> images_gps;
    getDepthMapOfSingleScene(23, imageBatch_vec, original, images_gps); //23代表测试的gps_index
    cout << "images_gps : " << imageBatch_vec[23].scene_id << " size: " << images_gps.size() << endl;
    cout << "peek images_gps - image_id: " << images_gps[3].image_id << endl;
    cout << "peek images_gps - pose: " << images_gps[3].pose << endl;
    for (int i = 0; i < images_gps.size(); i++) {
        cout << "peek points size: " << images_gps[i].points.size() << endl;
    }

    return 0;
}


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
      /*  vector<ImageBatch> imageBatch_vec;
        bool flag3 = ReadHDMap::getAllImageBatch(imageBatch_vec);
    //    cout << "dfgfb:"<< dataFiles.size()<<" dfgfd:"<< dataFiles[100].images_vec.size()<< endl;

        if(flag3)
        {
            cout << "image batch ok" << endl;
        }*/

    /************************************************************************************************************
     *    // 根据指定scene_id查询此帧gps数据点,按顺序输出
     ************************************************************************************************************/
//        const string  gps_file_folder = "../data/gps";
//        vector<string> gps_vec;
//        bool flag = calulate::getAllFiles(gps_file_folder,gps_vec);
//    //  需要自行判断fileName是否存在 flag 0正确查询  -1 错误查询
//        calulate::sortedVector(gps_vec);
//        if (flag)
//        {
//            for (int i = 0; i < gps_vec.size(); ++i) {
//    //            cout << "gps files:" << gps_files[i]<<endl;
//            }
//        }
//        int num = gps_vec[10].find_last_of(".");
//        string id = gps_vec[10].substr(0, num-14);
//        ImageBatch imageBatch;
//        bool flag4 = ReadHDMap::getImageBatchBySceneId(id, imageBatch);
//        if (flag4)
//        {
//            for (int i = 0; i < imageBatch.images_vec.size(); ++i) {
//    //        cout << "image batch " << imageBatch.images_vec[i] << endl;
//            }
//        }
    /************************************************************************************************************
     *    获取每一个gps点+对应一张图片
     ************************************************************************************************************/
    //    vector<GpsImageBatch> gpsImageBatch_vec;
    //    bool flag5= ReadHDMap::getAllGpsImageBatch(gpsImageBatch_vec);
    //    GpsImageBatch gpsImageBatch;
    //    bool flag6= ReadHDMap::getGpsImageBatchByImageId(scene_id, 2, gpsImageBatch);
    //    cout << "gps heading"<<gpsImageBatch.gpsPoint.heading<<endl;