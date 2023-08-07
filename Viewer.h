#ifndef VIEWER_H
#define VIEWER_H
//#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QFileInfo>

#include <QImage>
#include <QPixmap> // QPixmap 헤더 추가
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

class Viewer: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Viewer(QQuickItem *parent = nullptr);
    ~Viewer();

    QImage getImage() const;
    void paint(QPainter *painter) override;

signals:
    void imageChanged();

private:
    QImage m_image;
};

#endif // VIEWER_H
