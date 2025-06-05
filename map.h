#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QList>
#include <QGraphicsScene>
#include "city.h"
#include "abstractmap.h"

/**
 * @class Map
 * @brief Repräsentiert eine Landkarte mit Städten und Straßen.
 *
 * Diese Klasse implementiert eine Karte, die Städte (City-Objekte) und Straßen (Street-Objekte)
 * verwaltet. Sie ermöglicht das Hinzufügen, Finden und Zeichnen von Städten und Straßen innerhalb
 * einer grafischen Szene (QGraphicsScene).
 *
 * Die Map-Klasse erbt von AbstractMap und implementiert dort definierte virtuelle Methoden.
 */
class Map: public AbstractMap
{
private:
    /// Liste aller Städte auf der Karte.
    /// QList ist eine Qt-Datenstruktur ähnlich zu std::vector, hier mit Zeigern auf City-Objekte.
    QList<City*> p_cities;

    /// Liste aller Straßen auf der Karte.
    /// Die Straßen verbinden die Städte und werden ebenfalls über Zeiger verwaltet.
    QList<Street*> p_streets;

public:
    /**
     * @brief Konstruktor der Map-Klasse.
     * Initialisiert eine neue leere Karte ohne Städte oder Straßen.
     */
    Map();

    /**
     * @brief Destruktor der Map-Klasse.
     * Gibt belegte Ressourcen frei und sorgt für sauberes Aufräumen.
     */
    ~Map();

    /**
     * @brief Fügt eine Stadt zur Karte hinzu.
     *
     * @param city Zeiger auf das City-Objekt, das hinzugefügt werden soll.
     *
     * Diese Methode erweitert die interne Städtesammlung um die angegebene Stadt.
     */
    void addCity(City* city) override;

    /**
     * @brief Zeichnet die Karte in einer QGraphicsScene.
     *
     * @param scene Referenz auf die grafische Szene, in der die Karte dargestellt wird.
     *
     * Die Methode iteriert über alle Städte und Straßen und fügt deren grafische Repräsentation
     * zur Szene hinzu, damit sie sichtbar werden.
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Entfernt alle Städte und Straßen aus der Karte.
     *
     * Setzt die interne Speicherung zurück, sodass die Karte wieder leer ist.
     */
    void clear();

    /**
     * @brief Fügt eine Straße zwischen zwei Städten zur Karte hinzu.
     *
     * @param street Zeiger auf das Street-Objekt, das hinzugefügt werden soll.
     * @return true, wenn die Straße erfolgreich hinzugefügt wurde, false sonst.
     *
     * Diese Methode erweitert die interne Straßensammlung um die angegebene Straße.
     * Sie überschreibt die virtuelle Methode von AbstractMap.
     */
    bool addStreet(Street*) override;

    /**
     * @brief Sucht eine Stadt anhand ihres Namens.
     *
     * @param cityName Name der gesuchten Stadt.
     * @return Zeiger auf die Stadt, wenn gefunden, sonst nullptr.
     *
     * Diese Methode durchsucht die Liste der Städte nach einer Stadt mit dem angegebenen Namen.
     */
    City* findCity(const QString cityName) const override;

    /**
     * @brief Gibt die Liste aller Städte auf der Karte zurück.
     *
     * @return QList mit Zeigern auf alle City-Objekte.
     */
    QList<City*> getCityList() const;

    /**
     * @brief Gibt alle Straßen zurück, die mit einer bestimmten Stadt verbunden sind.
     *
     * @param city Zeiger auf die Stadt, deren Straßen gesucht werden.
     * @return QVector mit Zeigern auf Street-Objekte, die die Stadt verbinden.
     */
    QVector<Street*> getStreetList(const City* city) const override;

    /**
     * @brief Findet die Stadt am gegenüberliegenden Ende einer Straße.
     *
     * @param street Zeiger auf die Straße.
     * @param city Zeiger auf eine der beiden Städte, die die Straße verbindet.
     * @return Zeiger auf die Stadt am anderen Ende der Straße.
     *
     * Diese Methode wird verwendet, um die Nachbarstadt einer gegebenen Stadt über eine Straße zu bestimmen.
     */
    City* getOppositeCity(const Street* street, const City* city) const override;

    /**
     * @brief Berechnet die Länge einer Straße.
     *
     * @param street Zeiger auf das Street-Objekt.
     * @return Länge der Straße als double.
     *
     * Die Methode bestimmt die Distanz zwischen den beiden Städten, die durch die Straße verbunden sind.
     */
    double getLength(const Street* street) const override;

};

#endif // MAP_H
