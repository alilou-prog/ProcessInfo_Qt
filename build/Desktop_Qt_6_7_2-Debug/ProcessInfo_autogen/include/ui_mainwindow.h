/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *argsCheckBox;
    QCheckBox *cmdCheckBox;
    QCheckBox *commCheckBox;
    QCheckBox *pidCheckBox;
    QCheckBox *ppidCheckBox;
    QCheckBox *ttyCheckBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(277, 313);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        argsCheckBox = new QCheckBox(groupBox);
        argsCheckBox->setObjectName("argsCheckBox");

        verticalLayout->addWidget(argsCheckBox);

        cmdCheckBox = new QCheckBox(groupBox);
        cmdCheckBox->setObjectName("cmdCheckBox");

        verticalLayout->addWidget(cmdCheckBox);

        commCheckBox = new QCheckBox(groupBox);
        commCheckBox->setObjectName("commCheckBox");

        verticalLayout->addWidget(commCheckBox);

        pidCheckBox = new QCheckBox(groupBox);
        pidCheckBox->setObjectName("pidCheckBox");

        verticalLayout->addWidget(pidCheckBox);

        ppidCheckBox = new QCheckBox(groupBox);
        ppidCheckBox->setObjectName("ppidCheckBox");

        verticalLayout->addWidget(ppidCheckBox);

        ttyCheckBox = new QCheckBox(groupBox);
        ttyCheckBox->setObjectName("ttyCheckBox");

        verticalLayout->addWidget(ttyCheckBox);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(centralwidget);
        okButton->setObjectName("okButton");

        horizontalLayout->addWidget(okButton);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 277, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        argsCheckBox->setText(QCoreApplication::translate("MainWindow", "args", nullptr));
        cmdCheckBox->setText(QCoreApplication::translate("MainWindow", "cmd", nullptr));
        commCheckBox->setText(QCoreApplication::translate("MainWindow", "comm", nullptr));
        pidCheckBox->setText(QCoreApplication::translate("MainWindow", "pid", nullptr));
        ppidCheckBox->setText(QCoreApplication::translate("MainWindow", "ppid", nullptr));
        ttyCheckBox->setText(QCoreApplication::translate("MainWindow", "tty", nullptr));
        cancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        okButton->setText(QCoreApplication::translate("MainWindow", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
