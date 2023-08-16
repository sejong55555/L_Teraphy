#ifndef VIEWER3_H
#define VIEWER3_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QFileInfo>

#include <QImage>
#include <opencv2/opencv.hpp>

using namespace cv;

class Viewer3: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Viewer3(QQuickItem *parent = nullptr);
    ~Viewer3();

    QImage getImage() const;
    void paint(QPainter *painter) override;

    Q_INVOKABLE void doWork(QString filePath);

signals:
    void imageChanged();

private:
    QImage m_image;

};
#endif // VIEWER3_H
