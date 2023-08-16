#include "InterfaceManager.h"

InterfaceManager* InterfaceManager::mInstance = NULL;

InterfaceManager::InterfaceManager(QObject *parent) :
    QObject(parent)
{
    mInstance = this;

    mPng =new CVtoPNG();
    mPngThread = new QThread;
    mPng->moveToThread(mPngThread);
    mPngThread->start();

    QObject::connect(mPng, &CVtoPNG::start, mPng, &CVtoPNG::doPngThread);
    QObject::connect(mPngThread, &QThread::finished, mPng, &QObject::deleteLater);
    QObject::connect(mPng, &CVtoPNG::resultReady, [&](const QString &result){
        if(mPngThread->isRunning() == true) {
            mPngThread->quit(); // 스레드중지
        }
    });

    QObject::connect(mPng,SIGNAL(writeCompleted()), this, SLOT(handleWriteCompleted()));//write done, information

    emit mPng->start("");
}

InterfaceManager::~InterfaceManager()
{
    delete mPng;
    delete mPngThread;
}

void InterfaceManager::handleWriteCompleted()
{    
    if(count>4) count =0;

    qDebug()<<__FUNCTION__<<count;
    emit sigWriteDone(count);
    count++;
}

InterfaceManager *InterfaceManager::getInstance()
{
    return mInstance;
}
