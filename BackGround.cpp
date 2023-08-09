#include "BackGround.h"

using namespace cv;

BackGround::BackGround(cv::Mat img_color)
{

    //Mat image = imread("/home/sejong/Work/Lteraphy/L_Teraphy/image/walk_540.jpg");
    //namedWindow("TestImage", WINDOW_AUTOSIZE);
    //imshow("TestImage",image);
    //waitKey();
    //destroyWindow("TestImage");




    cv::cvtColor(img_color, img_color, cv::COLOR_BGR2RGB);
    cv::Mat img_color_cv = img_color;

    const int imageSize = 1000;
    const int colorCycleTime = 500;

    cv::namedWindow("Natural Rainbow Image", cv::WINDOW_AUTOSIZE);

    cv::Mat image(imageSize, imageSize, CV_8UC3);


    while (true) {
        double timeInMillis = static_cast<double>(cv::getTickCount()) / cv::getTickFrequency() * 1000.0;

        for (int y = 0; y < imageSize; ++y) {
            for (int x = 0; x < imageSize; ++x) {
                // 이미지에 컬러 팔레트 그림
                int r = static_cast<int>(255.0f * x / imageSize);
                int g = static_cast<int>(255.0f * y / imageSize);
                int b = static_cast<int>(255.0f - 255.0f * y / imageSize);

                // 시간에 따라 색상 변화 주기 적용
                r = static_cast<int>(r * (std::sin(timeInMillis / colorCycleTime) + 1) / 2);
                g = static_cast<int>(g * (std::sin(timeInMillis / colorCycleTime + 2 * 3.14159f / 3) + 1) / 2);
                b = static_cast<int>(b * (std::sin(timeInMillis / colorCycleTime + 4 * 3.14159f / 3) + 1) / 2);

                cv::Vec3b img_color_pixel = img_color_cv.at<cv::Vec3b>(y, x);
                if (img_color_pixel != cv::Vec3b(0, 0, 0)) {
                    r += img_color_pixel[2]; // Red
                    g += img_color_pixel[1]; // Green
                    b += img_color_pixel[0]; // Blue
                }

                // RGB 값 범위 조정 (0 ~ 255)
                r = std::min(std::max(r, 0), 255);
                g = std::min(std::max(g, 0), 255);
                b = std::min(std::max(b, 0), 255);

                image.at<cv::Vec3b>(y, x) = cv::Vec3b(b, g, r);
            }
        }

        cv::imshow("Natural Rainbow Image", image);

        char key = cv::waitKey(30);
        if (key == 'q' || key == 'Q') {
            break;
        }
    }

    cv::destroyWindow("Natural Rainbow Image");

}
