1.首先在https://trac.osgeo.org/geos下载geos-3.6.2.tar.bz2 并解压

```
cd geos-3.6.2
./configue  //或选择安装的目录./configure --prefix=/root/env/geos
make 
make install 
```

2.使用

```bash
sudo gedit /etc/ls.so.conf
#在文件里面添加加
/root/env/geos/lib
/sbin/ldconfig
```

在程序编译时在makefile或g++加入(用clion此步省略)

```
LIBS = geos
LIBS_SEARCH_PATH = /root/env/geos
INCLUDES = /root/env/geos/include
```

3.HelloWorld测试

```c++
#include <iostream>
#include "geos.h"
using namespace std;
int main()
{
   cout<<"GEOS库版本为："<<GEOS_VERSION<<endl;
}
```

