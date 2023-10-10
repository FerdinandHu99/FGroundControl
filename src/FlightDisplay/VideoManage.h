#ifndef VIDEOMANAGE_H
#define VIDEOMANAGE_H

#include <QObject>

class VideoManage : public QObject
{
    Q_OBJECT
public:
    explicit VideoManage(QObject *parent = nullptr);
    ~VideoManage();
    Q_INVOKABLE void startVideo ();

signals:

};

#endif // VIDEOMANAGE_H
