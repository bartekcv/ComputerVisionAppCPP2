/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionselectButtonClicked;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *programsList;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QListWidget *programListWidget;
    QSplitter *splitter;
    QPushButton *selectButton;
    QPushButton *newButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *copyButton;
    QWidget *empty;
    QMenuBar *menubar;
    QMenu *menuComputerVision_SIWEK;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionselectButtonClicked = new QAction(MainWindow);
        actionselectButtonClicked->setObjectName(QString::fromUtf8("actionselectButtonClicked"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -10, 801, 591));
        programsList = new QWidget();
        programsList->setObjectName(QString::fromUtf8("programsList"));
        verticalLayoutWidget_2 = new QWidget(programsList);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 781, 531));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        textEdit = new QTextEdit(verticalLayoutWidget_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 30));
        textEdit->setInputMethodHints(Qt::ImhNone);

        verticalLayout_2->addWidget(textEdit);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        programListWidget = new QListWidget(verticalLayoutWidget_2);
        programListWidget->setObjectName(QString::fromUtf8("programListWidget"));

        verticalLayout_2->addWidget(programListWidget);

        splitter = new QSplitter(verticalLayoutWidget_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        selectButton = new QPushButton(splitter);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        splitter->addWidget(selectButton);
        newButton = new QPushButton(splitter);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        newButton->setAutoDefault(false);
        splitter->addWidget(newButton);
        editButton = new QPushButton(splitter);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        splitter->addWidget(editButton);
        deleteButton = new QPushButton(splitter);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        splitter->addWidget(deleteButton);
        copyButton = new QPushButton(splitter);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        splitter->addWidget(copyButton);

        verticalLayout_2->addWidget(splitter);

        stackedWidget->addWidget(programsList);
        empty = new QWidget();
        empty->setObjectName(QString::fromUtf8("empty"));
        empty->setEnabled(true);
        stackedWidget->addWidget(empty);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuComputerVision_SIWEK = new QMenu(menubar);
        menuComputerVision_SIWEK->setObjectName(QString::fromUtf8("menuComputerVision_SIWEK"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuComputerVision_SIWEK->menuAction());
        menubar->addAction(menuEdit->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(selectButton, SIGNAL(clicked()), MainWindow, SLOT(update()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ComputerVision SIWEK", nullptr));
        actionselectButtonClicked->setText(QCoreApplication::translate("MainWindow", "selectButtonClicked", nullptr));
#if QT_CONFIG(shortcut)
        actionselectButtonClicked->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "Chose programs path:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Chose program:", nullptr));
        selectButton->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        newButton->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        menuComputerVision_SIWEK->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
