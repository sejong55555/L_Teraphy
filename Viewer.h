#ifndef VIEWER_H
#define VIEWER_H
//#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QFileInfo>

#include <QImage>
#include <opencv2/opencv.hpp>
#include "DetectSegmentation.h"
#include "BackGround.h"

using namespace cv;

class Viewer: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Viewer(QQuickItem *parent = nullptr);
    ~Viewer();

    QImage getImage() const;
    void paint(QPainter *painter) override;

    Q_INVOKABLE void openViewer();

signals:
    void imageChanged();

private:
    QImage m_image;

    void TestopenCV();
    void TestopenCV2();

};

#endif // VIEWER_H
