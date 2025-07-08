//#include "ImageProcessing.h"
#pragma once
#include "ImageCapture.h"
#include <nlohmann/json.hpp>

class MainProcessing{

public:
    void capture();
    QImage showImage(); 
    void loadData();
    void setProgramData(nlohmann::json);
    nlohmann::json getProgramData();
     

private: 
    ImageCapture cap = ImageCapture();
    cv::Mat matImage;
    QImage qtImage;
    nlohmann::json programData;
    std::filesystem::path programPath;
};