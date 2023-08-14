#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

#include <QObject>
#include <QThread>
#include "cvtopng.h"

class InterfaceManager: public QObject
{
    Q_OBJECT
public:
    InterfaceManager(QObject *parent = 0);
    ~InterfaceManager();

private:
    CVtoPNG *mPng;
    QThread *mPngThread;
};

#endif // INTERFACEMANAGER_H
