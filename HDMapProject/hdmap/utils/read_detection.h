#include<iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

typedef struct{
    int x;
    int y;
    int label;
}PointInt;

bool is_file_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool readDetectionFiles(const string& image_id,vector<PointInt>& img_coors)
{
    // file_name: 检测得到txt 文件的文件名
    // img_coors 检测到的像素对应的像素坐标和label
    const string file_path = "../data/detection_result_1/";
    string lane_file_name = file_path + "lane/" + image_id + "@laneline.txt";
    string light_file_name = file_path + "traffic_light_bbox/" +image_id + "@traffic_light.txt";
    string line;

    // 读取车道线
    ifstream lane_fin( lane_file_name);
    if ( !lane_fin ) return false;
    if ( is_file_empty(lane_fin)) return false; //判断文件是否为空

    while (std::getline(lane_fin, line))
    {
        std::istringstream iss(line);
        // 数据格式：x, y, label
        int x, y, label;
        if (!(iss >> x >> y >> label)) break;

        PointInt coor_label;
        coor_label.x = x;
        coor_label.y = y;
        coor_label.label = label;

        img_coors.push_back(coor_label);

        if ( !lane_fin.good() ) break;
    }

    // 读取红绿灯
    ifstream light_fin( light_file_name);
    if ( !light_fin ) return false;
    if ( is_file_empty(light_fin) ) return false; //判断文件是否为空
    
    while (std::getline(light_fin, line))
    {
        std::istringstream iss(line);
        // 数据格式：x, y, label
        int xmin, ymin, xmax, ymax, label;
        double score;
        if (!(iss >> xmin >> ymin >> xmax >> ymax >> label >> score)) break;

        for(int i=xmin; i<=xmax; i++){
            for (int j=ymin; j<=ymax; j++){
                PointInt coor_label;
                coor_label.x = i;
                coor_label.y = j;
                coor_label.label = label;
                img_coors.push_back(coor_label);
            }
        }

        if ( !light_fin.good() ) break;
    }
    return true;
}

