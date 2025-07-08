#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include "../tools/ProgramManager.h"
#include "editview.h"
//#include "../imageProcessing/ImageCapture.h"

class EditView;

namespace Ui {
class MainWindow;
//class CameraWorker;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QImage capture();
    QImage img; 

private:
    Ui::MainWindow *ui;
    ProgramManager manager;
    EditView *editView;
    std::vector<std::filesystem::path> programs; 
    std::filesystem::path filePath;
    std::string fileName;
    void updateProgramList();
    //ImageCapture cap = ImageCapture();
    //cv::Mat capturedImage;

private slots:
    void on_selectButton_clicked();
    void on_editButton_clicked();
    void on_newButton_clicked();
    void on_deleteButton_clicked();
    void on_copyButton_clicked();
};

#endif 