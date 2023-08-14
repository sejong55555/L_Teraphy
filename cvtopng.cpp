#include "cvtopng.h"

CVtoPNG::CVtoPNG()
{
    // 4채널 이미지 생성 (알파 채널 포함)
    cv::Mat image(300, 400, CV_8UC4, cv::Scalar(0, 255, 0, 255)); // 불투명한 초록색 이미지 생성

    // 이미지에 텍스트 추가 (알파 채널 값은 255로 설정하여 완전 불투명하게)
    //cv::putText(image, "Hello, OpenCV", cv::Point(50, 150), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 0, 255, 255), 4);
    cv::putText(image, "Hello, OpenCV", cv::Point(50, 150), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 0, 0, 255), 4);


    cvtColor(image, image, cv::COLOR_BGRA2RGBA); // Convert BGR to RGBA

    // 녹색 부분의 알파 채널 값을 0으로 설정하여 투명하게 만듦
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            cv::Vec4b &pixel = image.at<cv::Vec4b>(y, x);
            if (pixel[0] == 0 && pixel[1] == 255 && pixel[2] == 0) {
                pixel[3] = 0; // Set alpha channel to 0 for green parts
            }
        }
    }

    // PNG 파일로 저장
    bool success = imwrite("/home/sejong/Work/Lteraphy/L_Teraphy/image/test.png", image);

    if (success) {
        qDebug() << "PNG file saved successfully." ;
    } else {
        qDebug() << "Failed to save PNG file.";
    }
}
