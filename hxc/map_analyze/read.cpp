//
// Created by xijun1 on 2017/12/22.
//
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

//反射机制
//#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/dynamic_message.h>

#include "demo.pb.h"
#include<iostream>
#include <fstream>
#include<ios>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#include <fcntl.h>   // open
using namespace std;

void InfoStudents(const caffe::Student & stu){
    cout<< "student info:"<<endl;
    cout<<"     name: "<<stu.name()<<endl;
    cout<<"     age: "<<stu.age()<<endl;
    cout<<"     grade: "<<stu.grade()<<endl;
}

void InfoTeacher(const caffe::Teacher & teacher) {
    cout << "teacher info:" << endl;
    cout << "       name: " << teacher.name() << endl;
    cout << "       age: " << teacher.age() << endl;
    cout<< "            is worker: "<<teacher.work().isworker()<<endl;
    cout<< "            is jiaban: "<<teacher.work().isjiaban()<<endl;
}


int main(void)
{
    caffe::Class cls;
    int file_desc = open("map.prototxt",O_NDELAY);

    google::protobuf::io::FileInputStream fileInputStream(file_desc);
    if(!google::protobuf::TextFormat::Parse(&fileInputStream,&cls)){
        std::cout<<"parse failure."<<std::endl;
        return -1;
    }
    std::cout<<cls.name()<<std::endl;


    //按照索引进行读取
    for(int i=1;i<cls.GetMetadata().descriptor->field_count(); ++i){
        std::cout<<cls.descriptor()->field(i)->name()<<std::endl;
        //cout<<cls.descriptor()->field(i)->full_name()<<endl;
        if(cls.descriptor()->field(i)->name()=="stu"){
            for (auto &stu_info : cls.stu()){

                 InfoStudents(stu_info);
            }
        }

        if(cls.descriptor()->field(i)->name()=="teacher"){
            for (auto &teacher_info : cls.teacher()){

                InfoTeacher(teacher_info);
            }
        }
    }

    return 0;
}
