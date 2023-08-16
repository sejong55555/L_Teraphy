#ifndef CVTOPNG_H
#define CVTOPNG_H
#include <QObject>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QThread>

using namespace cv;

class CVtoPNG: public QObject
{
    Q_OBJECT
public:
    explicit CVtoPNG(QObject *parent = nullptr);
    int WritePNGText(QString str, QString path, unsigned int width, unsigned int height);

public slots:
    void doPngThread(const QString &msg);

signals:
    void start(const QString &);
    void resultReady(const QString &result);
    void writeCompleted();
};

#endif // CVTOPNG_H
