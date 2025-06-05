/**
 * @file mainwindow.cpp
 * @brief Implementation of the MainWindow class
 * @author Your Name
 * @date Current Date
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addcitydialog.h"
#include "addstreetdialog.h"
#include "city.h"
#include "dijkstra.h"
#include "ui_addstreetdialog.h" // Might not be needed if dialog.getStartCityComboBox() is used
#include "mapiofileinput.h"
#include <QMessageBox>
#include <QString>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <QFileDialog>
#include <QRegularExpression> // For regular expression validation
#include <QtMath>             // For sqrt

//==============================================================================
// Constructor and Destructor
//==============================================================================

/**
 * _________________________________________________________________________
 *
 * @brief Konstruktor für das Hauptfenster der Anwendung.
 * _________________________________________________________________________
 *
 * Initialisiert das UI, setzt die Szene für die QGraphicsView,
 * stellt den Hintergrund auf Weiß und setzt die anfängliche Fenstergröße.
 * Außerdem werden die Map-Objekte initialisiert.
 * _________________________________________________________________________
 *
 * @param parent Zeiger auf das übergeordnete QWidget (Standard: nullptr)
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // UI-Elemente aus dem Designer initialisieren und mit diesem MainWindow verbinden
    ui->setupUi(this);

    // Neue Grafikszene erstellen, die als Container für grafische Items dient
    // Das 'this' als Parent sorgt dafür, dass die Szene mit dem Fenster mitverwaltet wird
    scene = new QGraphicsScene(this);

    // Die erstellte Szene der QGraphicsView zuweisen, damit sie angezeigt wird
    ui->graphicsView->setScene(scene);

    // Hintergrundfarbe der Szene auf Weiß setzen (Standard ist transparent)
    scene->setBackgroundBrush(Qt::white);

    // Die Größe des Hauptfensters auf 600x500 Pixel festlegen
    resize(600, 500);

    // Map-Objekt erzeugen, um die Kartenlogik zu verwalten
    map = new Map();

    // MapIo-Objekt mit spezifischer NRW-Implementierung initialisieren
    // Dieses Objekt ist zuständig für das Einlesen/Verarbeiten von Kartendaten
    mapIo = new MapIoNrw();
}

// Destroys the MainWindow object and cleans up allocated resources.
MainWindow::~MainWindow()
{
    delete map;
    delete ui;
    delete mapIo;
}

//==============================================================================
// UI Update Methods
//==============================================================================


/**
 * @brief Aktualisiert die Dropdown-Menüs für die Start- und Zielstädte.
 *
 * Diese Funktion leert zuerst die beiden ComboBoxen und füllt sie anschließend
 * mit den Namen aller Städte aus der aktuellen Map. Danach werden die Standard-
 * Auswahlindizes gesetzt (erste Stadt als Start, zweite Stadt als Ziel),
 * sofern genügend Städte vorhanden sind.
 */
void MainWindow::updateCityDropdowns()
{
    // Leere beide Dropdown-Listen, um alte Einträge zu entfernen
    ui->comboBox_startCity->clear();
    ui->comboBox_endCity->clear();

    // Liste aller Städte aus dem Map-Objekt abrufen
    QList<City*> cities = map->getCityList();

    // Für jede Stadt den Namen in beide ComboBoxen hinzufügen
    for (City* city : cities)
    {
        ui->comboBox_startCity->addItem(city->getName());
        ui->comboBox_endCity->addItem(city->getName());
    }

    // Wenn mindestens eine Stadt vorhanden ist, setze die Startstadt auf die erste
    if (ui->comboBox_startCity->count() > 0)
        ui->comboBox_startCity->setCurrentIndex(0);

    // Wenn mindestens zwei Städte vorhanden sind, setze die Zielstadt auf die zweite
    if (ui->comboBox_endCity->count() > 1)
        ui->comboBox_endCity->setCurrentIndex(1);
}



//==============================================================================
// Test Function Slots
//==============================================================================
#pragma region Test Function Slots

/**
 * @brief Slot, der ausgelöst wird, wenn der Test-Button gedrückt wird.
 *
 * Liest den Text aus dem Eingabefeld aus, überprüft, ob es eine Zahl ist.
 * Wenn ja, wird die Zahl um 4 erhöht und ausgegeben, sonst wird der eingegebene
 * Text ausgegeben. Das Ergebnis wird in einer MessageBox angezeigt und zusätzlich
 * im Debug-Output ausgegeben.
 *
 * Außerdem wird ein schwarzes Rechteck mit fester Größe an einer zufälligen
 * Position innerhalb der Szene gezeichnet.
 */
void MainWindow::on_pushButton_test_clicked()
{
    // Debug-Ausgabe, dass der Button gedrückt wurde
    qDebug() << "---->Pushb wurde gedrückt.";

    // Text aus dem Eingabefeld lesen
    QString input = ui->lineEdit_test->text();

    QString output;
    QMessageBox msgBox;

    // Versuche, den Text als Double zu interpretieren
    bool ok = false;
    double d_number = input.toDouble(&ok);

    if (ok) // Falls die Konvertierung erfolgreich war (gültige Zahl)
    {
        // Ausgabe vorbereiten: Zahl um 4 erhöht
        output = QString("Die Zahl %1 um 4 erhöht = %2").arg(d_number).arg(d_number + 4);
        qDebug() << output;
    }
    else // Falls keine gültige Zahl erkannt wurde
    {
        // Ausgabe vorbereiten: Eingelesener Text
        output = QString("Folgendes wurde eingelesen: %1").arg(input);
        qDebug() << output;
    }

    // Ergebnis in einer MessageBox anzeigen
    msgBox.setText(output);
    msgBox.exec();

    // Zufällige Position innerhalb der Szene (600x500) bestimmen
    int randomX = QRandomGenerator::global()->bounded(600);
    int randomY = QRandomGenerator::global()->bounded(500);

    // Größe des Rechtecks
    int width = 10;
    int height = 10;

    // Schwarzes Rechteck an der zufälligen Position in die Szene einfügen
    scene->addRect(randomX, randomY, width, height,
                   QPen(Qt::black), QBrush(Qt::black, Qt::SolidPattern));
}


/**
 * @brief Slot, der ausgelöst wird, wenn der "Draw City"-Button gedrückt wird.
 *
 * Diese Funktion erstellt zwei City-Objekte mit festen Positionen und
 * zeichnet sie in die aktuell verwendete QGraphicsScene.
 *
 * Dabei werden Debug-Informationen ausgegeben, um den Aufruf sichtbar zu machen.
 */
void MainWindow::on_pushButton_DrawCity_clicked()
{
    // Debug-Ausgabe zur Bestätigung, dass der Button-Klick erkannt wurde
    qDebug() << "--->Test Draw City was clicked.\n";

    // Erstelle zwei City-Objekte mit Namen und (x,y)-Positionen
    City Berlin("Berlin", 100, 150);
    City Koeln("Koeln", 300, 300);

    // Zeichne die Städte auf die Szene, die in der Klasse als 'scene' gespeichert ist
    Berlin.draw(*scene);
    Koeln.draw(*scene);
}


/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Draw"-Button gedrückt wird.
 *
 * Erzeugt zwei neue City-Objekte mit zufälligen Positionen innerhalb eines
 * vorgegebenen Bereichs. Fügt diese Städte der Map hinzu, löscht die aktuelle
 * Zeichnung in der GraphicsView und zeichnet anschließend die komplette Map neu.
 */
void MainWindow::on_pushButton_TestDraw_clicked()
{
    // Erzeuge zwei Städte mit Namen und zufälligen (x,y)-Koordinaten
    City* c1 = new City("Berlin", QRandomGenerator::global()->bounded(600), QRandomGenerator::global()->bounded(500));
    City* c2 = new City("Hamburg", QRandomGenerator::global()->bounded(600), QRandomGenerator::global()->bounded(500));

    // Füge die neu erzeugten Städte der Map hinzu
    map->addCity(c1);
    map->addCity(c2);

    // Lösche alle bisherigen Zeichnungen in der Scene der GraphicsView
    ui->graphicsView->scene()->clear();

    // Zeichne die gesamte Map, inklusive der neu hinzugefügten Städte
    map->draw(*ui->graphicsView->scene());
}

/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Simple UI"-Button gedrückt wird.
 *
 * Liest den aktuellen Text aus dem Eingabefeld `lineEdit_test` aus,
 * formatiert ihn mit einem vorgegebenen Muster und gibt die
 * resultierende Zeichenkette in der Debug-Konsole aus.
 */
void MainWindow::on_pushButton_testSimpleUi_clicked()
{
    // Muster-String mit Platzhalter für den Benutzereingabetext
    QString pattern = "The user's input: %1";

    // Eingabetext aus dem LineEdit holen und in das Muster einsetzen
    QString s = pattern.arg(ui->lineEdit_test->text());

    // Ausgabe des formatierten Strings in der Debug-Konsole
    qDebug() << s;
}

/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Simple Drawing"-Button gedrückt wird.
 *
 * Zeichnet ein festes Rechteck mit der Größe 50x100 an der Position (50, 20)
 * in die aktuell verwendete QGraphicsScene.
 */
void MainWindow::on_pushButton_testSimpleDrawing_clicked()
{
    // Fügt ein Rechteck mit (x=50, y=20, Breite=50, Höhe=100) zur Szene hinzu
    scene->addRect(50, 20, 50, 100);
}


/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Draw Cities"-Button gedrückt wird.
 *
 * Erstellt eine vordefinierte Stadt mit festen Koordinaten, zeichnet diese
 * auf die aktuelle Szene und aktualisiert anschließend die Dropdown-Listen
 * mit den verfügbaren Städten.
 */
void MainWindow::on_pushButton_testDrawCities_clicked()
{
    // Erstelle eine Stadt namens "city c1" an der Position (20, 50)
    City c1("city c1", 20, 50);

    // Zeichne die Stadt in die aktuelle Szene
    c1.draw(*scene);

    // Aktualisiere die Dropdown-Menüs für Start- und Zielstadt
    updateCityDropdowns();
}


/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Draw Map With Cities"-Button gedrückt wird.
 *
 * Erstellt mehrere Städte mit festen Koordinaten, fügt sie der Map hinzu
 * und zeichnet anschließend die komplette Map inklusive der Städte in die Szene.
 */
void MainWindow::on_pushButton_testDrawMapWithCities_clicked()
{
    // Erstelle eine Liste für City-Zeiger
    QVector<City*> citylist;

    // Neue Städte mit Namen und Positionen erzeugen und der Liste hinzufügen
    citylist.append(new City("City A", 20, 50));
    citylist.append(new City("City B", 100, 100));
    citylist.append(new City("City C", 200, 150));

    // Jede Stadt aus der Liste der Map hinzufügen
    for (City* cursor : citylist)
        map->addCity(cursor);

    // Zeichne die gesamte Map, inklusive aller hinzugefügten Städte, auf die Szene
    map->draw(*scene);
}


/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Draw Streets"-Button gedrückt wird.
 *
 * Erstellt zwei Stadtobjekte mit festen Positionen, zeichnet diese auf die Szene
 * und verbindet sie mit einer Straße, die ebenfalls gezeichnet wird.
 */
void MainWindow::on_pushButton_testDrawStreets_clicked()
{
    // Erstelle zwei Städte mit Namen und Koordinaten
    City Berlin("Berlin", 100, 150);
    City Koeln("Koeln", 300, 300);

    // Zeichne die Städte in die Szene
    Berlin.draw(*scene);
    Koeln.draw(*scene);

    // Erstelle eine Straße, die Berlin und Koeln verbindet
    Street s(&Berlin, &Koeln);

    // Zeichne die Straße in die Szene
    s.draw(*scene);
}

/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Draw Map With Streets"-Button gedrückt wird.
 *
 * Erstellt mehrere Städte und Straßen zwischen ihnen,
 * fügt die Städte der Map hinzu, zeichnet die Straßen und anschließend die komplette Map.
 */
void MainWindow::on_pushButton_testDrawMapWithStreets_clicked()
{
    // Erstelle eine Liste für City-Zeiger
    QVector<City*> citylist;

    // Neue Städte mit Namen und Positionen erzeugen
    City* c1 = new City("City A", 20, 50);
    City* c2 = new City("City B", 100, 50);
    City* c3 = new City("City C", 200, 150);

    // Städte der Liste hinzufügen
    citylist.append(c1);
    citylist.append(c2);
    citylist.append(c3);

    // Straßen zwischen den Städten erstellen und zeichnen
    Street s1(c1, c2);
    Street s2(c1, c3);
    s1.draw(*scene);
    s2.draw(*scene);

    // Städte der Map hinzufügen
    for (City* cursor : citylist)
        map->addCity(cursor);

    // Ganze Map in der Szene zeichnen (inklusive der Städte)
    map->draw(*scene);
}

/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Reject Street"-Button gedrückt wird.
 *
 * Testet das Hinzufügen einer Straße zu einer Map, bei der eine Stadt nicht zur Map gehört.
 * Erwartet, dass das Hinzufügen der Straße abgelehnt wird, und gibt das Ergebnis im Debug aus.
 */
void MainWindow::on_pushButton_testRejectStreet_clicked()
{
    // Erstelle eine neue Map-Instanz für den Test
    Map* test = new Map();

    // Erstelle eine gültige Stadt und füge sie der Map hinzu
    City* allowedCity = new City("Zulässige Stadt", 100, 100);
    test->addCity(allowedCity);

    // Erstelle eine ungültige Stadt, die nicht der Map hinzugefügt wird
    City* invalidCity = new City("Invalid", 200, 200);

    // Versuche, eine Straße zwischen einer gültigen und einer ungültigen Stadt hinzuzufügen
    Street* invalidStreet = new Street(allowedCity, invalidCity);

    // Füge die Straße der Map hinzu; sollte fehlschlagen
    bool result = test->addStreet(invalidStreet);

    // Ausgabe des Testergebnisses in die Debug-Konsole
    if (!result)
        qDebug() << "testRejectStreet: Straße wurde korrekt abgelehnt.";
    else
        qDebug() << "testRejectStreet: Fehler! Straße wurde hinzugefügt, obwohl sie nicht sollte.";

    // Bereinige alle dynamisch allokierten Objekte, um Speicherlecks zu vermeiden
    delete test;
    delete allowedCity;
    delete invalidCity;
    delete invalidStreet;
}

/**
 * @brief Slot, der ausgelöst wird, wenn der "Test Abstract Map"-Button gedrückt wird.
 *
 * Führt verschiedene Tests auf der Map-Klasse durch, darunter:
 * - Hinzufügen von Straßen ohne und mit vorhandenen Städten,
 * - Suche von Städten,
 * - Ermittlung der Gegenstadt einer Straße,
 * - Berechnung der Straßenlänge,
 * - Abruf der Straßenliste für eine Stadt.
 *
 * Gibt Zwischenergebnisse und Fehler in der Debug-Konsole aus.
 */
void MainWindow::on_pushButton_testAbstractMap_clicked()
{
    Map testMap;

    // Erstelle Städte und Straßen für die Tests
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";

    // Test: Hinzufügen einer Straße ohne die zugehörigen Städte
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not be added if cities have not been added.";
        }
    }

    // Test: Hinzufügen einer Straße nach dem Hinzufügen der Städte
    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    // Test: Suche von Städten nach Namen
    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found nullptr should be returned.";
    }

    // Füge weitere Stadt und Straße für spätere Tests hinzu
    testMap.addCity(c);
    testMap.addStreet(s2);

    // Test: Ermittlung der Gegenstadt an einer Straße
    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map->getOppositeCity(s, c); // 'map' hier vorausgesetzt initialisiert und enthält s und c
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be nullptr.";
    }

    // Test: Berechnung der Straßenlänge
    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // Vergleiche mit 5% Toleranz
        if (l < expectedLength * 0.95 || l > expectedLength * 1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";
    }

    // Test: Abruf der Straßenliste für eine Stadt
    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);

        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";

    // Speicherbereinigung der dynamisch erzeugten Objekte
    delete a;
    delete b;
    delete c;
    delete s;
    delete s2;
}

/**
 * @brief Slot, der ausgelöst wird, wenn die Checkbox "showTests" geklickt wird.
 *
 * Zeigt oder versteckt alle Test-Buttons im UI, je nachdem, ob die Checkbox aktiviert ist.
 */
void MainWindow::on_checkBox_showTests_clicked()
{
    qDebug() << "Checkbox wurde geklickt!";

    if (ui->checkBox_showTests->isChecked())
    {
        // Alle Test-Buttons anzeigen
        ui->pushButton_TestDraw->show();
        ui->pushButton_testSimpleUi->show();
        ui->pushButton_testSimpleDrawing->show();
        ui->pushButton_testDrawCities->show();
        ui->pushButton_testDrawMapWithCities->show();
        ui->pushButton_testRejectStreet->show();
        ui->pushButton_testDrawMapWithStreets->show();
        ui->pushButton_testDrawStreets->show();
        ui->pushButton_DrawCity->show();
        ui->pushButton_testAbstractMap->show();
        ui->pushButton_dijkstraTest->show();

        qDebug() << "Tests eingeblendet";
    }
    else
    {
        // Alle Test-Buttons ausblenden
        ui->pushButton_TestDraw->hide();
        ui->pushButton_testSimpleUi->hide();
        ui->pushButton_testSimpleDrawing->hide();
        ui->pushButton_testDrawCities->hide();
        ui->pushButton_testDrawMapWithCities->hide();
        ui->pushButton_testRejectStreet->hide();
        ui->pushButton_testDrawMapWithStreets->hide();
        ui->pushButton_testDrawStreets->hide();
        ui->pushButton_DrawCity->hide();
        ui->pushButton_testAbstractMap->hide();
        ui->pushButton_dijkstraTest->hide();

        qDebug() << "Tests ausgeblendet";
    }
}

/**
 * @brief Slot für den "Dijkstra Test" Button.
 *
 * Erzeugt zwei Städte und eine Straße zwischen ihnen,
 * fügt diese zur Map hinzu, zeichnet sie und startet anschließend
 * eine Dijkstra-Suche nach dem kürzesten Weg zwischen den beiden Städten.
 *
 * Das Ergebnis wird in der Debug-Konsole ausgegeben.
 */
void MainWindow::on_pushButton_dijkstraTest_clicked()
{
    // Erstelle Start- und Zielstadt mit festen Koordinaten
    City* a = new City("Startstadt", 0.0, 0.0);
    City* b = new City("Zielstadt", 10.0, 10.0);

    // Füge Städte zur Map hinzu
    map->addCity(a);
    map->addCity(b);

    // Erstelle eine Straße zwischen Start- und Zielstadt
    Street* street = new Street(a, b);
    map->addStreet(street);

    // Zeichne die Map (Städte und Straßen) auf der Szene
    map->draw(*scene);

    // Starte die Dijkstra-Suche nach dem kürzesten Pfad
    QVector<Street*> path = Dijkstra::search(*map, "Startstadt", "Zielstadt");

    // Prüfe, ob ein Pfad gefunden wurde und gib das Ergebnis aus
    if (path.isEmpty())
        qDebug() << "Kein Weg gefunden von Startstadt nach Zielstadt";
    else
    {
        qDebug() << "Gefundener Weg:";
        for (Street* s : path)
        {
            qDebug() << s->getCity_A()->getName() << "<->" << s->getCity_B()->getName();
        }
    }
}


#pragma endregion // Test Function Slots



///////////////////////////////////////////////////////////////////////////////////
//==============================================================================
// Main Functionality Slots
//==============================================================================
////////////////////////////////////////////////////////////////////////////////////
#pragma region Main Functionality Slots


/**
 * @brief Slot für das Beenden der Anwendung über das Exit-Menü.
 *
 * Schließt das Hauptfenster und beendet somit die Anwendung.
 */
void MainWindow::on_actionExit_triggered()
{
    qDebug() << "----->Exit was triggered.\n ";
    close();  // Schließt das Hauptfenster
}

/**
 * @brief Slot, der ausgelöst wird, wenn die "About"-Aktion im Menü aktiviert wird.
 *
 * Zeigt ein Informationsfenster (MessageBox) mit Details über das Programm an.
 */
void MainWindow::on_actionAbout_triggered()
{
    qDebug() << "--->About was triggered.\n ";
    QMessageBox::about(this, "Über dieses Programm", "Dies ist eine einfache Qt-Anwendung mit Info-Menü.");
}

/**
 * @brief Slot für den Button "Stadt hinzufügen".
 *
 * Öffnet einen Dialog zur Eingabe einer neuen Stadt. Führt eine Validierung der Eingaben durch,
 * um sicherzustellen, dass der Name nicht leer ist, nur aus Buchstaben besteht, die Koordinaten
 * gültige Zahlen sind und der Stadtname noch nicht existiert. Bei Fehlern wird der Dialog erneut angezeigt.
 * Nach erfolgreicher Eingabe wird die neue Stadt zur Map hinzugefügt, gezeichnet und die Dropdowns aktualisiert.
 */
void MainWindow::on_pushButton_addCity_clicked()
{
    while (true) // Schleife, um den Dialog bei Validierungsfehlern erneut anzuzeigen
    {
        AddCityDialog dialog(this);
        if (dialog.exec() != QDialog::Accepted)
        {
            qDebug() << "Stadt hinzufügen abgebrochen.";
            return; // Nutzer hat den Dialog abgebrochen
        }

        // Werte aus dem Dialog auslesen
        QString name = dialog.getName().trimmed();
        QString xStr = dialog.getX();
        QString yStr = dialog.getY();

        // Koordinaten validieren (konvertieren in int)
        bool okX, okY;
        int x = xStr.toInt(&okX);
        int y = yStr.toInt(&okY);

        // Validierung: Name darf nicht leer sein
        if (name.isEmpty())
        {
            QMessageBox::warning(this, "Fehler", "Der Name darf nicht leer sein.");
            continue; // Dialog erneut anzeigen
        }

        // Validierung: Name darf nur Buchstaben enthalten
        QRegularExpression re("^[A-Za-z]+$");
        if (!re.match(name).hasMatch())
        {
            QMessageBox::warning(this, "Fehler", "Der Name darf nur aus Buchstaben bestehen.");
            continue; // Dialog erneut anzeigen
        }

        // Validierung: Koordinaten müssen gültige Zahlen sein
        if (!okX || !okY)
        {
            QMessageBox::warning(this, "Fehler", "Ungültige Koordinaten! Bitte gültige Zahlen eingeben.");
            continue; // Dialog erneut anzeigen
        }

        // Validierung: Stadtname darf nicht schon existieren
        if (map->findCity(name))
        {
            QMessageBox::warning(this, "Fehler", "Stadtname existiert bereits!");
            continue; // Dialog erneut anzeigen
        }

        // Neue Stadt zur Map hinzufügen und zeichnen
        City* newCity = new City(name, x, y);
        map->addCity(newCity);
        newCity->draw(*scene);

        // Dropdown-Listen mit neuer Stadt aktualisieren
        updateCityDropdowns();

        qDebug() << "Neue Stadt hinzugefügt:" << name;
        break; // Eingabe erfolgreich, Schleife beenden
    }
}

/**
 * @brief Slot für den Button "Map füllen".
 *
 * Löscht zunächst alle bestehenden Daten in der Map,
 * füllt die Map anschließend mit Daten über das MapIo-Objekt,
 * zeichnet die Map neu und aktualisiert die Stadtauswahl in den Dropdowns.
 */
void MainWindow::on_pushButton_fillMap_clicked()
{
    map->clear();               // Bestehende Kartendaten löschen
    mapIo->fillMap(*map);       // Map mit Daten füllen (z.B. aus Datei oder Datenquelle)
    map->draw(*scene);          // Karte im GraphicsScene neu zeichnen
    updateCityDropdowns();      // Dropdown-Listen mit Städten aktualisieren
}

/**
 * @brief Slot für den Button "Karte löschen".
 *
 * Löscht alle visuellen Elemente aus der Szene und
 * entfernt alle Städte und Straßen aus der internen Map-Instanz,
 * indem die aktuelle Map gelöscht und eine neue leere Map erzeugt wird.
 * Aktualisiert anschließend die Stadtauswahl-Dropdowns und setzt
 * das Label für die Straßenlänge zurück.
 */
void MainWindow::on_pushButton_clearMap_clicked()
{
    scene->clear(); // Alle visuellen Elemente aus der Grafik-Szene entfernen

    // Vorhandene Map löschen und neu erstellen, um Daten komplett zu entfernen
    if (map)
    {
        delete map;
        map = new Map();
    }

    updateCityDropdowns(); // Dropdowns aktualisieren, da keine Städte mehr vorhanden sind
    ui->label_pathLength->setText("Straßenlänge: -"); // Anzeige der Straßenlänge zurücksetzen

    qDebug() << "Alle Karten-Daten komplett gelöscht";
}

/**
 * @brief Slot für den Button "Weg suchen".
 *
 * Führt eine Dijkstra-Suche zwischen der gewählten Start- und Zielstadt durch,
 * zeichnet den gefundenen kürzesten Weg in der Szene und zeigt die Gesamtlänge an.
 *
 * Validiert die Eingaben, zeigt Warnungen bei Fehlern und aktualisiert die GUI entsprechend.
 */
void MainWindow::on_pushButton_searchPath_clicked()
{
    scene->clear();            // Vorherige Zeichnungen (Pfad) löschen
    map->draw(*scene);         // Grundkarte (Städte und Straßen) neu zeichnen

    QString startName = ui->comboBox_startCity->currentText();
    QString endName = ui->comboBox_endCity->currentText();

    // Validierung: Start- und Zielstadt müssen ausgewählt sein
    if (startName.isEmpty() || endName.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte Start- und Zielstadt auswählen.");
        return;
    }

    // Validierung: Start und Ziel dürfen nicht identisch sein
    if (startName == endName) {
        QMessageBox::warning(this, "Fehler", "Start- und Zielstadt dürfen nicht identisch sein.");
        return;
    }

    // Dijkstra-Suche ausführen
    QVector<Street*> path = Dijkstra::search(*map, startName, endName);

    if (path.isEmpty()) {
        QMessageBox::information(this, "Kein Weg", "Es konnte kein Weg gefunden werden.");
        ui->label_pathLength->setText("Distanz: Kein Weg");
        return;
    }

    // Gefundenen Pfad in der Szene rot zeichnen und Gesamtlänge berechnen
    double totalLength = 0.0;
    for (Street* street : path) {
        street->drawRed(*scene);   // Rot markierte Straße zeichnen (muss in Street implementiert sein)
        totalLength += map->getLength(street);
    }

    qDebug() << "Kürzeste Strecke von" << startName << "nach" << endName << ":" << totalLength << "Einheiten.";
    ui->label_pathLength->setText(QString("Distanz: %1 km").arg(totalLength, 0, 'f', 2)); // Anzeige der Gesamtlänge
}

/**
 * @brief Slot zum Hinzufügen einer Straße zwischen zwei Städten.
 *
 * Öffnet einen Dialog, in dem Start- und Zielstadt ausgewählt werden können.
 * Führt Validierungen durch (Existenz der Städte, Unterschiedlichkeit der Städte).
 * Berechnet die Länge der Straße, fügt sie der Map hinzu und zeichnet sie.
 * Aktualisiert die GUI-Elemente entsprechend.
 */
void MainWindow::on_pushButton_addStreet_clicked()
{
    while (true) // Schleife, um den Dialog bei Validierungsfehlern erneut anzuzeigen
    {
        AddStreetDialog dialog(this);

        // Städte in die Dropdowns des Dialogs einfügen
        dialog.getStartCityComboBox()->clear();
        dialog.getEndCityComboBox()->clear();
        for (City* city : map->getCityList()) {
            dialog.getStartCityComboBox()->addItem(city->getName());
            dialog.getEndCityComboBox()->addItem(city->getName());
        }

        // Dialog anzeigen und abbrechen, falls Nutzer nicht bestätigt
        if (dialog.exec() != QDialog::Accepted)
        {
            qDebug() << "Straße hinzufügen abgebrochen.";
            return;
        }

        QString startName = dialog.getStartCityComboBox()->currentText();
        QString endName = dialog.getEndCityComboBox()->currentText();

        City* startCity = map->findCity(startName);
        City* endCity = map->findCity(endName);

        // Validierung: Städte müssen existieren
        if (!startCity || !endCity)
        {
            QMessageBox::warning(this, "Fehler", "Eine der ausgewählten Städte wurde nicht gefunden.");
            continue; // Dialog erneut zeigen
        }

        // Validierung: Start und Ziel dürfen nicht gleich sein
        if (startCity == endCity)
        {
            QMessageBox::warning(this, "Fehler", "Start- und Zielstadt müssen unterschiedlich sein.");
            continue; // Dialog erneut zeigen
        }

        // Länge der Straße berechnen (euklidische Distanz)
        double dx = startCity->getposX() - endCity->getposX();
        double dy = startCity->getposY() - endCity->getposY();
        double length = qSqrt(dx*dx + dy*dy);

        // Neue Straße erstellen, hinzufügen und zeichnen
        Street* newStreet = new Street(startCity, endCity);
        map->addStreet(newStreet);
        newStreet->draw(*scene);

        // Länge anzeigen
        ui->label_pathLength->setText(QString("Straßenlänge: %1").arg(length, 0, 'f', 2));

        qDebug() << "Neue Straße hinzugefügt zwischen" << startName << "und" << endName << "mit Länge:" << length;
        break; // Erfolgreich, Schleife beenden
    }

    updateCityDropdowns(); // Dropdowns ggf. aktualisieren (z.B. für Pfadsuche)
}



/**
 * @brief Lädt eine Karte aus zwei ausgewählten Textdateien (Städte und Straßen).
 *
 * Diese Funktion öffnet zwei Dateidialoge zur Auswahl von Stadtdaten und Straßendaten.
 * Anschließend wird die bisherige Karte gelöscht, eine neue Karte erstellt und
 * mit den geladenen Daten gefüllt. Danach wird die Karte auf der Zeichenfläche dargestellt.
 * Der Nutzer wird gefragt, ob auch die Straßen gezeichnet werden sollen.
 * Abschließend werden die Dropdown-Menüs mit den neuen Städten aktualisiert.
 *
 * @note Diese Funktion reagiert auf den Klick des Buttons "Load Map".
 */
void MainWindow::on_pushButton_loadMap_clicked()
{
    qDebug() << "Load map button clicked";

    // Select city file
    QMessageBox::information(this, "Bitte City Datei auswählen", "Bitte wählen Sie die Datei mit den Städten aus.");
    QString cityFile = QFileDialog::getOpenFileName(this, "Städtedatei auswählen", "C:/Streetplanner/txtFiles", "Textdateien (*.txt)");
    if (cityFile.isEmpty()) return; // User cancelled

    // Select street file
    QMessageBox::information(this, "Bitte Street Datei auswählen", "Bitte wählen Sie die Datei mit den Straßen aus.");
    QString streetFile = QFileDialog::getOpenFileName(this, "Straßendatei auswählen", "C:/Streetplanner/txtFiles", "Textdateien (*.txt)");
    if (streetFile.isEmpty()) return; // User cancelled

    // Clear old map and create a new one
    if (map) delete map;
    map = new Map();

    // Load map from files
    MapIoFileinput* loader = new MapIoFileinput(cityFile, streetFile);
    loader->fillMap(*map); // Fill the map with data from files

    // Clear scene and draw only cities initially
    scene->clear();
    map->draw(*scene); // Map::draw typically draws cities.

    // Ask user if streets should be drawn
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Straßen zeichnen?",
                                  "Möchten Sie die Straßen auf der Karte anzeigen?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Draw streets, avoiding duplicates (as streets are part of two cities' street lists)
        QSet<Street*> drawnStreets;
        for (City* city : map->getCityList()) {
            QVector<Street*> streets = map->getStreetList(city);
            for (Street* street : streets) {
                if (!drawnStreets.contains(street)) {
                    street->draw(*scene);
                    drawnStreets.insert(street);
                }
            }
        }
        qDebug() << "Straßen wurden gezeichnet";
    } else {
        qDebug() << "Straßen wurden nicht gezeichnet";
    }

    QMessageBox::information(this, "Fertig", "Karte erfolgreich geladen.");
    delete loader; // Clean up loader object

    updateCityDropdowns(); // Update dropdowns with loaded cities
}

#pragma endregion // Main Functionality Slots
