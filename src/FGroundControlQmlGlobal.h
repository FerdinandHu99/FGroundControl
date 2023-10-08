#ifndef FGROUNDCONTROLQMLGLOBAL_H
#define FGROUNDCONTROLQMLGLOBAL_H

#include <QObject>

class FGroundControlQmlGlobal : public QObject
{
    Q_OBJECT
public:
    explicit FGroundControlQmlGlobal(QObject *parent = nullptr);
    ~FGroundControlQmlGlobal();

    Q_PROPERTY(QString appName READ appName CONSTANT)
    QString appName () { return "FGroundControl";}

signals:

};

#endif // FGROUNDCONTROLQMLGLOBAL_H
