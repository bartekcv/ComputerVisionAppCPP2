
#include <iostream>
//#include "../tools/ProgramManager.h"
#include <QApplication>
#include "../gui/mainwindow.h"

int main(int argc, char *argv[]) {
    //ProgramManager manager;
    //manager.updateProgramList("../Programs/");
    //auto programs = manager.getPrograms();

    QApplication app(argc, argv);

    MainWindow window;
    window.resize(1200, 800);
    window.show();

    return app.exec();
}

//int main(int argc, char *argv[]){
//    
//    ProgramManager manager;
//
//    manager.updateProgramList("../Programs/");
//    auto programs = manager.getPrograms();
//    
//
//    for (const auto& path : programs) {
//        std::cout << " - " << path.filename().string() << '\n';
//    }
//
//    auto programName = "Test1.json";
//
//    auto filePath = std::filesystem::path("../Programs") / programName;
//    std::cout<<filePath;
//    nlohmann::json newData = { {"name", programName}, {"version", 1.0} };
//
//    manager.createProgramFile(filePath, newData);
//
//    manager.updateProgramList("../Programs/");
//
//    programs = manager.getPrograms();
//    
//    for (const auto& path : programs) {
//        std::cout << " - " << path.filename().string() << '\n';
//    }
//
//    //auto filePath = std::filesystem::path("../Programs") / programs[0].filename();
//
//    //std::cout<<filePath;
//
//    //try{
//    //auto p1 = manager.openProgramFile(filePath);
//    //}  catch (const std::exception& e) {
//    //std::cerr << "Błąd: " << e.what() << "\n";
//    //}/
//    
//    //ProgramManager::printJson(p1,0);
//
//    return 0;
//}