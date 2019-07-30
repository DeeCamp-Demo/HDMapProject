export LD_LIBRARY_PATH=/usr/local/lib



在当前目录下执行编译指令可获得编译后的c++文件

```bash
protoc --cpp_out=.  demo.proto
```