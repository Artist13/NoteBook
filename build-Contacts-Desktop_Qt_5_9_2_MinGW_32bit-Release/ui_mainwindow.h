/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralWidget;
    QPushButton *AddPerson;
    QListWidget *listWidget;
    QListWidget *ListOfOrders;
    QPushButton *AddOrder;
    QPushButton *Delete_Student;
    QPushButton *Delete_Order;
    QPushButton *CreateReport;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(768, 487);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AddPerson = new QPushButton(centralWidget);
        AddPerson->setObjectName(QStringLiteral("AddPerson"));
        AddPerson->setGeometry(QRect(10, 410, 111, 23));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 20, 261, 361));
        ListOfOrders = new QListWidget(centralWidget);
        ListOfOrders->setObjectName(QStringLiteral("ListOfOrders"));
        ListOfOrders->setGeometry(QRect(290, 20, 461, 361));
        AddOrder = new QPushButton(centralWidget);
        AddOrder->setObjectName(QStringLiteral("AddOrder"));
        AddOrder->setGeometry(QRect(300, 410, 111, 23));
        Delete_Student = new QPushButton(centralWidget);
        Delete_Student->setObjectName(QStringLiteral("Delete_Student"));
        Delete_Student->setGeometry(QRect(170, 410, 101, 23));
        Delete_Order = new QPushButton(centralWidget);
        Delete_Order->setObjectName(QStringLiteral("Delete_Order"));
        Delete_Order->setGeometry(QRect(420, 410, 101, 23));
        CreateReport = new QPushButton(centralWidget);
        CreateReport->setObjectName(QStringLiteral("CreateReport"));
        CreateReport->setGeometry(QRect(644, 410, 101, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 768, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        AddPerson->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\207\320\265\320\275\320\270\320\272\320\260", Q_NULLPTR));
        AddOrder->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", Q_NULLPTR));
        Delete_Student->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\321\207\320\265\320\275\320\270\320\272\320\260", Q_NULLPTR));
        Delete_Order->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", Q_NULLPTR));
        CreateReport->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\276\321\202\321\207\320\265\321\202", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
