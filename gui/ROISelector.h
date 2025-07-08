#ifndef ROISELECTOR_H
#define ROISELECTOR_H

#include <QObject>
#include <QImage>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <opencv2/opencv.hpp>

class ROISelector : public QObject
{
    Q_OBJECT

public:
    ROISelector(QLabel *targetLabel, QObject *parent = nullptr);

    void setSourceMat(const cv::Mat &mat);
    void setSourceImage(const QImage &image);
    void drawROIRectangle();

    cv::Rect getSelectedROI();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QLabel *label;
    QImage image;
    cv::Mat mat;
    QPoint roiStart, roiEnd;
    bool selectingROI;

    cv::Rect qtToCvRect(const QRect &rect, const QSize &labelSize, const cv::Size &matSize);
};

#endif // ROISELECTOR_H
