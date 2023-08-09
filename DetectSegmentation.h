#ifndef DETECTSEGMENTATION_H
#define DETECTSEGMENTATION_H

#include <opencv2/opencv.hpp>
#include <cmath>

using namespace cv;
using namespace std;

class DetectSegmentation
{
public:
    DetectSegmentation();
    DetectSegmentation(cv::Mat img_color_cv);

    Mat img_color;
    Mat img_binary;
    Mat img_gray;
};

#endif // DETECTSEGMENTATION_H
