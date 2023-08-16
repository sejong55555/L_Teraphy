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
    qDebug() << __FUNCTION__ << "path =" << filePath;
    Mat image = imread(path, IMREAD_UNCHANGED); // Use IMREAD_UNCHANGED to keep alpha channel
    if (image.empty()) {
        qWarning("Failed to load image");
        return;
    }


    QImage qImage;

    if (image.channels() == 3) {
        cvtColor(image, image, cv::COLOR_BGR2RGB); // Swap BGR to RGB
        qImage = QImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_RGB888);
    } else if (image.channels() == 4) {
        //qImage = QImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_ARGB32_Premultiplied);
        qImage = QImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_ARGB32);
    }

    if (qImage.isNull()) {
        qWarning("Failed to convert cv::Mat to QImage");
        return;
    }

    m_image = qImage.copy(); // Create a deep copy of the QImage

    qDebug() << __FUNCTION__ << "Signal Send image Changed";
    update();
}

