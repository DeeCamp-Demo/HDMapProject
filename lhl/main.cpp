#include <iostream>
#include "DBScan.h"
#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;

int main() {
    std::cout << "Hello, World!" << std::endl;

    default_random_engine e;
    uniform_real_distribution<double> u(0, 1); //随机数分布对象

    DBScan cluster(3, 2);

    for (int i = 0;i < 100;i++)
    {
        cluster.append_datapoint(3 + u(e), 4 + u(e), 5 + u(e));
    }

    for (int i = 0;i < 100;i++) {
        cluster.append_datapoint(30 + u(e), 40 + u(e), 50 + u(e));
    }

    for (int i = 0;i < 100;i++)
    {
        cluster.append_datapoint(-30 + u(e), -40 + u(e), -50 + u(e));
    }

    // 加入部分杂散点作测试
    cluster.append_datapoint(-10, -200, 3000);
    cluster.append_datapoint(-10, -200, -3000);
    cluster.append_datapoint(-1000, -200, 3000);

    // 开始聚类
    cluster.start_dbscan();

    for(int i = 0;i < cluster.dataset.size();i++)
    {
        DataPoint& dp = cluster.dataset[i];
        cout << "dp id = " << dp.get_dpId() << " x = " << dp.x << " y = " << dp.y << " z = " << dp.z << " label id =  " << dp.labelID << endl;
    }

    return 0;
}