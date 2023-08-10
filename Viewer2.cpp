#include "Viewer2.h"


Viewer2::Viewer2(QQuickItem *parent)
    : QQuickPaintedItem{parent}
{
}

Viewer2::~Viewer2()
{
}

QImage Viewer2::getImage() const
{
    return m_image;
}

void Viewer2::paint(QPainter *painter)
{
    qDebug()<<__FUNCTION__<<"painter Draw";
    painter->drawImage(0, 0, m_image); // Draw the QImage in the QQuickPaintedItem
}


void Viewer2::doWork(QString filePath)
{
    const std::string path = filePath.toStdString();
    qDebug()<<__FUNCTION__<<"path =" <<filePath;
    Mat image =imread(path, IMREAD_COLOR);
    if (image.empty()) {
        qWarning("Failed to load image");
        return;
    }

    // Convert cv::Mat to QImage
    cvtColor(image, image, cv::COLOR_BGR2RGB); // Swap BGR to RGB
    QImage qImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_RGB888);
    m_image = qImage.copy(); // Create a deep copy of the QImage

    qDebug()<<__FUNCTION__<<"Signal Send image Changed";
    emit imageChanged();
}

void Viewer2::openViewer()
{
    qDebug()<<__FUNCTION__;
}
