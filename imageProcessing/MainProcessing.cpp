#include "MainProcessing.h"

void MainProcessing::capture(){
    cap.setCameraIndex(0);
    //cap.setFrameSize(180, 480);
    cap.captureSingleFrame(matImage);
        
}

void MainProcessing::setProgramData(nlohmann::json js){
    this->programData = js;
    //cap.setCameraIndex(1);
        ////set cameraID
    if (programData.contains("capture") && programData["capture"].contains("camera_index")) {
        int cameraIndex = programData["capture"]["camera_index"];
        //ui->sourceInput->setValue(cameraIndex);
        cap.setCameraIndex(0);
    }
   
    if (programData.contains("capture") && programData["capture"].contains("resolution")) {
        auto resolution = programData["capture"]["resolution"];
        if (resolution.is_array() && resolution.size() == 2) {
            int width = resolution[0];
            int height = resolution[1];
            //ui->widthInput->setValue(width);
            //ui->heightInput->setValue(height);
            cap.setFrameSize(height, width);
        }
    }
}

nlohmann::json MainProcessing::getProgramData(){
    return this->programData;
}

QImage MainProcessing::showImage(){
    return cap.matToQImage(matImage);
}