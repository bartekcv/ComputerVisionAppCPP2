#pragma once
#include <QString>
#include <vector>
#include <nlohmann/json.hpp>
#include <QStringList>
#include <fstream>
#include <QDebug>

class ProgramManager {
public:
 
    void createProgramFile(const std::filesystem::path& filePath, const nlohmann::json& content);
    nlohmann::json openProgramFile(const std::filesystem::path& filePath);
    std::vector<std::filesystem::path>& getPrograms();
    void updateProgramList(const std::filesystem::path& folderPath);
    void deleteProgram(const std::filesystem::path& filePath);
    static void printJson(const nlohmann::json& j, int indent = 0);
    bool folderExist(const std::filesystem::path& filePath);
    nlohmann::json initProgram(std::string name);

private:
    std::vector<std::filesystem::path> programs;



};
