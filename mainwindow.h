
/**
 * @file mainwindow.h
 * @brief Header-Datei für die MainWindow-Klasse
 * @author japh
 * @date 5.5.15
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "map.h"
#include "mapio.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Hauptfenster-Klasse der Anwendung
 *
 * Diese Klasse stellt das Hauptfenster der Kartenanwendung dar und verwaltet
 * die Benutzeroberfläche für die Karten-, Stadt- und Straßenverwaltung.
 * Sie erbt von QMainWindow und bietet verschiedene Funktionen zum Testen,
 * Zeichnen und Verwalten von Karten.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor der MainWindow-Klasse
     * @param parent Zeiger auf das übergeordnete Widget (Standard: nullptr)
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruktor der MainWindow-Klasse
     *
     * Gibt alle verwendeten Ressourcen frei und räumt das UI auf.
     */
    ~MainWindow();

    /**
     * @brief Aktualisiert die Dropdown-Listen für Städte
     *
     * Diese Methode aktualisiert alle Dropdown-Menüs in der Benutzeroberfläche,
     * die Städte anzeigen, um die neuesten verfügbaren Städte zu reflektieren.
     */
    void updateCityDropdowns();

private slots:
    void on_pushButton_test_clicked();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_pushButton_DrawCity_clicked();
    void on_pushButton_TestDraw_clicked();
    void on_pushButton_testSimpleUi_clicked();
    void on_pushButton_testSimpleDrawing_clicked();
    void on_pushButton_testDrawCities_clicked();
    void on_pushButton_testDrawMapWithCities_clicked();
    void on_pushButton_testDrawStreets_clicked();
    void on_pushButton_testDrawMapWithStreets_clicked();
    void on_pushButton_testRejectStreet_clicked();
    void on_pushButton_testAbstractMap_clicked();
    void on_checkBox_showTests_clicked();
    void on_pushButton_dijkstraTest_clicked();
    void on_pushButton_addCity_clicked();
    void on_pushButton_fillMap_clicked();
    void on_pushButton_clearMap_clicked();
    void on_pushButton_searchPath_clicked();
    void on_pushButton_addStreet_clicked();
    void on_pushButton_loadMap_clicked();

private:
    /**
     * @brief Zeiger auf das UI-Objekt
     *
     * Verwaltet alle UI-Elemente des Hauptfensters.
     */
    Ui::MainWindow *ui;

    /**
     * @brief Zeiger auf die Grafik-Szene
     *
     * QGraphicsScene für die Darstellung der Karte und grafischen Elemente.
     */
    QGraphicsScene *scene;

    /**
     * @brief Zeiger auf das Karten-Objekt
     *
     * Verwaltet die Kartendaten, Städte und Straßen.
     */
    Map *map;

    /**
     * @brief Zeiger auf das MapIo-Objekt
     *
     * Verwaltet das Laden und Speichern von Kartendaten.
     */
    MapIo *mapIo;
};

#endif // MAINWINDOW_H
