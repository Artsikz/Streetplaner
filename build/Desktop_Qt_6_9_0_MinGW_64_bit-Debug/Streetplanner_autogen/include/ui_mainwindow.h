/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSafe;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_fillMap;
    QCheckBox *checkBox_showTests;
    QPushButton *pushButton_testSimpleUi;
    QLineEdit *lineEdit_test;
    QPushButton *pushButton_testDrawMapWithCities;
    QLabel *label_eingabe;
    QPushButton *pushButton_testSimpleDrawing;
    QPushButton *pushButton_TestDraw;
    QPushButton *pushButton_testRejectStreet;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_DrawCity;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_test;
    QPushButton *pushButton_testDrawStreets;
    QPushButton *pushButton_testDrawMapWithStreets;
    QPushButton *pushButton_addCity;
    QPushButton *pushButton_testDrawCities;
    QPushButton *pushButton_testAbstractMap;
    QPushButton *pushButton_dijkstraTest;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(435, 348);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setEnabled(false);
        actionSafe = new QAction(MainWindow);
        actionSafe->setObjectName("actionSafe");
        actionSafe->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(5);
        pushButton_fillMap = new QPushButton(centralwidget);
        pushButton_fillMap->setObjectName("pushButton_fillMap");

        gridLayout->addWidget(pushButton_fillMap, 15, 0, 1, 1);

        checkBox_showTests = new QCheckBox(centralwidget);
        checkBox_showTests->setObjectName("checkBox_showTests");

        gridLayout->addWidget(checkBox_showTests, 3, 0, 1, 1);

        pushButton_testSimpleUi = new QPushButton(centralwidget);
        pushButton_testSimpleUi->setObjectName("pushButton_testSimpleUi");

        gridLayout->addWidget(pushButton_testSimpleUi, 7, 0, 1, 1);

        lineEdit_test = new QLineEdit(centralwidget);
        lineEdit_test->setObjectName("lineEdit_test");
        lineEdit_test->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit_test, 2, 0, 1, 1);

        pushButton_testDrawMapWithCities = new QPushButton(centralwidget);
        pushButton_testDrawMapWithCities->setObjectName("pushButton_testDrawMapWithCities");

        gridLayout->addWidget(pushButton_testDrawMapWithCities, 10, 0, 1, 1);

        label_eingabe = new QLabel(centralwidget);
        label_eingabe->setObjectName("label_eingabe");

        gridLayout->addWidget(label_eingabe, 0, 0, 1, 1);

        pushButton_testSimpleDrawing = new QPushButton(centralwidget);
        pushButton_testSimpleDrawing->setObjectName("pushButton_testSimpleDrawing");

        gridLayout->addWidget(pushButton_testSimpleDrawing, 8, 0, 1, 1);

        pushButton_TestDraw = new QPushButton(centralwidget);
        pushButton_TestDraw->setObjectName("pushButton_TestDraw");

        gridLayout->addWidget(pushButton_TestDraw, 6, 0, 1, 1);

        pushButton_testRejectStreet = new QPushButton(centralwidget);
        pushButton_testRejectStreet->setObjectName("pushButton_testRejectStreet");

        gridLayout->addWidget(pushButton_testRejectStreet, 13, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 1, 39, 1);

        pushButton_DrawCity = new QPushButton(centralwidget);
        pushButton_DrawCity->setObjectName("pushButton_DrawCity");

        gridLayout->addWidget(pushButton_DrawCity, 9, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 38, 0, 1, 1);

        pushButton_test = new QPushButton(centralwidget);
        pushButton_test->setObjectName("pushButton_test");

        gridLayout->addWidget(pushButton_test, 4, 0, 1, 1);

        pushButton_testDrawStreets = new QPushButton(centralwidget);
        pushButton_testDrawStreets->setObjectName("pushButton_testDrawStreets");

        gridLayout->addWidget(pushButton_testDrawStreets, 11, 0, 1, 1);

        pushButton_testDrawMapWithStreets = new QPushButton(centralwidget);
        pushButton_testDrawMapWithStreets->setObjectName("pushButton_testDrawMapWithStreets");

        gridLayout->addWidget(pushButton_testDrawMapWithStreets, 12, 0, 1, 1);

        pushButton_addCity = new QPushButton(centralwidget);
        pushButton_addCity->setObjectName("pushButton_addCity");

        gridLayout->addWidget(pushButton_addCity, 14, 0, 1, 1);

        pushButton_testDrawCities = new QPushButton(centralwidget);
        pushButton_testDrawCities->setObjectName("pushButton_testDrawCities");

        gridLayout->addWidget(pushButton_testDrawCities, 5, 0, 1, 1);

        pushButton_testAbstractMap = new QPushButton(centralwidget);
        pushButton_testAbstractMap->setObjectName("pushButton_testAbstractMap");

        gridLayout->addWidget(pushButton_testAbstractMap, 16, 0, 1, 1);

        pushButton_dijkstraTest = new QPushButton(centralwidget);
        pushButton_dijkstraTest->setObjectName("pushButton_dijkstraTest");

        gridLayout->addWidget(pushButton_dijkstraTest, 17, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 435, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuInfo = new QMenu(menuFile);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSafe);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addAction(menuInfo->menuAction());
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSafe->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        pushButton_fillMap->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
        checkBox_showTests->setText(QCoreApplication::translate("MainWindow", "Testkn\303\266pfe", nullptr));
        pushButton_testSimpleUi->setText(QCoreApplication::translate("MainWindow", "TestSimpleUi", nullptr));
        lineEdit_test->setText(QString());
        lineEdit_test->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ihre eingabe", nullptr));
        pushButton_testDrawMapWithCities->setText(QCoreApplication::translate("MainWindow", "TestDrawMapWithCities", nullptr));
        label_eingabe->setText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        pushButton_testSimpleDrawing->setText(QCoreApplication::translate("MainWindow", "TestSimpleDrawing", nullptr));
        pushButton_TestDraw->setText(QCoreApplication::translate("MainWindow", "TestDraw", nullptr));
        pushButton_testRejectStreet->setText(QCoreApplication::translate("MainWindow", "TestRejectStreet", nullptr));
        pushButton_DrawCity->setText(QCoreApplication::translate("MainWindow", "Test Draw City", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_test->setToolTip(QCoreApplication::translate("MainWindow", "Come on, push it", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_test->setText(QCoreApplication::translate("MainWindow", "Push It", nullptr));
        pushButton_testDrawStreets->setText(QCoreApplication::translate("MainWindow", "TestDrawStreets", nullptr));
        pushButton_testDrawMapWithStreets->setText(QCoreApplication::translate("MainWindow", "TestDrawMapWithStreets", nullptr));
        pushButton_addCity->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        pushButton_testDrawCities->setText(QCoreApplication::translate("MainWindow", "TestDrawCities", nullptr));
        pushButton_testAbstractMap->setText(QCoreApplication::translate("MainWindow", "TestAbstractMap", nullptr));
        pushButton_dijkstraTest->setText(QCoreApplication::translate("MainWindow", "Dijkstra Test", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
