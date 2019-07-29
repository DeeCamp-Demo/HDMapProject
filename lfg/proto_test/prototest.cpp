//
// Created by lfg on 19-7-30.
//
#include "prototest.h"

int main(){
    ConstraintSetConfig constraint_set_config_;
    std::string file_name = "./config/test.prototxt";
    bool read_state = readproto::ReadProtoFromTextFile(file_name, &constraint_set_config_);

    bool using_hsv_ = constraint_set_config_.using_hsv();
    printf(using_hsv_)

}
