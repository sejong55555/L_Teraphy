#ifndef VIEWER4_H
#define VIEWER4_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QFileInfo>

#include <QImage>
#include <opencv2/opencv.hpp>

using namespace cv;

class Viewer4: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Viewer4(QQuickItem *parent = nullptr);
    ~Viewer4();

    QImage getImage() const;
    void paint(QPainter *painter) override;

    Q_INVOKABLE void openViewer();
    Q_INVOKABLE void doWork(QString filePath);

signals:
    void imageChanged();

private:
    QImage m_image;

};
#endif // VIEWER4_H
