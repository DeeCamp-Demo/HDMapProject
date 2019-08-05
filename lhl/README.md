# 类描述
    DBScan.h实现了两个类, DataPoint类和DBScan类.
## DataPoint
该类提供一个散点的描述，包括空间三维坐标和一些属性修饰，属性描述如下：
- x ： x轴坐标
- y ： y轴坐标
- z ： z轴坐标
- labelID : 表示该点的类别（从0开始），默认为-1，表示未分类
## DBScan
属性描述：
- dataset : 一个由DataPoint构成的vector，存放当前已有的数据点，调用start_dbscan方法后即可更新各数据点的labelID属性

方法描述：
- DBScan(float minDis, int minPts) : 构造函数，minDis表示聚类最小圆半径，minPts表示最小圆内点数
- ~DBScan(){} : 析构函数，为空
- void append_datapoint(float x, float y, float z) : 填充数据点，xyz分别表示三轴坐标
- bool start_dbscan(void) : 启动dbscan进行聚类，返回是否成功
- void clear_datapoint(void) : 清空数据集