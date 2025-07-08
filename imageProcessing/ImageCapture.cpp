
#include "ImageCapture.h"


    ImageCapture::ImageCapture():cameraIndex(0), frameSize(640, 480), cap(nullptr) {}


    ImageCapture::~ImageCapture() {
        if (cap && cap->isOpened()) {
            cap->release();
        }
        delete cap;
    }

 
    void ImageCapture::setCameraIndex(int index) {
        cameraIndex = index;
        restartCapture();
    }

    // Ustaw rozmiar obrazu
    void ImageCapture::setFrameSize(int width, int height) {
        frameSize = cv::Size(width, height);
        resizeFrame();
    }

    // Pojedyncza klatka
    bool ImageCapture::captureSingleFrame(cv::Mat& outFrame) {
        if (!initializeCamera()) {
            return false;
        }
        *cap >> outFrame;
        cap->release();
        if (outFrame.empty()) {
            qDebug() << "Pusta klatka.";
            return false;
        }
        resizeFrame(outFrame);
        return true;
    }

    // Ciągłe wczytywanie obrazów - zwraca kolejny obraz lub filtruje/wywołuje callback
    bool ImageCapture::captureContinuousFrame(cv::Mat& outFrame) {
        if (!initializeCamera()) {
            return false;
        }
        *cap >> outFrame;
        if (outFrame.empty()) {
            qDebug() << "Pusta klatka.";
            return false;
        }
        resizeFrame(outFrame);
        return true;
    }

    // Diagnostyka - sprawdza czy kamera działa
    bool ImageCapture::checkCamera() {
        cv::VideoCapture tempCap(cameraIndex);
        bool isOpened = tempCap.isOpened();
        tempCap.release();
        return isOpened;
    }

    // Konwersja cv::Mat do QImage
    QImage ImageCapture::matToQImage(const cv::Mat& mat) {
        cv::Mat rgb;
        if (mat.channels() == 3) {
            cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);
            return QImage((const unsigned char*)(rgb.data), rgb.cols, rgb.rows, QImage::Format_RGB888).copy();
        } else if (mat.channels() == 1) {
            return QImage((const unsigned char*)(mat.data), mat.cols, mat.rows, QImage::Format_Grayscale8).copy();
        } else {
            // obsługa innych typów może być konieczna
            return QImage();
        }
    }

      // Inicjalizacja kamery
    bool ImageCapture::initializeCamera() {
        if (cap && cap->isOpened()) {
            return true;
        }

        cap = new cv::VideoCapture(cameraIndex, cv::CAP_V4L2);
        if (!cap->isOpened()) {
            qDebug() << "Nie można otworzyć kamery o indeksie" << cameraIndex;
            delete cap;
            cap = nullptr;
            return false;
        }
        resizeFrame();
        return true;
    }

    // Restartujemy po zmianie ustawień
    void ImageCapture::restartCapture() {
        if (cap && cap->isOpened()) {
            cap->release();
            delete cap;
        }
        cap = nullptr;
        initializeCamera();
    }

    // Wymuszenie rozmiaru klatki
    void ImageCapture::resizeFrame(cv::Mat& frame) {
        cv::resize(frame, frame, frameSize);
    }

    // Użyj tej metody, aby od razu zmienić rozmiar lub zainicjować
    void ImageCapture::resizeFrame() {
        // Opcjonalnie, można ustawić rozdzielczość kamery
        if (cap && cap->isOpened()) {
            cap->set(cv::CAP_PROP_FRAME_WIDTH, frameSize.width);
            cap->set(cv::CAP_PROP_FRAME_HEIGHT, frameSize.height);
        }
    }