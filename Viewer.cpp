#include "Viewer.h"


Viewer::Viewer(QQuickItem *parent)
    : QQuickPaintedItem{parent}
{
    //TestopenCV();
    //TestopenCV2();
}

Viewer::~Viewer()
{

}

QImage Viewer::getImage() const
{
    return m_image;
}

void Viewer::paint(QPainter *painter)
{
    qDebug()<<__FUNCTION__<<"painter Draw";
    painter->drawImage(0, 0, m_image); // Draw the QImage in the QQuickPaintedItem
}


void Viewer::doWork(QString filePath)
{
    const std::string path = filePath.toStdString();
    qDebug()<<__FUNCTION__<<"path =" <<filePath;
    cv::Mat image =imread(path, IMREAD_COLOR);
    if (image.empty()) {
        qWarning("Failed to load image");
        return;
    }

    // Convert cv::Mat to QImage
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB); // Swap BGR to RGB
    QImage qImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_RGB888);
    m_image = qImage.copy(); // Create a deep copy of the QImage

    qDebug()<<__FUNCTION__<<"Signal Send image Changed";
    emit imageChanged();
}

void Viewer::openViewer()
{
    qDebug()<<__FUNCTION__;

    //TestopenCV();
}


void Viewer::TestopenCV()
{
    cv::Mat image =imread("/home/sejong/Work/Lteraphy/L_Teraphy/image/2.jpeg", IMREAD_COLOR);
    if (image.empty()) {
        qWarning("Failed to load image");
        return;
    }

    // Convert cv::Mat to QImage
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB); // Swap BGR to RGB
    QImage qImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_RGB888);
    m_image = qImage.copy(); // Create a deep copy of the QImage

    qDebug()<<__FUNCTION__<<"Signal Send image Changed";
    emit imageChanged();
}

