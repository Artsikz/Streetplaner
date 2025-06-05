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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *pushButton_testRejectStreet;
    QPushButton *pushButton_addCity;
    QLabel *label_eingabe;
    QPushButton *pushButton_addStreet;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_testDrawMapWithCities;
    QPushButton *pushButton_testSimpleUi;
    QPushButton *pushButton_DrawCity;
    QPushButton *pushButton_fillMap;
    QPushButton *pushButton_testSimpleDrawing;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_showTests;
    QPushButton *pushButton_clearMap;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_endCity;
    QComboBox *comboBox_startCity;
    QPushButton *pushButton_searchPath;
    QLabel *label_pathLength;
    QPushButton *pushButton_testDrawCities;
    QFrame *line_2;
    QPushButton *pushButton_dijkstraTest;
    QPushButton *pushButton_testAbstractMap;
    QPushButton *pushButton_testDrawStreets;
    QPushButton *pushButton_TestDraw;
    QPushButton *pushButton_testDrawMapWithStreets;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_test;
    QPushButton *pushButton_test;
    QPushButton *pushButton_loadMap;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(478, 562);
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
        pushButton_testRejectStreet = new QPushButton(centralwidget);
        pushButton_testRejectStreet->setObjectName("pushButton_testRejectStreet");

        gridLayout->addWidget(pushButton_testRejectStreet, 30, 0, 1, 1);

        pushButton_addCity = new QPushButton(centralwidget);
        pushButton_addCity->setObjectName("pushButton_addCity");

        gridLayout->addWidget(pushButton_addCity, 16, 0, 1, 1);

        label_eingabe = new QLabel(centralwidget);
        label_eingabe->setObjectName("label_eingabe");

        gridLayout->addWidget(label_eingabe, 0, 0, 1, 1);

        pushButton_addStreet = new QPushButton(centralwidget);
        pushButton_addStreet->setObjectName("pushButton_addStreet");

        gridLayout->addWidget(pushButton_addStreet, 18, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 7, 2, 51, 1);

        pushButton_testDrawMapWithCities = new QPushButton(centralwidget);
        pushButton_testDrawMapWithCities->setObjectName("pushButton_testDrawMapWithCities");

        gridLayout->addWidget(pushButton_testDrawMapWithCities, 27, 0, 1, 1);

        pushButton_testSimpleUi = new QPushButton(centralwidget);
        pushButton_testSimpleUi->setObjectName("pushButton_testSimpleUi");

        gridLayout->addWidget(pushButton_testSimpleUi, 24, 0, 1, 1);

        pushButton_DrawCity = new QPushButton(centralwidget);
        pushButton_DrawCity->setObjectName("pushButton_DrawCity");

        gridLayout->addWidget(pushButton_DrawCity, 26, 0, 1, 1);

        pushButton_fillMap = new QPushButton(centralwidget);
        pushButton_fillMap->setObjectName("pushButton_fillMap");

        gridLayout->addWidget(pushButton_fillMap, 17, 0, 1, 1);

        pushButton_testSimpleDrawing = new QPushButton(centralwidget);
        pushButton_testSimpleDrawing->setObjectName("pushButton_testSimpleDrawing");

        gridLayout->addWidget(pushButton_testSimpleDrawing, 25, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        checkBox_showTests = new QCheckBox(centralwidget);
        checkBox_showTests->setObjectName("checkBox_showTests");

        horizontalLayout_3->addWidget(checkBox_showTests);

        pushButton_clearMap = new QPushButton(centralwidget);
        pushButton_clearMap->setObjectName("pushButton_clearMap");

        horizontalLayout_3->addWidget(pushButton_clearMap);


        gridLayout->addLayout(horizontalLayout_3, 8, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        comboBox_endCity = new QComboBox(centralwidget);
        comboBox_endCity->setObjectName("comboBox_endCity");

        horizontalLayout_4->addWidget(comboBox_endCity);

        comboBox_startCity = new QComboBox(centralwidget);
        comboBox_startCity->setObjectName("comboBox_startCity");

        horizontalLayout_4->addWidget(comboBox_startCity);

        pushButton_searchPath = new QPushButton(centralwidget);
        pushButton_searchPath->setObjectName("pushButton_searchPath");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(pushButton_searchPath->sizePolicy().hasHeightForWidth());
        pushButton_searchPath->setSizePolicy(sizePolicy);
        pushButton_searchPath->setMaximumSize(QSize(80, 20));
        QPalette palette;
        QBrush brush(QColor(114, 164, 240, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush);
        QBrush brush1(QColor(0, 38, 11, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush);
        pushButton_searchPath->setPalette(palette);

        horizontalLayout_4->addWidget(pushButton_searchPath);

        label_pathLength = new QLabel(centralwidget);
        label_pathLength->setObjectName("label_pathLength");
        label_pathLength->setMaximumSize(QSize(10000, 1000));

        horizontalLayout_4->addWidget(label_pathLength);


        gridLayout->addLayout(horizontalLayout_4, 1, 2, 1, 1);

        pushButton_testDrawCities = new QPushButton(centralwidget);
        pushButton_testDrawCities->setObjectName("pushButton_testDrawCities");

        gridLayout->addWidget(pushButton_testDrawCities, 22, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 5, 0, 1, 1);

        pushButton_dijkstraTest = new QPushButton(centralwidget);
        pushButton_dijkstraTest->setObjectName("pushButton_dijkstraTest");

        gridLayout->addWidget(pushButton_dijkstraTest, 32, 0, 1, 1);

        pushButton_testAbstractMap = new QPushButton(centralwidget);
        pushButton_testAbstractMap->setObjectName("pushButton_testAbstractMap");

        gridLayout->addWidget(pushButton_testAbstractMap, 31, 0, 1, 1);

        pushButton_testDrawStreets = new QPushButton(centralwidget);
        pushButton_testDrawStreets->setObjectName("pushButton_testDrawStreets");

        gridLayout->addWidget(pushButton_testDrawStreets, 28, 0, 1, 1);

        pushButton_TestDraw = new QPushButton(centralwidget);
        pushButton_TestDraw->setObjectName("pushButton_TestDraw");

        gridLayout->addWidget(pushButton_TestDraw, 23, 0, 1, 1);

        pushButton_testDrawMapWithStreets = new QPushButton(centralwidget);
        pushButton_testDrawMapWithStreets->setObjectName("pushButton_testDrawMapWithStreets");

        gridLayout->addWidget(pushButton_testDrawMapWithStreets, 29, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 33, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_test = new QLineEdit(centralwidget);
        lineEdit_test->setObjectName("lineEdit_test");
        lineEdit_test->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEdit_test);

        pushButton_test = new QPushButton(centralwidget);
        pushButton_test->setObjectName("pushButton_test");

        horizontalLayout->addWidget(pushButton_test);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        pushButton_loadMap = new QPushButton(centralwidget);
        pushButton_loadMap->setObjectName("pushButton_loadMap");

        gridLayout->addWidget(pushButton_loadMap, 19, 0, 1, 1);

        gridLayout->setColumnStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 478, 17));
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
        pushButton_testRejectStreet->setText(QCoreApplication::translate("MainWindow", "TestRejectStreet", nullptr));
        pushButton_addCity->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        label_eingabe->setText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        pushButton_addStreet->setText(QCoreApplication::translate("MainWindow", "Add streets", nullptr));
        pushButton_testDrawMapWithCities->setText(QCoreApplication::translate("MainWindow", "TestDrawMapWithCities", nullptr));
        pushButton_testSimpleUi->setText(QCoreApplication::translate("MainWindow", "TestSimpleUi", nullptr));
        pushButton_DrawCity->setText(QCoreApplication::translate("MainWindow", "Test Draw City", nullptr));
        pushButton_fillMap->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
        pushButton_testSimpleDrawing->setText(QCoreApplication::translate("MainWindow", "TestSimpleDrawing", nullptr));
        checkBox_showTests->setText(QCoreApplication::translate("MainWindow", "Tests anzeigen", nullptr));
        pushButton_clearMap->setText(QCoreApplication::translate("MainWindow", "Clear Map", nullptr));
        comboBox_endCity->setPlaceholderText(QCoreApplication::translate("MainWindow", "Starting City", nullptr));
        comboBox_startCity->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ending City", nullptr));
        pushButton_searchPath->setText(QCoreApplication::translate("MainWindow", "Search Path", nullptr));
        label_pathLength->setText(QCoreApplication::translate("MainWindow", "Distanz:", nullptr));
        pushButton_testDrawCities->setText(QCoreApplication::translate("MainWindow", "TestDrawCities", nullptr));
        pushButton_dijkstraTest->setText(QCoreApplication::translate("MainWindow", "Dijkstra Test", nullptr));
        pushButton_testAbstractMap->setText(QCoreApplication::translate("MainWindow", "TestAbstractMap", nullptr));
        pushButton_testDrawStreets->setText(QCoreApplication::translate("MainWindow", "TestDrawStreets", nullptr));
        pushButton_TestDraw->setText(QCoreApplication::translate("MainWindow", "TestDraw", nullptr));
        pushButton_testDrawMapWithStreets->setText(QCoreApplication::translate("MainWindow", "TestDrawMapWithStreets", nullptr));
        lineEdit_test->setText(QString());
        lineEdit_test->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ihre eingabe", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_test->setToolTip(QCoreApplication::translate("MainWindow", "Come on, push it", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_test->setText(QCoreApplication::translate("MainWindow", "Test Push ", nullptr));
        pushButton_loadMap->setText(QCoreApplication::translate("MainWindow", "Load Map ", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
