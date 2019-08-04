#ifndef consts_h
#define consts_h

#include <string>
#include <vector>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

// ------------------------------------------------------------------
// Image properties
const int image_width = 1920;      // 宽度
const int image_height = 1080;      // 高度

// Camera calibration and distortion parameters (OpenCV)
const double fx = 1261.501206545319f;    // 相机内参
const double fy = 1147.048474835442f;
const double cx = 976.2383478986866f;
const double cy = 530.589333254679f;

const double k1 = -0.4039346734945025;
const double k2 = 0.1488016793983929;
const double p1 = 0.001059521151138014;
const double p2 = 0.0005015718248852138;

// camera frames per second
const float fps = 30.0;
// Color order of the images (0: BGR, 1: RGB. It is ignored if images are grayscale)
const int RGB = 1;

// Camera and body coordinate system transformation relationship (m)
double yaw = -0.08726646;
double pitch = 0.06981317;
double roll = 0.00;
double camera_height = 1.32;

// Parameters for building depth map
const int ncc_window_size = 2;    // NCC 取的窗口半宽度
const int ncc_area = (2*ncc_window_size+1)*(2*ncc_window_size+1); // NCC窗口面积
const double min_cov = 0.1;    // 收敛判定：最小方差
const double max_cov = 8;      // 发散判定：最大方差

// 需要调参（场景既定的先验信息）
const int neighbor_frames = 10;  // 用来作参考计算的相邻帧数
const double init_depth   = 8.0;    // 深度初始值
const double init_cov2    = 4.0;    // 方差初始值

//region point with label
typedef struct {
    int x;
    int y;
    int label;
} PointInt;

typedef struct {
    int x;
    int y;
    int label;
    double d;
} Point3D;

typedef struct {
    string image_id;
    Mat pose; //RT
    vector<Point3D> points;
} Image3D;


#endif /* consts_h */
