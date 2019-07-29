//
// Created by lfg on 19-7-30.
//

#include "readproto.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

#include <stdint.h>

#include <algorithm>
#include <fstream>  // NOLINT(readability/streams)
#include <string>
#include <vector>

namespace readproto {

    using google::protobuf::io::FileInputStream;
    using google::protobuf::io::FileOutputStream;
    using google::protobuf::io::ZeroCopyInputStream;
    using google::protobuf::io::CodedInputStream;
    using google::protobuf::io::ZeroCopyOutputStream;
    using google::protobuf::io::CodedOutputStream;
    using google::protobuf::Message;

// 从文件读取Proto的txt文件
    bool ReadProtoFromTextFile(const char* filename, Message* proto) {
        int fd = open(filename, O_RDONLY);
        CHECK_NE(fd, -1) << "File not found: " << filename;
        FileInputStream* input = new FileInputStream(fd);//新建一个FileInputStream对象 input
        // 注意如何使用protobuf去读取,解析input文件中的Message， 即使文件中参数定义顺序与Message中的参数定义顺序不一致，也可以解析。
        bool success = google::protobuf::TextFormat::Parse(input, proto);
        delete input;
        close(fd);
        return success;
    }


}

