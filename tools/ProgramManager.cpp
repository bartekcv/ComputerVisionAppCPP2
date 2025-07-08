#include "../tools/ProgramManager.h"
#include <iostream>

void ProgramManager::createProgramFile(const std::filesystem::path& filePath, const nlohmann::json& content) {
    if (std::filesystem::exists(filePath)) {
        throw std::runtime_error("Program already exist: " + filePath.string());
    }

    std::ofstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Nie można utworzyć pliku: " + filePath.string());
    }

    file << content.dump(4); 
}

nlohmann::json ProgramManager::openProgramFile(const std::filesystem::path& filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku: " + filePath.string());
    }
    nlohmann::json data;
    file >> data;
    return data;
}

std::vector<std::filesystem::path>& ProgramManager::getPrograms() {
    return programs;
}

void ProgramManager::updateProgramList(const std::filesystem::path& folderPath) {
    this->programs;
    programs.clear();
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".json") {
            programs.push_back(entry.path());
        }
    }
}

void ProgramManager::deleteProgram(const std::filesystem::path& filePath){

    if (!std::filesystem::remove(filePath)) {
        return;
    }

}

void ProgramManager::printJson(const nlohmann::json& j, int indent) {
    QString prefix(indent, ' ');

    if (j.is_object()) {
        for (auto& [key, value] : j.items()) {
            qDebug().noquote() << prefix + QString::fromStdString(key) + ":";
            printJson(value, indent + 2);
        }
    } else if (j.is_array()) {
        for (const auto& item : j) {
            printJson(item, indent + 2);
        }
    } else {
        qDebug().noquote() << prefix + QString::fromStdString(j.dump());
    }
}

bool ProgramManager::folderExist(const std::filesystem::path& folderPath){
    return (std::filesystem::exists(folderPath) && std::filesystem::is_directory(folderPath));
}


nlohmann::json ProgramManager::initProgram(std::string name){
 	nlohmann::json data = {
            {"name", name},
            {"capture", {
                {"camera_index", 0},
                {"resolution", {640, 480}}
            }},
            {"tools", nlohmann::json::array()}
        };
        return data;
}









