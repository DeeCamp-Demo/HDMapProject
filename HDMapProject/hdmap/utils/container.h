//
// Created by joey on 19-8-4.
//

#ifndef DEECAMP_CONTAINER_H
#define DEECAMP_CONTAINER_H

#include <sophus/se3.h>
using Sophus::SE3;

// for eigen
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace Eigen;

#include <iostream>
#include "Utils.h"
#include <math.h>
#include <iomanip>
#include <consts.h>
#include <read_hdmap.h>
#include "read_hdmap.h"
#include "build_depth.h"
#include "read_detection.h"
#include "consts.h"

cv::Mat mTcb = cv::Mat::eye(4, 4, CV_64F);
cv::Mat pose = cv::Mat::eye(4, 4, CV_64F);


// get poses by scene_id corresponding to gps
vector<cv::Mat> getPosesBySceneId(string& scene_id, Utils::new3s_PointXYZ& original) {
    Utils transform;
    Utils::new3s_PointXYZ enu_coord_1;
    Utils poseCompute;
    vector<cv::Mat> camera_poses;

    //根据scene_id显示此帧gps数据点
    Utils::new3s_PointXYZ  scene_point_start;
    GPSInfoEach gpsInfoEach = ReadHDMap::getGPSInfoBySceneId(scene_id);
    vector<GPSPointEach> points = gpsInfoEach.gpsPoints;

    for (int k = 0; k < points.size(); ++k) {
        double header_angle = points[k].heading;

        // 这个是返回的NEU坐标系的点的差
        scene_point_start.set_x(points[k].points.x);
        scene_point_start.set_y(points[k].points.y);
        scene_point_start.set_z(points[k].points.z);
        transform.convertCJC02ToENU(scene_point_start, enu_coord_1, original);
        //std::cout<<"enu_coord1: "<<enu_coord_1.get_x()<<" "<<enu_coord_1.get_y()<<" "<<enu_coord_1.get_z()<<std::endl;

        //std::cout<<"delta_angle: "<<header_angle<<std::endl;
        cv::Mat tempRstart = poseCompute.convertAngleToR(header_angle);
        tempRstart.copyTo(pose.rowRange(0, 3).colRange(0, 3));
        pose.row(0).col(3) = enu_coord_1.get_x();
        pose.row(1).col(3) = enu_coord_1.get_y();
        pose.row(2).col(3) = 0.0;
        //std::cout<<"pose: "<<pose<<std::endl;
        cv::Mat camera_pose = mTcb * pose;
        //std::cout << "camera_pose: "<< camera_pose << std::endl;
        camera_poses.push_back(camera_pose);
    }
    return camera_poses;
}


//convert RT of cv::Mat into R of Eigen::Matrix3d and t of Eigen::Vector3d
void cvMat2RT (cv::Mat& mat, Eigen::Matrix3d& R, Eigen::Vector3d& t) {
    R.row(0)(0) = mat.at<double>(0, 0);
    R.row(0)(1) = mat.at<double>(0, 1);
    R.row(0)(2) = mat.at<double>(0, 2);
    t.row(0)(0) = mat.at<double>(0, 3);

    R.row(1)(0) = mat.at<double>(1, 0);
    R.row(1)(1) = mat.at<double>(1, 1);
    R.row(1)(2) = mat.at<double>(1, 2);
    t.row(1)(0) = mat.at<double>(1, 3);

    R.row(2)(0) = mat.at<double>(2, 0);
    R.row(2)(1) = mat.at<double>(2, 1);
    R.row(2)(2) = mat.at<double>(2, 2);
    t.row(2)(0) = mat.at<double>(2, 3);
}


// get image paths and corresponding poses (ref & currs) by gps_index and ref_img_index
void getImagePathsAndPoses(int gps_index, int ref_img_index, vector<ImageBatch>& imageBatch_vec, Utils::new3s_PointXYZ& original,
                           string& ref_img_path, vector<string>& curr_img_paths, cv::Mat& ref_pose, vector<cv::Mat>& curr_poses) {

    // 当前gps对应的image paths信息
    ImageBatch img_batch_curr = imageBatch_vec[gps_index];
    vector<string> img_list_curr = img_batch_curr.images_vec;
    int num_images_curr = img_list_curr.size();
    string scene_id_curr = img_batch_curr.scene_id;
    vector<cv::Mat> camera_poses_curr = getPosesBySceneId(scene_id_curr, original);

    /**************get ref image path and corresponding pose************/
    ref_img_path = img_list_curr[ref_img_index];
    ref_pose = camera_poses_curr[ref_img_index];

    /********************get neighbor image paths and corresponding poses************/
    //需要用到上一个scene
    if (ref_img_index < neighbor_frames / 2) {
        //当前gps是第一个
        if (gps_index == 0) {
            for (int i = 0; i < neighbor_frames + 1; i++){
                if (i == ref_img_index) continue; //避开ref_img_path
                curr_img_paths.push_back(imageBatch_vec[gps_index].images_vec[i]);
                curr_poses.push_back(camera_poses_curr[i]);
            }
        }
            //当前gps不是第一个
        else {
            ImageBatch img_batch_prev = imageBatch_vec[gps_index - 1]; //上一个scene的image paths
            vector<string> img_list_prev = img_batch_prev.images_vec;
            int num_images_prev = (int)img_list_prev.size();
            string scene_id_prev = img_batch_prev.scene_id;
            vector<cv::Mat> camera_poses_prev = getPosesBySceneId(scene_id_prev, original);

            int end = ref_img_index + neighbor_frames / 2;            // end in curr_list
            int start = num_images_prev - (neighbor_frames - end);    // start in before_list
            for (int i = start; i < img_list_prev.size(); i++) {      //extract frames from before_list
                curr_img_paths.push_back(img_list_prev[i]);
                curr_poses.push_back(camera_poses_prev[i]);
            }
            for (int i = 0; i < end; i++) {                           //extract remained frames from curr_list
                if (i == ref_img_index) continue;
                curr_img_paths.push_back(img_list_curr[i]);
                curr_poses.push_back(camera_poses_curr[i]);
            }
        }
    }
        //需要用到下一个scene
    else if (ref_img_index > num_images_curr - neighbor_frames / 2) {
        //当前gps是最后一个
        if (gps_index == imageBatch_vec.size() - 1) {
            for (int i = num_images_curr - neighbor_frames - 1; i < num_images_curr; i++) {
                if (i == ref_img_index) continue;                           //避开ref_path
                curr_img_paths.push_back(img_list_curr[i]);
                curr_poses.push_back(camera_poses_curr[i]);
            }
        }
            //当前gps不是最后一个
        else {
            ImageBatch img_batch_next = imageBatch_vec[gps_index + 1];
            vector<string> img_list_next = img_batch_next.images_vec;
            int num_images_next = (int)img_list_next.size();
            string scene_id_next = img_batch_next.scene_id;
            vector<cv::Mat> camera_poses_next = getPosesBySceneId(scene_id_next, original);

            int start = ref_img_index - neighbor_frames / 2;
            int end = neighbor_frames - (num_images_curr - start);
            for (int i = start; i < num_images_curr; i++) {            // extract frames from curr
                if (i == ref_img_index) continue;
                curr_img_paths.push_back(img_list_curr[i]);
                curr_poses.push_back(camera_poses_curr[i]);
            }
            for (int i = 0; i < end; i++) {                            // extract frames from next
                curr_img_paths.push_back(img_list_next[i]);
                curr_poses.push_back(camera_poses_next[i]);
            }
        }
    }
        //只在当前scene抽取neighbor frames
    else {
        for (int i = ref_img_index - neighbor_frames / 2; i <= ref_img_index + neighbor_frames / 2; i++) {
            if (i == ref_img_index) continue;                              //避开ref_path
            curr_img_paths.push_back(img_list_curr[i]);
            curr_poses.push_back(camera_poses_curr[i]);
        }
    }
}

void getDepthMapOfSingleImage(int gps_index, int ref_img_index, vector<ImageBatch>& imageBatch_vec, Utils::new3s_PointXYZ& original,
                              cv::Mat& depth, cv::Mat& depth_cov, Image3D& image3D){

    //inputs for building depth map
    string ref_img_path;
    cv::Mat ref_pose;
    vector<string> curr_img_paths;
    vector<cv::Mat> curr_poses;
    vector<PointInt> points_target;

    getImagePathsAndPoses(gps_index, ref_img_index, imageBatch_vec, original, ref_img_path, curr_img_paths, ref_pose, curr_poses);
    bool flag_detection = readDetectionFiles(ref_img_path, points_target);
    if (flag_detection) {
        cout << "Successfully detected traffic light or road lane!" << endl;
    }

    std::cout << "ref_img_path: " << ref_img_path << endl;
    std::cout << "ref_pose: " << ref_pose << endl;
    std::cout << "curr_img_paths size: " << curr_img_paths.size() << endl;
    std::cout << "curr_poses size: " << curr_poses.size() << endl;

    //for (int i = 0; i < curr_img_paths.size(); i++) {
    //    std::cout << "curr_img_path: " << curr_img_paths[i] << endl;
    //    std::cout << "curr_pose: " << curr_poses[i] << endl;
    //}


    /*********** get "ref & currs" from "ref_img_path & curr_img_paths" ************/
    string ref_img_name = "../data/images/" + ref_img_path + ".jpeg";
    cv::Mat ref = imread(ref_img_name, 0);
    vector<cv::Mat> currs;                                                              // 前后相邻frames
    for (string curr_img_path : curr_img_paths) {
        string curr_img_name = "../data/images/" + curr_img_path + ".jpeg";
        cv::Mat curr = imread(curr_img_name, 0);
        currs.push_back(curr);
    }

    /******* convert "ref_pose & curr_poses" into SE3 format: "ref_pose_SE3 & curr_poses_SE3" ********/
    Eigen::Matrix3d R;
    Eigen::Vector3d t;
    cvMat2RT(ref_pose, R, t); //convert
    Quaterniond q(R);
    SE3 ref_pose_SE3(q, t);

    vector<SE3> curr_poses_SE3;
    for (cv::Mat curr_pose : curr_poses) {
        Eigen::Matrix3d R;
        Eigen::Vector3d t;
        cvMat2RT(curr_pose, R, t);
        Quaterniond q(R);
        SE3 curr_pose_SE3(q, t);
        curr_poses_SE3.push_back(curr_pose_SE3);
    }

    /********* actually build depth map from initialized depth map -> output depth into vector and visualize it********/
    DepthMapping DM(ref, ref_pose_SE3, currs, curr_poses_SE3, points_target);
    bool ret = DM.build_depthMap(depth, depth_cov);

    if (ret == true) {
        cout << "successfully built depth map!" << endl;
    }

    image3D.image_id = ref_img_path;
    image3D.pose = ref_pose;
    vector<Point3D> points_with_depth;

    // print depth
    cout << "printing depth: " << endl;
    for (PointInt p : points_target) {
        double curr_depth = depth.at<double> (image_height - p.y, p.x);
        if (curr_depth != init_depth) {
            cout << curr_depth << " " << endl;

            //包装信息
            Point3D pwd;
            pwd.x = p.x;
            pwd.y = p.y;
            pwd.label = p.label;
            pwd.d = curr_depth;
            points_with_depth.push_back(pwd);
        }
    }
    image3D.points = points_with_depth;

    // save depth as image
    Mat depth_out;
    normalize(depth, depth_out, 0, 255, cv::NORM_MINMAX);
    imwrite("/home/joey/work/zhangjing/deecamp/depth_results/depth_test.png", depth_out);
    cout << "finished writing into opencv image" << endl;
}

//get depth maps(all detected points with estimated depth and label + image_id & pose) of one scene
void getDepthMapOfSingleScene(int gps_index, vector<ImageBatch>& imageBatch_vec, Utils::new3s_PointXYZ& original,
                              vector<Image3D>& images_gps){

    ImageBatch img_batch = imageBatch_vec[gps_index];
    cout << "Number of image batch of current gps: " << img_batch.images_vec.size() << endl;
    int counter = 0;
    for (int i = 0; i < img_batch.images_vec.size(); i++) {
        counter++;
        cv::Mat depth( image_height, image_width, CV_64F, init_depth );             // 初始化深度图
        cv::Mat depth_cov( image_height, image_width, CV_64F, init_cov2 );          // 初始化深度方差图
        Image3D image3D;
        getDepthMapOfSingleImage(gps_index, i, imageBatch_vec, original, depth, depth_cov, image3D);
        images_gps.push_back(image3D);
        cout << "-------------------------------------------" << endl;
        if (counter == 4) break;
    }
}

#endif //DEECAMP_CONTAINER_H
