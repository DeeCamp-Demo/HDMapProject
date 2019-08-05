#include "pcl_viewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pcl_viewer w;
    w.show();

    return a.exec();
}
