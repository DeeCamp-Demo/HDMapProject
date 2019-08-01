#include <iostream>
#include <vector>
#include <io.h>
#include "build_depth.h"
#include "consts.h"
#include "ReadHDMap.h"

int main (int argc, char** argv) {
    if (argc != 8) {
        cout << "Usage: build_depth_test curr_index path_to_test_dataset" << endl;
        return -1;
    }

    const int ref_gps_index = atoi(argv[1]);
    const int ref_img_index = atoi(argv[2]);
    const string gps_path(argv[3]);
    
    string ref_img;
    vector<string> currs_img_list;
    
    getImgs(gps_path, ref_img_index, ref_gps_index, ref_img, currs_img_list);
    
    Mat depth( height, width, CV_64F, init_depth );             // 深度图
    Mat depth_cov( height, width, CV_64F, init_cov2 );          // 深度方差图
    
    Mat ref;                                                    //　当前要进行深度估计的image
    SE3 pose_ref;                                               //　当前要进行深度估计的image的pose
    vector<Mat> currs;                                          //  前后相邻frames
    Vector<Pose> poses_curr;                                    //  前后相邻frames对应的pose    
    vector<Point> points;                                       //  目标区域的点集（带label）
    
    DepthMapping DM(ref, pose_ref, currs, poses_curr, points);
    bool ret = DM.build_depthMap(depth, depth_cov);
    if (ret == true) {
        cout << "successfully built depth map!" << endl;
    }

    // cout << "depth: " << depth << endl;
    Mat depth_out;
    normalize(depth, depth_out, 0, 255, cv::NORM_MINMAX);
    imwrite("depth.png", depth_out);
    cout<<"done."<< endl;

    return 0;
}
    
bool getImgs(const string& gps_path, const int& ref_img_index,
             const int& ref_gps_index, const string& ref_img,
             const vector<string>& currs_img_list){
    
    vector<string> files, ref_gps_img_list, next_gps_img_list, before_gps_img_list;
    string next_scene_id, before_scene_id;
    
    getFiles(gps_path, files );
    int total_gps = files.size();
    string scene_id = files[ref_gps_index];
    
    // API
    GPSInfoEach gpsInfoEach = getGPSInfoEachBySceneId(sence_id);
    curr_gps_img_list = gpsInfoEach.img_list;
    ref_img = curr_gps_img_list[ref_img_index]

    if (ref_img_index < (neighbor_frames/2)){
        if (ref_gps_index == 0){
            for (int i=0; i<= neighbor_frames; i++){
                currs_img_list.push_back(ref_gps_img_list[i]);
            }
        }
        else{
            // API
            GPSInfoEach B_gpsInfoEach = getGPSInfoEachBySceneId(files[ref_gps_index-1]);
            before_gps_img_list = B_gpsInfoEach.img_list;
            int before_img_num = (neighbor_frames/2) - ref_img_index;
            for(int i=before_gps_img_list.size()-1; i>before_gps_img_list.size()-before_img_num; i--){
                currs_img_list.push_back(before_gps_img_list[i]);
            }
            for(int i=0; i<neighbor_frames-before_img_num; i++){
                currs_img_list.push_back(curr_gps_img_list[i]);
            }
        }
    }
    else if (ref_img_index > (total_num_frames-neighbor_frames/2)){
        if (ref_gps_index == total_gps-1){
            for (int i=curr_gps_img_list.size()-1; i>curr_gps_img_list.size()-neighbor_frames; i--){
                currs_img_list.push_back(curr_gps_img_list[i]);
            }
        }
        else{
            // API
            GPSInfoEach N_gpsInfoEach = getGPSInfoEachBySceneId(files[ref_gps_index+1]);
            next_gps_img_list = N_gpsInfoEach.img_list;
            int next_img_num = next_gps_img_list.size() - ref_img_index;
            for(int i=0; i>next_img_num; i++){
                currs_img_list.push_back(next_gps_img_list[i]);
            }
            for(int i=next_gps_img_list.size()-1; i>next_gps_img_list.size()-next_img_num; i--){
                currs_img_list.push_back(curr_gps_img_list[i]);
            }
        }
    }
    else{
        for (int i=ref_img_index - neighbor_frames/2; i<ref_img_index+neighbor_frames/2; i++){
            currs_img_list.push_back(curr_gps_img_list[i]);
        }
    }
    return true;
}

