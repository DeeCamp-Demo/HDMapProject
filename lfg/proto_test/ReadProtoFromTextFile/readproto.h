//
// Created by lfg on 19-7-30.
//

#ifndef HDMAPPROJECT_READPROTO_H
#define HDMAPPROJECT_READPROTO_H
#include "google/protobuf/message.h"

namespace readproto {
    using ::google::protobuf::Message;
// 从txt读取proto的定义
    bool ReadProtoFromTextFile(const char* filename, Message* proto);

}


#endif //HDMAPPROJECT_READPROTO_H
