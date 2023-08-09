#include "DetectSegmentation.h"

DetectSegmentation::DetectSegmentation(cv::Mat input_img_color)
{
    img_color = input_img_color;
    const int imageSize = 1000;

    resize(img_color, img_color, Size(imageSize , imageSize));
    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);

    threshold(img_gray, img_binary, 150, 255, THRESH_BINARY_INV);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(img_binary, img_binary, MORPH_CLOSE, kernel);

    vector<vector<Point>> contours;
    findContours(img_binary, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
    for (size_t i = 0; i < contours.size(); ++i) {
        cv::Scalar color = cv::Scalar(0, 255, 0);
        cv::drawContours(img_color, contours, i, color, 1);
    }
}
