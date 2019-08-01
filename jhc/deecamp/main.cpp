#include <iostream>
#include "Utils.h"
#include <math.h>
#include <iomanip>

cv::Mat K;
cv::Mat distCoeffs;
cv::Mat Rcb;
cv::Mat mTcb = cv::Mat::eye(4, 4, CV_64F);

int main() {
    // 坐标转换部分
    Utils::new3s_PointXYZ original;
    Utils::new3s_PointXYZ object1;

    original.set_x(22.68085797);
    original.set_y(114.36477538);
    original.set_z(0);
    // lon是经度 lat是纬度
    object1.set_x(22.68085991);
    object1.set_y(114.36478212);
    object1.set_z(1.32000000);

    Utils::new3s_PointXYZ enu_coord_1;
    Utils transform;
    transform.convertCJC02ToENU(object1, enu_coord_1, original);
    std::cout<<std::setprecision(11)<<enu_coord_1.get_x()<<" "<<enu_coord_1.get_y()<<" "<<enu_coord_1.get_z()<<std::endl;

    const std::string strCameraPath = "../Config/param.yml";
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

    cv::Mat mTbw = cv::Mat::eye(4, 4, CV_64F);
    cv::Mat mRbw;
    Utils poseCompute;
    // 这里读取到第一个帧的车的偏角
    double header_former;
    mRbw = poseCompute.convertAngleToR(header_former);
    mRbw.copyTo(mTbw.rowRange(0, 3).colRange(0, 3));
    // 这里假定我得到了第二个帧的车的偏角
    double header_now;
    // 这个是返回的NEU坐标系的点的差
    double add_t[3];
    // 对于初始的pose
    cv::Mat pose = mTbw;
    cv::Mat now_pose = poseCompute.updatePose(pose, header_former, header_now, add_t);
    cv::Mat camera_pose = mTcb * now_pose;
    return 0;
}