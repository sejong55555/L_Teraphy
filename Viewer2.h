#ifndef VIEWER2_H
#define VIEWER2_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QFileInfo>

#include <QImage>
#include <opencv2/opencv.hpp>

using namespace cv;

class Viewer2: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Viewer2(QQuickItem *parent = nullptr);
    ~Viewer2();

    QImage getImage() const;
    void paint(QPainter *painter) override;

    Q_INVOKABLE void openViewer();
    Q_INVOKABLE void doWork(QString filePath);

signals:
    void imageChanged();

private:
    QImage m_image;

};
#endif // VIEWER2_H
