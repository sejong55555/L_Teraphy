#include "InterfaceManager.h"

InterfaceManager::InterfaceManager(QObject *parent) :
    QObject(parent)
{
    mPng =new CVtoPNG();
    mPngThread = new QThread;
    mPng->moveToThread(mPngThread);
    mPngThread->start();

    QObject::connect(mPng, &CVtoPNG::start, mPng, &CVtoPNG::doPngThread);
    QObject::connect(mPngThread, &QThread::finished, mPng, &QObject::deleteLater);
    QObject::connect(mPng, &CVtoPNG::resultReady, [&](const QString &result){
        //qDebug() << __PRETTY_FUNCTION__ << "##################### result " << result;
        if(mPngThread->isRunning() == true) {
            mPngThread->quit(); // 스레드중지
        }
    });
    emit mPng->start("");

    //mPng->WritePNGText(" have a good day ", "/home/sejong/Work/Lteraphy/L_Teraphy/image/test.png", 300,400);

}

InterfaceManager::~InterfaceManager()
{
    delete mPng;
    delete mPngThread;
}
