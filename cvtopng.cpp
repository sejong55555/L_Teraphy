#include "cvtopng.h"
#include "Global.h"

CVtoPNG::CVtoPNG(QObject *parent) :
    QObject(parent)
{

}

void CVtoPNG::doPngThread(const QString &msg)
{
    QString str[5]={"Have a good day", "You will do well","Luck is with you","Like the first time","Let's do our best"};
    int i=0;

    while (1) {
        //qDebug()<<"#";
        WritePNGText(str[i],QString(WORK_PATH_TXT_IMAGE).arg(i),300,400);
        QThread::msleep(1000);
        emit writeCompleted();

        i++;
        if(i>4) i=0;
    }
}

int CVtoPNG::WritePNGText(QString str, QString path, unsigned int width, unsigned int height)
{
    // 4채널 이미지 생성 (알파 채널 포함) //format BGRA
    cv::Mat image(width, height, CV_8UC4, cv::Scalar(0, 255, 0, 255)); // 불투명한 초록색 이미지 생성
    // 이미지에 RED 텍스트 추가 (알파 채널 값은 255로 설정하여 완전 불투명하게)
    cv::putText(image, str.toStdString(), cv::Point(50, 150), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 0, 255, 255), 4);
    //cvtColor(image, image, cv::COLOR_BGRA2RGBA); // Convert BGR to RGBA

    // 녹색 부분의 알파 채널 값을 0으로 설정하여 투명하게 만듦
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            cv::Vec4b &pixel = image.at<cv::Vec4b>(y, x);
            if (pixel[0] == 0 && pixel[1] == 255 && pixel[2] == 0) {
                pixel[3] = 0; // Set alpha channel to 0 for green parts
            }

        }
    }

    const std::string spath = path.toStdString();

    // PNG 파일로 저장
    bool success = imwrite(spath, image);

    if (success) {
        qDebug() << path+"  file saved successfully." ;
        return 0;
    } else {
        qDebug() << path+"  Failed to save PNG file.";
        return -1;
    }

}
