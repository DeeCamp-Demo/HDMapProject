#include "pcl_viewer.h"
#include "ui_pcl_viewer.h"

pcl_viewer::pcl_viewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pcl_viewer)
{
    ui->setupUi(this);
}

pcl_viewer::~pcl_viewer()
{
    delete ui;
}
