#ifndef VIEWER1_H
#define VIEWER1_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QFileInfo>

#include <QImage>
#include <opencv2/opencv.hpp>

using namespace cv;

class Viewer1: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Viewer1(QQuickItem *parent = nullptr);
    ~Viewer1();

    QImage getImage() const;
    void paint(QPainter *painter) override;

    Q_INVOKABLE void openViewer();
    Q_INVOKABLE void doWork(QString filePath);

signals:
    void imageChanged();

private:
    QImage m_image;

};
#endif // VIEWER1_H
