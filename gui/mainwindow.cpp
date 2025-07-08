#include "mainwindow.h"
#include "editview.h"
#include "../build/ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
//#include "../imageProcessing/MainProcessing.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    editView = new EditView(this, ui->stackedWidget);
    ui->stackedWidget->addWidget(editView);
    ui->stackedWidget->setCurrentWidget(ui->programsList);
    filePath = "../Programs";
    fileName = "NewProgram";
    updateProgramList();
    connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, [=](int index) {
    if (ui->stackedWidget->widget(index) == ui->programsList) {
        this->setWindowTitle("ComputerVision SIWEK");
    }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectButton_clicked() {
    QMessageBox::information(this, "Klik", "Kliknąłeś SELECT");
}

void MainWindow::on_editButton_clicked() {
        QListWidgetItem *selectedItem = ui->programListWidget->currentItem();

    if (!selectedItem) {
        QMessageBox::warning(this, "Brak wyboru", "Najpierw wybierz program z listy.");
        return;
    }

    QString selectedProgram = selectedItem->text();
    std::filesystem::path fullPath = std::filesystem::path(filePath) / selectedProgram.toStdString();

    // sprawdź, czy plik istnieje
    if (!std::filesystem::exists(fullPath)) {
        QMessageBox::critical(this, "Błąd", "Nie można znaleźć pliku: " + QString::fromStdString(fullPath.string()));
        return;
    }

        // Wczytaj plik .json do edytora
    //nlohmann::json programData = manager.loadProgramFile(fullPath); // ← zakładam, że masz taką metodę
    nlohmann::json programData = manager.openProgramFile(fullPath);
    
    // Przekaż dane do editView – musisz utworzyć metodę np. setProgramData(json)
    editView->setProgramData(programData, fullPath); // zakładamy, że pełna ścieżka się przyda

    // Ustaw widok i tytuł
    this->setWindowTitle("ComputerVision SIWEK - Edycja programu: " + selectedProgram);
    ui->stackedWidget->setCurrentWidget(editView);

}

void MainWindow::on_newButton_clicked() {
    QMessageBox::information(this, "Klik", "Kliknąłeś NEW");
        bool ok;
    fileName = QInputDialog::getText(this, "New Program", "Program name:", QLineEdit::Normal, "", &ok).toStdString();
    auto fullPath = std::filesystem::path(filePath) / (fileName + ".json");
    //nlohmann::json newData = { {"name", fileName}, {"version", 1.0} };
    nlohmann::json newData = manager.initProgram(fileName);
    manager.createProgramFile(fullPath, newData);
    updateProgramList();


}

void MainWindow::on_deleteButton_clicked() {
    QMessageBox::information(this, "Klik", "Kliknąłeś DELETE");
}

void MainWindow::on_copyButton_clicked() {
    QMessageBox::information(this, "Klik", "Kliknąłeś COPY");
}

void MainWindow::updateProgramList(){
    manager.updateProgramList(filePath);
    programs = manager.getPrograms();
    ui->programListWidget->clear();  
    for (const auto& programPath : programs) {
        QString fileName = QString::fromStdString(programPath.filename().string());  // tylko nazwa pliku
        ui->programListWidget->addItem(fileName);
    }
}



