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

    static InterfaceManager *getInstance();
    static InterfaceManager *mInstance;

private:
    CVtoPNG *mPng;
    QThread *mPngThread;

    int count =1;

signals:
    void sigWriteDone(int index);

public slots:
    void handleWriteCompleted();
};

#endif // INTERFACEMANAGER_H
