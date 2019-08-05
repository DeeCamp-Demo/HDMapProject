#ifndef PCL_HANDLE_H
#define PCL_HANDLE_H

#include <QObject>

class pcl_handle : public QObject
{
    Q_OBJECT
public:
    explicit pcl_handle(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PCL_HANDLE_H