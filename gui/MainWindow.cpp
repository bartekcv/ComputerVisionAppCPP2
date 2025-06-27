#include "../gui/MainWindow.h"
#include "../tools/ProgramManager.h"
#include <iostream>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    programList = new QListWidget(this);
    selectButton = new QPushButton("Select", this);
    newButton = new QPushButton("New", this);
    editButton = new QPushButton("Edit", this);
    deleteButton = new QPushButton("Delete", this);
    updateButton = new QPushButton("Update", this);
    changePathButton = new QPushButton("Change Program Path", this);

    filePath = "../Programs";
    fileName = "NewProgram";

    // Layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(programList);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(selectButton);
    buttonLayout->addWidget(newButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(updateButton);
    buttonLayout->addWidget(changePathButton);

    mainLayout->addLayout(buttonLayout);

    central->setLayout(mainLayout);

    // Connect signals to slots
    connect(selectButton, &QPushButton::clicked, this, &MainWindow::onSelectClicked);
    connect(newButton, &QPushButton::clicked, this, &MainWindow::onNewClicked);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::onEditClicked);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
    connect(updateButton, &QPushButton::clicked, this, &MainWindow::onUpdateClicked);
    connect(changePathButton, &QPushButton::clicked, this, &MainWindow::onChangePathClicked);


}

// Slots implementations

void MainWindow::onSelectClicked() {
    auto item = programList->currentItem();
    if (item) {
        QMessageBox::information(this, "Select", "Selected: " + item->text());
    } else {
        QMessageBox::warning(this, "Select", "No program selected");
    }
}

void MainWindow::onNewClicked() {
    bool ok;
    fileName = QInputDialog::getText(this, "New Program", "Program name:", QLineEdit::Normal, "", &ok).toStdString();
    auto fullPath = std::filesystem::path(filePath) / (fileName + ".json");
    nlohmann::json newData = { {"name", fileName}, {"version", 1.0} };
    manager.createProgramFile(fullPath, newData);
    MainWindow::onUpdateClicked();
}

void MainWindow::onEditClicked() {
    auto item = programList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Edit", "No program selected");
        return;
    }
    bool ok;
    QString text = QInputDialog::getText(this, "Edit Program", "New name:", QLineEdit::Normal, item->text(), &ok);
    if (ok && !text.isEmpty()) {
        item->setText(text);
    }
}

void MainWindow::onDeleteClicked() {
    auto item = programList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Delete", "Select program to delete!");
        return;
    }
    auto reply = QMessageBox::question(
    this,
    "Delete Program",
    "Are you sure you want to delete program:\n" + item->text() + "?",
    QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    std::filesystem::path fullPath = std::filesystem::path(filePath) / item->text().toStdString();
    manager.deleteProgram(fullPath);
    MainWindow::onUpdateClicked();

    }
}

void MainWindow::onUpdateClicked() {
    manager.updateProgramList(filePath);
    programs = manager.getPrograms();
    programList->clear();  
    for (const auto& programPath : programs) {
        QString fileName = QString::fromStdString(programPath.filename().string());  // tylko nazwa pliku
        programList->addItem(fileName);
    }

}

void MainWindow::onChangePathClicked() {
    bool ok;
    auto newFilePath = QInputDialog::getText(this, "New program path", "Chose prorams folder:", QLineEdit::Normal, "", &ok).toStdString();
    if (manager.folderExist(newFilePath)) {
        filePath = newFilePath;
    }
    MainWindow::onUpdateClicked();
}


