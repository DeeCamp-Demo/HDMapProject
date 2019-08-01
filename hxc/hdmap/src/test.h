//
// Created by catalina on 2019/8/1.
//
#include "utils/read_hdmap.h"
#include <iostream>
#include <cstring>        // for strcat()
#include "fstream"
//#include "string.h"
//#include <dirent.h>
//#include <stdio.h>

#ifndef HDMAP_TEST_H
#define HDMAP_TEST_H





/*struct _finddata_t
{
    unsigned attrib;//文件属性的存储位置
    time_t time_create;
    time_t time_access; //文件最后一次被访问的时间。
    time_t time_write;//文件最后一次被修改的时间。
    unsigned  size;
//    char name[_MAX_FNAME];
    string file_name;
};*/

/*struct Dirent
{
   long d_ino; // inode number 索引节点号
   off_t d_off; // offset to this dirent 在目录文件中的偏移
   unsigned short d_reclen; // length of this d_name 文件名长
   unsigned char d_type; // the type of d_name 文件类型
   char d_name [NAME_MAX+1]; // file name (null-terminated) 文件名，最长255字符
};*/
//其中d_type表明该文件的类型：文件(8)、目录(4)、链接文件(10)等
class test {
public:
//    vector<string> sortFilesByNum(vector<string> fileNames, int type);
};



#endif //HDMAP_TEST_H
