#ifndef PCL_VIEWER_H
#define PCL_VIEWER_H

#include <QMainWindow>

namespace Ui {
class pcl_viewer;
}

class pcl_viewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit pcl_viewer(QWidget *parent = nullptr);
    ~pcl_viewer();

private:
    Ui::pcl_viewer *ui;
};

#endif // PCL_VIEWER_H
