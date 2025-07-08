#include "editview.h"
#include "ui_editview.h"



EditView::EditView(QWidget *parent, QStackedWidget *widgetStack):
    QWidget(parent),
    ui(new Ui::EditView),
    mainWidget(widgetStack)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->captureSetings);
    roiSelector = new ROISelector(ui->camImage, this);
    //ui->sourceInput->setValue(5);

}

EditView::~EditView()
{
    delete ui;
}


void EditView::on_captureSetingsButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->captureSetings);
  
}
void EditView::on_addToolButton_clicked(){
        nlohmann::json newTool = {
        {"type", "NewTool"},
        {"roi", {{"x",0},{"y",0},{"width",100},{"height",100}}},
        {"filters", nlohmann::json::array()},
        {"params", {{"param1", 0}, {"param2", true}}},
        {"output", {}}
    };

    //programData["tools"].push_back(newTool);
    //int index = programData["tools"].size() - 1;
    //ui->toolsList->addItem("New tool #" + QString::number(index));
    ui->stackedWidget->setCurrentWidget(ui->editTool);
}
void EditView::on_backButton_clicked(){
    mainWidget->setCurrentIndex(0); 
}

void EditView::on_captureButton_clicked(){
    cam1.capture();
    img = cam1.showImage();
    QPixmap pixmap = QPixmap::fromImage(img);
    ui->camImage->setPixmap(pixmap); 
    roiSelector->setSourceImage(img);
}

void EditView::setProgramData(nlohmann::json json, std::filesystem::path path){

    //programPath = path;
    
    cam1.setProgramData(json);
    //nlohmann::json getProgramData();
//
    //ui->toolsList->clear();
    //
    ////set cameraID
    //if (programData.contains("capture") && programData["capture"].contains("camera_index")) {
    //    int cameraIndex = programData["capture"]["camera_index"];
    //    ui->sourceInput->setValue(cameraIndex);
    //}
}

void EditView::saveCurrentToolData() {
 //   if (currentToolIndex < 0 || currentToolIndex >= programData["tools"].size()) return;
//
 //   auto& params = programData["tools"][currentToolIndex]["params"];
 //   params.clear();
//
 //   for (int i = 0; i < toolFormLayout->rowCount(); ++i) {
 //       QLabel* label = qobject_cast<QLabel*>(toolFormLayout->itemAt(i, QFormLayout::LabelRole)->widget());
 //       QLineEdit* edit = qobject_cast<QLineEdit*>(toolFormLayout->itemAt(i, QFormLayout::FieldRole)->widget());
 //       if (label && edit) {
 //           std::string key = label->text().toStdString();
 //           std::string val = edit->text().toStdString();
 //           // Zakładamy JSON parseable:
 //           try {
 //               params[key] = nlohmann::json::parse(val);
 //           } catch (...) {
 //               params[key] = val; // fallback jako string
 //           }
 //       }
 //   }
}

void EditView::on_saveButton_clicked() {
    saveCurrentToolData();
}










