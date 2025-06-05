///main.cpp

#include "mainwindow.h"

#include <QApplication>

#include <QFileDialog>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
