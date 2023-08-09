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

void Viewer::TestopenCV()
{

#if 1  //call paint
    // OpenCV 코드 시작
    // Get the directory where the source code is located
    QString sourceCodePath = QFileInfo(QCoreApplication::applicationFilePath()).path();
    int lastSlashIndex = sourceCodePath.lastIndexOf('/');
    sourceCodePath = sourceCodePath.left(lastSlashIndex);

    // Append the image file path relative to the source code directory
    QString imagePath = sourceCodePath + "/L_Teraphy/image/1.jpg";

#if 1
    cv::Mat image = cv::imread(imagePath.toStdString(), cv::IMREAD_COLOR/*cv::IMREAD_GRAYSCALE*/);
    qDebug()<<__FUNCTION__ << "## Path =" <<imagePath;
    if (image.empty()) {
        qWarning("Failed to load image");
        return;
    }

    // Convert cv::Mat to QImage
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB); // Swap BGR to RGB
    QImage qImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_RGB888);
    m_image = qImage.copy(); // Create a deep copy of the QImage
#else

    QImage qImage(imagePath);
    if (qImage.isNull()) {
        qWarning("Failed to load image");
        return;
    }

    m_image = qImage.copy(); // Create a deep copy of the QImage

#endif

    qDebug()<<__FUNCTION__<<"Signal Send image Changed";
    emit imageChanged();
#endif



#if 0  //opencv draw

    // Get the directory where the source code is located
    QString sourceCodePath = QFileInfo(QCoreApplication::applicationFilePath()).path();
    int lastSlashIndex = sourceCodePath.lastIndexOf('/');
    sourceCodePath = sourceCodePath.left(lastSlashIndex);

    // Append the image file path relative to the source code directory
    QString imagePath = sourceCodePath + "/L_Teraphy/image/1.jpg";

    //covert to Qstring to char *
    const char *charArray = imagePath.toUtf8().constData();

    cv::Mat image = cv::imread(charArray);
    cv::namedWindow("TestImage", cv::WINDOW_AUTOSIZE);
    cv::imshow("TestImage",image);
    cv::waitKey();
    cv::destroyWindow("TestImage");

#endif



#if 0  //camera

    cv::Mat frame;
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
    {
        qWarning()<<"Can't open a camera";
        return ;
    }

    cap.read(frame);
    if(frame.empty())
    {
        qWarning()<<"Can't capture a camera";
        return ;
    }

    cv::namedWindow("TestImage", cv::WINDOW_AUTOSIZE);
    cv::imshow("TestImage",frame);
    cv::waitKey();
    cv::destroyWindow("TestImage");




#endif
}


void Viewer::openViewer()
{
    qDebug()<<__FUNCTION__;

    TestopenCV();
    //TestopenCV2();
}



Point2f src[15];
int idx = 0;
Mat img_color;

double Distance(const Point& p1, const Point& p2){

    double distance;
    distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    return distance;
}

double calculateAngle(const Point& p1, const Point& p2) {
    double deltaX = p2.x - p1.x;
    double deltaY = p2.y - p1.y;
    return atan2(deltaY, deltaX) * 180.0 / M_PI;
}

Point calculateMidpoint(const Point& p1, const Point& p2) {
    Point midpoint;
    midpoint.x = (p1.x + p2.x) / 2.0;
    midpoint.y = (p1.y + p2.y) / 2.0;
    return midpoint;
}


void mouse_callback(int event, int x, int y, int flgs, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        src[idx] = Point2f(x, y);
        idx++;

        qDebug() << "(" << x << "," << y << ")" << endl;
        circle(img_color, Point(x, y), 3, Scalar(0, 0, 255), -1);
        imshow("source", img_color);

    }
}


void Viewer::TestopenCV2()
{
    namedWindow("source");
    setMouseCallback("source", mouse_callback);
    //img_color=imread("/home/sejong/Work/Lteraphy/L_Teraphy/image/walk_540.jpg", IMREAD_COLOR);
    img_color=imread("/home/sejong/Work/Lteraphy/L_Teraphy/image/2.jpeg", IMREAD_COLOR);

    int height = img_color.rows;
    int width = img_color.cols;
    qDebug()<<__FUNCTION__<<"height ="<<height <<" , width ="<<width;

    Mat img_mask(height,width,CV_8UC3,Scalar(0,0,0));

    while (1)
    {
        imshow("source", img_color);
        if (waitKey(1) == 32)//SPACE Key
        {
            destroyWindow("source");
            break;
        }
    }

    circle(img_mask, Point(src[0]),Distance(src[0], src[2]), Scalar(255, 255, 255), -1);
    qDebug()<<"circle completed !";

    std::vector<cv::Point> body;
    body.push_back(cv::Point(src[1].x, src[1].y));
    body.push_back(cv::Point(src[2].x, src[2].y));
    body.push_back(cv::Point(src[3].x, src[3].y));
    body.push_back(cv::Point(src[9].x, src[9].y));
    body.push_back(cv::Point(src[11].x, src[11].y));
    body.push_back(cv::Point(src[10].x, src[10].y));
    body.push_back(cv::Point(src[8].x, src[8].y));
    fillConvexPoly(img_mask,body,Scalar(255, 255, 255));

   qDebug()<<"fillConvexPoly completed !";

    ellipse(img_mask, calculateMidpoint(src[1],src[5]),Size(Distance(src[1], src[5])/2,20),calculateAngle(src[1], src[5]),0,360, Scalar(255, 255, 255), -1);
    ellipse(img_mask, calculateMidpoint(src[5],src[4]),Size(Distance(src[5], src[4])/2+10,20),calculateAngle(src[5], src[4]),0,360, Scalar(255, 255, 255), -1);

    ellipse(img_mask, calculateMidpoint(src[3],src[6]),Size(Distance(src[3], src[6])/2,20),calculateAngle(src[3], src[6]),0,360, Scalar(255, 255, 255), -1);
    ellipse(img_mask, calculateMidpoint(src[6],src[7]),Size(Distance(src[6], src[7])/2+10,20),calculateAngle(src[6], src[7]),0,360, Scalar(255, 255, 255), -1);

    ellipse(img_mask, calculateMidpoint(src[10],src[12]),Size(Distance(src[10], src[12])/2+10,20),calculateAngle(src[10], src[12]),0,360, Scalar(255, 255, 255), -1);
    ellipse(img_mask, calculateMidpoint(src[12],src[14]),Size(Distance(src[12], src[14])/2+10,20),calculateAngle(src[12], src[14]),0,360, Scalar(255, 255, 255), -1);

    ellipse(img_mask, calculateMidpoint(src[11],src[13]),Size(Distance(src[11], src[13])/2+10,20),calculateAngle(src[11], src[13]),0,360, Scalar(255, 255, 255), -1);
    ellipse(img_mask, calculateMidpoint(src[13],src[15]),Size(Distance(src[13], src[15])/2+10,20),calculateAngle(src[13], src[15]),0,360, Scalar(255, 255, 255), -1);

    qDebug()<<"ellipse completed !";

    DetectSegmentation detectSegmentation(img_mask);
    BackGround backGround(detectSegmentation.img_color);




    //namedWindow("TestImage", cv::WINDOW_AUTOSIZE);
    //imshow("TestImage",img_mask);
    //waitKey();
    //destroyWindow("TestImage");

}

