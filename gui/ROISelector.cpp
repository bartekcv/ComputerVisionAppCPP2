#include "ROISelector.h"

ROISelector::ROISelector(QLabel *targetLabel, QObject *parent)
    : QObject(parent), label(targetLabel), selectingROI(false)
{
    label->installEventFilter(this);
}

void ROISelector::setSourceMat(const cv::Mat &m) {
    mat = m.clone();
}

void ROISelector::setSourceImage(const QImage &img) {
    image = img;
}

bool ROISelector::eventFilter(QObject *obj, QEvent *event) {
    if (obj == label) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            selectingROI = true;
            roiStart = mouseEvent->pos();
            roiEnd = roiStart;
            return true;
        }
        else if (event->type() == QEvent::MouseMove && selectingROI) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            roiEnd = mouseEvent->pos();
            drawROIRectangle();
            return true;
        }
        else if (event->type() == QEvent::MouseButtonRelease && selectingROI) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            roiEnd = mouseEvent->pos();
            selectingROI = false;
            drawROIRectangle();

            QRect roiRect = QRect(roiStart, roiEnd).normalized();
            if (!mat.empty()) {
                cv::Rect cvRoi = qtToCvRect(roiRect, label->size(), mat.size());
                if (cvRoi.width > 0 && cvRoi.height > 0) {
                    cv::Mat roi = mat(cvRoi);
                    cv::imshow("Zaznaczone ROI", roi);
                    cv::waitKey(1);
                }
            }
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

void ROISelector::drawROIRectangle() {
    QImage tempImage = image;
    QPainter painter(&tempImage);
    painter.setPen(QPen(Qt::red, 2));
    QRect rect(roiStart, roiEnd);
    painter.drawRect(rect.normalized());
    label->setPixmap(QPixmap::fromImage(tempImage));
}

cv::Rect ROISelector::qtToCvRect(const QRect &rect, const QSize &labelSize, const cv::Size &matSize) {
    double scaleX = static_cast<double>(matSize.width) / labelSize.width();
    double scaleY = static_cast<double>(matSize.height) / labelSize.height();
    return cv::Rect(rect.x() * scaleX, rect.y() * scaleY,
                    rect.width() * scaleX, rect.height() * scaleY);
}

cv::Rect ROISelector::getSelectedROI() {
    QRect rect = QRect(roiStart, roiEnd).normalized();
    return qtToCvRect(rect, label->size(), mat.size());
}
