#include "../gui/EditWindow.h


EditWindow::EditWindow(QWidget* parent)
    : QWidget(parent)
{
    //tabs = new QTabWidget(this);
    //tabs->addTab(new SourceTab, "Źródło");
    //tabs->addTab(new RoiTab, "ROI");
    //tabs->addTab(new FilterTab, "Filtry");
    //tabs->addTab(new SettingsTab, "Ustawienia");
    //tabs->addTab(new ResultsTab, "Wyniki");

    auto* layout = new QVBoxLayout(this);
    layout->addWidget(tabs);
}
