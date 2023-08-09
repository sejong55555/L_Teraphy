#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <opencv2/opencv.hpp>
#include <cmath>

class BackGround
{
public:
    BackGround(cv::Mat img_color);
    void drawImage(cv::Mat img_color, sf::Image& image, int colorCycleTime, sf::RenderWindow& window, int width, int height);
    void set_Back(cv::Mat img_color);
    bool shouldSave = false;
};

#endif // BACKGROUND_H
