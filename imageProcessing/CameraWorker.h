#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QObject>
#include <opencv2/opencv.hpp>

class CameraWorker : public QObject {
    Q_OBJECT
public:
    void start();

private:
    cv::VideoCapture cap;
};

#endif // CAMERAWORKER_H