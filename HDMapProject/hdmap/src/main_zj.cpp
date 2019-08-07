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

#include "vo.h"
#include "container.h"


//cv::Mat K;
//cv::Mat distCoeffs;
cv::Mat Rcb;
//cv::Mat mTcb = cv::Mat::eye(4, 4, CV_64F);
double header_former;
//cv::Mat pose = cv::Mat::eye(4, 4, CV_64F);


//int main() {
//    // 确定东北天坐标系原点和header的入口
//    Utils::new3s_PointXYZ original;
//    double header_start_former = 77.0464;
//    original.set_x(22.68085991);
//    original.set_y(114.36478212);
//    original.set_z(0);
//
//    // 这里的K和distCoeffs都是全局变量
//    K = (cv::Mat_<float>(3, 3) << fx, 0.0, cx, 0.0, fy, cy, 0.0, 0.0, 1.0);
//    distCoeffs = (cv::Mat_<float>(4, 1) << k1, k2, p1, p2);
//
//    // 正常Tcb的值的初始化和计算只需进行一次，因此这里代码应该放在主函数里
//    cv::Mat mTbw = cv::Mat::eye(4, 4, CV_64F);
//    cv::Mat mRbw;
//    Eigen::Vector3d ea0(yaw, pitch, roll);
//    Eigen::Matrix3d Rcb;
//    cv::Mat mRcb;
//    Rcb = Eigen::AngleAxisd(ea0[0], Eigen::Vector3d::UnitZ()) * Eigen::AngleAxisd(ea0[1], Eigen::Vector3d::UnitY()) * Eigen::AngleAxisd(ea0[2], Eigen::Vector3d::UnitX());
//    cv::eigen2cv(Rcb, mRcb);
//    mRcb.copyTo(mTcb.rowRange(0, 3).colRange(0, 3));
//    mTcb.row(2).col(3) = 1.32;
//
//    vector<ImageBatch> imageBatch_vec;
//    bool flag = ReadHDMap::getAllImageBatch(imageBatch_vec);
//    cout << "imageBatch_vec size: " << imageBatch_vec.size() << endl;
//
//    /************ TEST on single image: get depth map by gps_index & ref_img_index *********/
//    int gps_index = 23, ref_img_index = 3;
//    cv::Mat depth( image_height, image_width, CV_64F, init_depth );             // 初始化深度图
//    cv::Mat depth_cov( image_height, image_width, CV_64F, init_cov2 );          // 初始化深度方差图
//    Image3D image3D;
//    getDepthMapOfSingleImage(gps_index, ref_img_index, imageBatch_vec, original, depth, depth_cov, image3D);
//
//    /************ TEST on single scene: get all depth maps by gps_index ********/
//    vector<Image3D> images_gps;
//    getDepthMapOfSingleScene(23, imageBatch_vec, original, images_gps); //23代表测试的gps_index
//    cout << "images_gps : " << imageBatch_vec[23].scene_id << " size: " << images_gps.size() << endl;
//    cout << "peek images_gps - image_id: " << images_gps[3].image_id << endl;
//    cout << "peek images_gps - pose: " << images_gps[3].pose << endl;
//    for (int i = 0; i < images_gps.size(); i++) {
//        cout << "peek points size: " << images_gps[i].points.size() << endl;
//        if (images_gps[i].points.size() != 0) {
//            cout << "peek depth: " << images_gps[i].points[0].d << endl;
//        }
//    }
//
//    return 0;
//}

int main() {
    // 确定东北天坐标系原点和header的入口
    Utils::new3s_PointXYZ original;
    double header_start_former = 77.0464;
    original.set_x(22.68085991);
    original.set_y(114.36478212);
    original.set_z(0);


    // 正常Tcb的值的初始化和计算只需进行一次，因此这里代码应该放在主函数里
    cv::Mat mTbw = cv::Mat::eye(4, 4, CV_64F);
    cv::Mat mRbw;
    Eigen::Vector3d ea0(camera_yaw, camera_pitch, camera_roll);
    Eigen::Matrix3d Rcb;
    cv::Mat mRcb;
    Rcb = Eigen::AngleAxisd(ea0[0], Eigen::Vector3d::UnitZ()) * Eigen::AngleAxisd(ea0[1], Eigen::Vector3d::UnitY()) * Eigen::AngleAxisd(ea0[2], Eigen::Vector3d::UnitX());
    cv::eigen2cv(Rcb, mRcb);
    mRcb.copyTo(mTcb.rowRange(0, 3).colRange(0, 3));
    mTcb.row(2).col(3) = 1.32;

    /************ Test VO estimated relative pose between img1 and img2 **************/
//    string basedir = "/home/joey/work/zhangjing/deecamp/data/vo_test/";
//    string scene_id = "20190124164952_4b60fdd1db1a9fda118cfa078c552fa3_4";
//    string image_id = scene_id + "_332";
//    Mat img1 = imread ( basedir + scene_id + "_332.jpeg", CV_LOAD_IMAGE_COLOR );
//    Mat img2 = imread ( basedir + scene_id + "_333.jpeg", CV_LOAD_IMAGE_COLOR );
//
//    int image_index;
//    ReadHDMap::getIndexByImageId(image_id, image_index);
//    cout << "image_index: " << image_index << endl;
//
//    GPSInfoEach gpsInfoEach;
//    ReadHDMap::getGPSInfoBySceneId(scene_id, gpsInfoEach);
//
//    vector<cv::Mat> poses = getPosesBySceneId(scene_id, original);
//    cv::Mat pose1 = poses[image_index];
//    cv::Mat pose2 = poses[image_index + 1];
//
//    cv::Mat t_abs = (Mat_<double> (3,1) << pose2.at<double>(0, 3) - pose1.at<double>(0, 3),
//                                           pose2.at<double>(1, 3) - pose1.at<double>(1, 3),
//                                           pose2.at<double>(2, 3) - pose1.at<double>(2, 3));
//    //目前是直接相减算absolute translation
//    vector<Point3d> points;
//    Mat R, t;
//    calDepthByTriangulation(img1, img2, K, R, t, t_abs, points); //R是在内部的pose_estimation计算的
//
//    Mat rel_pose = (Mat_<double> (4,4) <<
//            R.at<double>(0,0), R.at<double>(0,1), R.at<double>(0,2), t.at<double>(0,0),
//            R.at<double>(1,0), R.at<double>(1,1), R.at<double>(1,2), t.at<double>(1,0),
//            R.at<double>(2,0), R.at<double>(2,1), R.at<double>(2,2), t.at<double>(2,0),
//            0.0, 0.0, 0.0, 1.0);
//
//    cout << "img1 pose: " << pose1 << endl;
//    cout << "img2 pose: " << pose2 << endl;
//    cout << "t_abs: " << t_abs << endl;
//    cout << "estimated rel_pose from gps between img1 and 2: " <<  pose2  * pose1.inv() << endl;
//
//    cout << "estimated rel_pose from VO: " << rel_pose << endl;
//    cout << "img2 pose predicted by VO: " << rel_pose * pose1 << endl;



    /************ For single image (specified by gps_index & ref_img_index): GET DEPTH MAP *********/
    int gps_index, ref_img_index;
    vector<ImageBatch> imageBatch_vec;
    bool flag = ReadHDMap::getAllImageBatch(imageBatch_vec);
    cout << "imageBatch_vec size: " << imageBatch_vec.size() << endl;
    for (int i = 0; i < imageBatch_vec.size(); i++) {
        if (imageBatch_vec[i].scene_id == "20190129104232_e58b8b3d6ac89c45c2a50d84ba822803_4") {
            gps_index = i;
            cout << "gps_index: " << i << endl;
            break;
        }
    }
    string image_id = "20190129104232_e58b8b3d6ac89c45c2a50d84ba822803_4_344";
    ReadHDMap::getIndexByImageId(image_id, ref_img_index);
    cout << "ref_img_index: " << ref_img_index << endl;

    cv::Mat depth( image_height, image_width, CV_64F, init_depth );             // 初始化深度图
    cv::Mat depth_cov( image_height, image_width, CV_64F, init_cov2 );          // 初始化深度方差图
    Image3D image3D;
    string mode = "full";
    getDepthMapOfSingleImage(gps_index, ref_img_index, imageBatch_vec, original, depth, depth_cov, image3D, mode);

    /************ For single scene (specified by gps_index): Calculate Divider Points Depth *********/
//    for (int i = 0; i < imageBatch_vec.size(); i++) {
//        if (imageBatch_vec[i].scene_id == "20190123112838_3faf30bde99e0f126cda2432ec90a621_4") {
//            cout << "gps index is : " << i << endl;
//        }
//    }
    //这里查出来的gps_index是1.

//    int gps_index = 2;
//    string scene_id = imageBatch_vec[gps_index].scene_id;
//    string txt_name = "/home/joey/work/zhangjing/deecamp/depth_results/divider/2/divider_all.txt";
//    ofstream out(txt_name);
//    for (int ref_img_index = 0; ref_img_index < imageBatch_vec[gps_index].images_vec.size(); ref_img_index++) {
//        string image_id = imageBatch_vec[gps_index].images_vec[ref_img_index];
//        cout << "image_id: " << image_id << endl;
//
//        // get pose of ref_img
//        vector<cv::Mat> poses = getPosesBySceneId(scene_id, original);
//        cv::Mat pose = poses[ref_img_index];
//        cv::Mat R, t;
//        R = (cv::Mat_<double>(3, 3) << pose.at<double>(0, 0), pose.at<double>(0, 1), pose.at<double>(0, 2),
//                pose.at<double>(1, 0), pose.at<double>(1, 1), pose.at<double>(1, 2),
//                pose.at<double>(2, 0), pose.at<double>(2, 1), pose.at<double>(2, 2));
//        t = (cv::Mat_<double>(3, 1) << pose.at<double>(0, 3), pose.at<double>(1, 3), pose.at<double>(2, 3));
//        //cout << "camera R: " << R << endl << "camera t: " << t << endl;
//        cv::Mat carPose = pose * mTcb.inv();
//        //cout << "car pose: " << carPose << endl;
//
//        // get divider points of ref_img, estimate depth and transform back to enu
//        DetchBatch detchBatch;
//        bool flag_detection = ReadHDMap::getAllDetectionBatchByIndex(scene_id, ref_img_index, detchBatch);
//        vector<DividerEach> divider_vec = detchBatch.dividerPerFrame.dividerEach_vec;
//
//        if (divider_vec.size() == 0) continue;
//
//        int counter = 0;
//        //cout << "divider_vec.size : " << divider_vec.size() << endl;
//        for (int i = 0; i < divider_vec.size(); i++) {
//            vector<PointT> points = divider_vec[i].points_vec;
//            for (int j = 0; j < points.size(); ++j) {
//                // calculate depth for divider point specially based on triangle
//                Point3D point3D;
//                calDepthForDivider(points[j], point3D);
//                cout << "divider point (pixel): " << "x: " << point3D.x << " y: " << point3D.y << " z(depth): "
//                     << point3D.d << endl;
//
//                // transform the pixel divider point into enu
//                Point3DEnu point3DEnu;
//                pixel3D2enu(point3D, R, t, point3DEnu);
//                cout << "divider point (enu): " << " x: " << point3DEnu.x << " y: " << point3DEnu.y << " z(height): "
//                     << point3DEnu.z << endl;
//
//                string line_to_write =
//                        double2Str(point3DEnu.x) + " " + double2Str(point3DEnu.y) + " " + double2Str(point3DEnu.z);
//                out << line_to_write << endl;
//                counter++;
//            }
//        }
//        cout << "--------" << endl;
//    }



    /************ For single scene(specified by gps_index): GET ALL DEPTH MAPS ********/
//    vector<Image3D> images_gps;
//    getDepthMapOfSingleScene(23, imageBatch_vec, original, images_gps); //23代表测试的gps_index
//    cout << "images_gps : " << imageBatch_vec[23].scene_id << " size: " << images_gps.size() << endl;
//    cout << "peek images_gps - image_id: " << images_gps[3].image_id << endl;
//    cout << "peek images_gps - pose: " << images_gps[3].pose << endl;

//    //    getDepthMapOfSingleScene(23, imageBatch_vec, original, images_gps); //23代表测试的gps_index
//    cout << "images_gps : " << imageBatch_vec[23].scene_id << " size: " << images_gps.size() << endl;
//    cout << "peek images_gps - image_id: " << images_gps[3].image_id << endl;
//    cout << "peek images_gps - pose: " << images_gps[3].pose << endl;

//    /***** transform recovered point with depth into enu coord and write into txt for smartFish *****/
//    for (Image3D& img_3d : images_gps) {
//        if (img_3d.points.size() == 0) continue;
//        string image_id = img_3d.image_id;
//        string txt_name = "/home/joey/work/zhangjing/deecamp/depth_results/23/" + image_id + ".txt";
//        ofstream out(txt_name);
//        Mat pose = img_3d.pose;
//        cv:: Mat R, t;
//        R = (cv::Mat_<double>(3, 3) << pose.at<double>(0, 0), pose.at<double>(0, 1), pose.at<double>(0, 2),
//                                       pose.at<double>(1, 0), pose.at<double>(1,1), pose.at<double>(1, 2),
//                                       pose.at<double>(2, 0), pose.at<double>(2,1), pose.at<double>(2, 2));
//        t = (cv::Mat_<double>(3, 1) << pose.at<double>(0, 3), pose.at<double>(1, 3), pose.at<double>(2, 3));
//
//        cout << "R: " << R << endl << "t: " << t << endl;
//
//        for (Point3D& point_with_depth : img_3d.points) {
//            Point3DEnu point3DEnu;
//            pixel2enu(point_with_depth, R, t, point3DEnu);
//
//            string line_to_write = double2Str(point3DEnu.x) + " " + double2Str(point3DEnu.y) + " " + double2Str(point3DEnu.z);
//            out << line_to_write << endl;
//
//            cout << "enu coord: " << line_to_write << endl;
//            cout << "--------" << endl;
//       }
//       cout << "finished writing " << img_3d.points.size() << " points into " << txt_name << endl;
//    }

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