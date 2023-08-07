#include "Viewer.h"


Viewer::Viewer(QQuickItem *parent)
    : QQuickPaintedItem{parent}
{
    // OpenCV 코드 시작
    // Get the directory where the source code is located
    QString sourceCodePath = QFileInfo(QCoreApplication::applicationFilePath()).path();
    int lastSlashIndex = sourceCodePath.lastIndexOf('/');
    sourceCodePath = sourceCodePath.left(lastSlashIndex);

    qDebug()<<__FUNCTION__ << "## source Path =" <<sourceCodePath; ///////// add debug

    // Append the image file path relative to the source code directory
    QString imagePath = sourceCodePath + "/L_Teraphy/image/1.jpg";


    cv::Mat image = cv::imread(imagePath.toStdString());
    qDebug()<<__FUNCTION__ << "## Path =" <<imagePath;
    if (image.empty()) {
        qWarning("Failed to load image");
        return;
    }

    // Convert cv::Mat to QImage
    QImage qImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_RGB888);
    m_image = qImage.copy(); // Create a deep copy of the QImage

    qDebug()<<__FUNCTION__<<"Signal Send image Changed";
    emit imageChanged();
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

