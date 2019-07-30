//
// Created by lfg on 19-7-30.
//
#include "prototest.h"


int main(){
    test::ConstraintSetConfig constraint_set_config_;
    std::string file_name = "../config/test.prototxt";
    std::string new_file_name = "../config/new.prototxt";

    bool read_state = protoio::ReadProtoFromTextFile(file_name, &constraint_set_config_);

    bool using_hsv_ = constraint_set_config_.using_hsv();
    constraint_set_config_.set_using_hsv(false);
    protoio::WriteProtoToTextFile(constraint_set_config_, new_file_name);
    float ok = constraint_set_config_.num();
    std::cout<< using_hsv_<<std::endl;
    std::cout<< ok<<std::endl;

}
