
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QDebug>

class ImageCapture {
public:
    ImageCapture();
    ~ImageCapture();

    void setCameraIndex(int index);
    void setFrameSize(int width, int height);
    bool captureSingleFrame(cv::Mat& outFrame);
    bool captureContinuousFrame(cv::Mat& outFrame); 
    bool checkCamera(); 

    QImage matToQImage(const cv::Mat& mat); 

private:
    int cameraIndex;
    cv::Size frameSize;
    cv::VideoCapture* cap;

    bool initializeCamera(); 
    void restartCapture(); 
    void resizeFrame(cv::Mat& frame); 
    void resizeFrame(); 
};
