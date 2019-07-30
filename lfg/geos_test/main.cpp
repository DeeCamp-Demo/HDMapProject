#include "geos_c.h"
#include <iostream>
using  namespace std;
GeometryFactory factory;
Point* createGeosPoint(double x,double y)
{
    Coordinate pt(x,y);
    Point* p=factory.createPoint(pt);
    return p;
}
int main()
{
    cout << GEOS_VERSION;
//    Polygon *p1=createGeosPolygon(12,12,5); //创建第一个多边形
//
//    for(int i=0;i<=20;i++)
//    {
//        cout<<i<<":   ";
//        Polygon *p2=createGeosPolygon(0,0,i); //创建第二个多边形
//        IntersectionMatrix *im=p2->relate(p1);
//        cout<<*im<<"    ";    //返回DE-9IM交叉矩阵
//        if(p2->disjoint(p1))
//            cout<<"不相交"<<endl;
//        else
//        {
//            if(p2->touches(p1))
//                cout<<"接触"<<endl;
//            else if(p2->overlaps(p1))
//                cout<<"部分重叠"<<endl;
//            else if(p2->covers(p1))
//                cout<<"覆盖"<<endl;
//            else
//                cout<<*im<<endl;
//        }
//    }
//    system("pause");
    return 1;
}