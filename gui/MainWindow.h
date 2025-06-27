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

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);

private:
    ProgramManager manager;
    std::vector<std::filesystem::path> programs; 
    std::filesystem::path filePath;
    std::string fileName;
    QListWidget* programList;
    QPushButton* selectButton;
    QPushButton* newButton;
    QPushButton* editButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* changePathButton;

private slots:
    void onSelectClicked();
    void onNewClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onUpdateClicked();
    void onChangePathClicked();
};




#endif // MAINWINDOW_H