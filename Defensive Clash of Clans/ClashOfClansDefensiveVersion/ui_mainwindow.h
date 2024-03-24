/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_button
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *button)
    {
        if (button->objectName().isEmpty())
            button->setObjectName("button");
        button->resize(800, 600);
        centralwidget = new QWidget(button);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 150, 101, 24));
        button->setCentralWidget(centralwidget);
        menubar = new QMenuBar(button);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        button->setMenuBar(menubar);
        statusbar = new QStatusBar(button);
        statusbar->setObjectName("statusbar");
        button->setStatusBar(statusbar);

        retranslateUi(button);

        QMetaObject::connectSlotsByName(button);
    } // setupUi

    void retranslateUi(QMainWindow *button)
    {
        button->setWindowTitle(QCoreApplication::translate("button", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("button", "Start the game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class button: public Ui_button {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
