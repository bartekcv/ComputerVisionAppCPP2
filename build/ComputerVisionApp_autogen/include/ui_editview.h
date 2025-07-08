/********************************************************************************
** Form generated from reading UI file 'editview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITVIEW_H
#define UI_EDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditView
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *captureSetingsButton;
    QPushButton *addToolButton;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QListWidget *toolsList;
    QPushButton *pushButton_4;
    QPushButton *backButton;
    QPushButton *saveButton;
    QStackedWidget *stackedWidget;
    QWidget *captureSetings;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *camImage;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpinBox *widthInput;
    QPushButton *captureButton;
    QSpinBox *sourceInput;
    QSpinBox *heightInput;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *editTool;
    QLabel *label_2;

    void setupUi(QWidget *EditView)
    {
        if (EditView->objectName().isEmpty())
            EditView->setObjectName(QString::fromUtf8("EditView"));
        EditView->resize(921, 583);
        verticalLayoutWidget = new QWidget(EditView);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 181, 501));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        captureSetingsButton = new QPushButton(verticalLayoutWidget);
        captureSetingsButton->setObjectName(QString::fromUtf8("captureSetingsButton"));

        verticalLayout->addWidget(captureSetingsButton);

        addToolButton = new QPushButton(verticalLayoutWidget);
        addToolButton->setObjectName(QString::fromUtf8("addToolButton"));

        verticalLayout->addWidget(addToolButton);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        toolsList = new QListWidget(verticalLayoutWidget);
        toolsList->setObjectName(QString::fromUtf8("toolsList"));

        verticalLayout->addWidget(toolsList);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        backButton = new QPushButton(verticalLayoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        verticalLayout->addWidget(backButton);

        saveButton = new QPushButton(verticalLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout->addWidget(saveButton);

        stackedWidget = new QStackedWidget(EditView);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(210, 20, 661, 501));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        captureSetings = new QWidget();
        captureSetings->setObjectName(QString::fromUtf8("captureSetings"));
        verticalLayoutWidget_2 = new QWidget(captureSetings);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(5, -1, 601, 501));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        camImage = new QLabel(verticalLayoutWidget_2);
        camImage->setObjectName(QString::fromUtf8("camImage"));
        sizePolicy.setHeightForWidth(camImage->sizePolicy().hasHeightForWidth());
        camImage->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(camImage);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, -1, -1);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        widthInput = new QSpinBox(verticalLayoutWidget_2);
        widthInput->setObjectName(QString::fromUtf8("widthInput"));
        widthInput->setMaximum(2000);

        gridLayout->addWidget(widthInput, 2, 2, 1, 1);

        captureButton = new QPushButton(verticalLayoutWidget_2);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));

        gridLayout->addWidget(captureButton, 2, 0, 1, 1);

        sourceInput = new QSpinBox(verticalLayoutWidget_2);
        sourceInput->setObjectName(QString::fromUtf8("sourceInput"));
        sourceInput->setMaximum(2000);

        gridLayout->addWidget(sourceInput, 2, 1, 1, 1);

        heightInput = new QSpinBox(verticalLayoutWidget_2);
        heightInput->setObjectName(QString::fromUtf8("heightInput"));

        gridLayout->addWidget(heightInput, 2, 3, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        stackedWidget->addWidget(captureSetings);
        editTool = new QWidget();
        editTool->setObjectName(QString::fromUtf8("editTool"));
        label_2 = new QLabel(editTool);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 0, 241, 31));
        label_2->setFont(font);
        stackedWidget->addWidget(editTool);

        retranslateUi(EditView);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditView);
    } // setupUi

    void retranslateUi(QWidget *EditView)
    {
        EditView->setWindowTitle(QCoreApplication::translate("EditView", "Form", nullptr));
        captureSetingsButton->setText(QCoreApplication::translate("EditView", "Capture setings", nullptr));
        addToolButton->setText(QCoreApplication::translate("EditView", "Add tool ", nullptr));
        pushButton->setText(QCoreApplication::translate("EditView", "Move up", nullptr));
        pushButton_5->setText(QCoreApplication::translate("EditView", "Move down", nullptr));
        pushButton_6->setText(QCoreApplication::translate("EditView", "Delete", nullptr));
        pushButton_4->setText(QCoreApplication::translate("EditView", "Results ", nullptr));
        backButton->setText(QCoreApplication::translate("EditView", "Back", nullptr));
        saveButton->setText(QCoreApplication::translate("EditView", "Save", nullptr));
        label->setText(QCoreApplication::translate("EditView", "Capture setings", nullptr));
        camImage->setText(QCoreApplication::translate("EditView", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("EditView", "Source ", nullptr));
        captureButton->setText(QCoreApplication::translate("EditView", "Capture", nullptr));
        label_4->setText(QCoreApplication::translate("EditView", "Width", nullptr));
        label_5->setText(QCoreApplication::translate("EditView", "Height ", nullptr));
        label_2->setText(QCoreApplication::translate("EditView", "Edit tool", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditView: public Ui_EditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITVIEW_H
