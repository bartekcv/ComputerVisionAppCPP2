#pragma once 
#ifndef EDITVIEW_H
#define EDITVIEW_H

#include <QWidget>
#include <QStackedWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QLabel>
#include <QMenuBar>
#include <QFormLayout>

#include "../imageProcessing/MainProcessing.h"
#include "ROISelector.h"
#include "mainwindow.h"


namespace Ui {
class EditView;
}

class EditView : public QWidget
{
    Q_OBJECT

public:
    explicit EditView(QWidget *parent = nullptr, QStackedWidget *stack = nullptr);//, ImageCapture* capture = nullptr);
    ~EditView();
    void setProgramData(nlohmann::json json, std::filesystem::path path);


private slots:
    void on_captureSetingsButton_clicked();
    void on_addToolButton_clicked();
    void on_backButton_clicked();
    void on_captureButton_clicked();
    void on_saveButton_clicked();
    //void updateImage();

private:
    Ui::EditView *ui;
    QStackedWidget *mainWidget;
    //MainWindow *mainWindow;
    MainProcessing cam1; 
    QImage img;
    ROISelector *roiSelector;
    //nlohmann::json programData;
    //std::filesystem::path programPath;
    QFormLayout* toolFormLayout = nullptr;
    int currentToolIndex = -1;

    void saveCurrentToolData();

};

#endif // EDITVIEW_H


