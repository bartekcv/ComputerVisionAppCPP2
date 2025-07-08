#pragma once
#include <QWidget>
#include <QTabWidget>


class EditWindow : public QWidget {
    Q_OBJECT
public:
    EditWindow(QWidget* parent = nullptr);

private:
    //QTabWidget* tabs;

signals:
    void backRequested();
};