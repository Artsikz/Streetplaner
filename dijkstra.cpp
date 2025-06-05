#include "dijkstra.h"
#include <QDebug>

/**
 * @brief Helper structure used internally by the Dijkstra algorithm
 *
 * Contains a pointer to a city, the current distance from the start city,
 * and a pointer to the shortest street (edge) used to reach this city.
 */
class Tuppel
{
public:
    City* city;               ///< Pointer to the city
    double distance;          ///< Current distance from the start city
    Street* shortestWay;      ///< Pointer to the shortest street leading here
};

/**
 * @brief Executes Dijkstra's algorithm to find the shortest path between two cities
 *
 * @param map Reference to the map containing all cities and streets
 * @param start Name of the starting city
 * @param target Name of the target city
 * @return QVector<Street*> List of streets forming the shortest path
 */
QVector<Street*> Dijkstra::search(const AbstractMap &map, QString start, QString target)
{
    // === Initialisierung: Start- und Zielstadt abrufen ===
    City* startPointer = map.findCity(start);
    City* targetPointer = map.findCity(target);
    if (startPointer == nullptr || targetPointer == nullptr)
    {
        qDebug() << "Dijkstra: Cities not found";
        return QVector<Street*>();  // Leere Liste zurückgeben
    }

    // === Definition der Datenstrukturen ===
    QVector<Tuppel> green;         // Bereits verarbeitete Knoten
    QVector<Tuppel> yellow;        // Knoten in Bearbeitung

    // Startknoten initialisieren
    Tuppel temp = {startPointer, 0, nullptr};
    yellow.push_back(temp);

    // === Hauptalgorithmus ===
    while (!yellow.empty())
    {
        // Suche nach dem Knoten mit der kleinsten Distanz
        Tuppel edgeToProcessData;
        QVector<Tuppel>::iterator edgeToProcess = yellow.begin();
        for (QVector<Tuppel>::iterator it = yellow.begin(); it != yellow.end(); ++it)
        {
            if (it->distance < edgeToProcess->distance)
            {
                edgeToProcess = it;
            }
        }
        edgeToProcessData = *edgeToProcess;
        green.push_back(*edgeToProcess);     // Knoten endgültig verarbeiten
        yellow.erase(edgeToProcess);         // Aus „yellow“ entfernen

        // Nachfolger ermitteln (benachbarte Städte über Straßen)
        QVector<Street*> streets = map.getStreetList(edgeToProcessData.city);
        QVector<Tuppel> successorList;
        for (QVector<Street*>::const_iterator it = streets.begin(); it != streets.end(); ++it)
        {
            temp.city = map.getOppositeCity(*it, edgeToProcessData.city);
            temp.distance = map.getLength(*it);
            temp.shortestWay = *it;
            successorList.push_back(temp);
        }

        // === Verarbeitung jedes Nachfolgers ===
        for (QVector<Tuppel>::const_iterator successor = successorList.begin(); successor != successorList.end(); ++successor)
        {
            bool found = false;

            // Überprüfen, ob Nachfolger bereits in „green“ ist
            for (QVector<Tuppel>::iterator it = green.begin(); it != green.end(); ++it)
            {
                if (successor->city == it->city)
                {
                    found = true;
                    if (edgeToProcessData.distance + successor->distance < it->distance)
                    {
                        it->distance = edgeToProcessData.distance + successor->distance;
                        it->shortestWay = successor->shortestWay;
                    }
                }
            }

            // Überprüfen, ob Nachfolger bereits in „yellow“ ist
            for (QVector<Tuppel>::iterator it = yellow.begin(); it != yellow.end(); ++it)
            {
                if (successor->city == it->city)
                {
                    found = true;
                    if (edgeToProcessData.distance + successor->distance < it->distance)
                    {
                        it->distance = edgeToProcessData.distance + successor->distance;
                        it->shortestWay = successor->shortestWay;
                    }
                }
            }

            // Wenn die Stadt noch nicht in „green“ oder „yellow“ war → neu hinzufügen
            if (!found)
            {
                temp.city = successor->city;
                temp.distance = edgeToProcessData.distance + successor->distance;
                temp.shortestWay = successor->shortestWay;
                yellow.push_back(temp);
            }
        }
    }

    // === Ermittlung des kürzesten Pfads ===
    QVector<Street*> shortestPath;
    City* currentEdge = nullptr;

    // Rückverfolgung ab dem Ziel
    for (QVector<Tuppel>::const_iterator it = green.begin(); it != green.end(); ++it)
    {
        if (it->city == targetPointer)
        {
            shortestPath.insert(shortestPath.begin(), it->shortestWay);
            currentEdge = map.getOppositeCity(it->shortestWay, it->city);
        }
    }

    // Keine Verbindung gefunden
    if (currentEdge == nullptr)
    {
        qDebug() << "Dijkstra: No Connection beetween the targets";
        return QVector<Street*>();
    }

    // Rückverfolgung bis zur Startstadt
    while (currentEdge != startPointer)
    {
        for (QVector<Tuppel>::const_iterator it = green.begin(); it != green.end(); ++it)
        {
            if (it->city == currentEdge)
            {
                shortestPath.insert(shortestPath.begin(), it->shortestWay);
                currentEdge = map.getOppositeCity(it->shortestWay, it->city);
            }
        }
    }

    return shortestPath;
}
