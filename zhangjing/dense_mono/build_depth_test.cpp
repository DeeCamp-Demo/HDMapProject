#include <iostream>
#include <vector>
#include "build_depth.h"
#include "consts.h"

int main (int argc, char** argv) {
    if (argc != 8) {
        cout << "Usage: build_depth_test curr_index path_to_test_dataset" << endl;
        return -1;
    }

    const int curr_index = atoi(argv[1]);
    const int neighbor_frames = atoi(argv[2]);
    const string path(argv[3]);
    const int a = atoi(argv[4]), b = atoi(argv[5]);
    const int w = atoi(argv[6]), h = atoi(argv[7]);
    
    Mat depth( height, width, CV_64F, init_depth );             // 深度图
    Mat depth_cov( height, width, CV_64F, init_cov2 );          // 深度方差图
    
    Mat ref;                                                    //　当前要进行深度估计的image
    SE3 pose_ref;                                               //　当前要进行深度估计的image的pose
    vector<Mat> currs;                                          //  前后相邻frames
    vector<Pose_id> poses_curr;                              //  前后相邻frames对应的pose    
    vector<Point_label> points;                                      //  目标区域的点集（带label）
    
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
