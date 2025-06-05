#include "map.h"

Map::Map() {}

Map::~Map() {}


///////////////////////////////////////////////////////////////////////////////////////
/// Add Funktionen
////////////////////////////////////////////////////////////////////////////7///////////

void Map::addCity(City* city)
{
    if (!city) return;  // Prüfen, ob der Zeiger gültig ist, sonst Funktion abbrechen

    // Überprüfen, ob die Stadt bereits in der Liste p_cities enthalten ist
    for (City* existing : p_cities)
    {
        // Vergleich der Städtenamen, um Duplikate zu vermeiden
        if (existing->getName() == city->getName())
        {
            // Ausgabe einer Meldung, dass die Stadt schon existiert
            qDebug() << "---->Die Stadt" << city->getName() << "existiert bereits!";
            return;  // Funktion beenden, da Stadt schon vorhanden ist
        }
    }

    // Stadt zur Liste p_cities hinzufügen, wenn sie noch nicht vorhanden war
    p_cities.append(city);
    // Ausgabe zur Bestätigung, dass die Stadt hinzugefügt wurde
    qDebug() << "--->Folgender Stadt wurde der Map hinzugefügt:" << city->getName();
}


bool Map::addStreet(Street* s)
{
    // Prüfen, ob beide Städte der Straße (City_A und City_B) in der Karte vorhanden sind
    if (!p_cities.contains(s->getCity_A()) || !p_cities.contains(s->getCity_B()))
    {
        // Wenn eine der Städte nicht vorhanden ist, kann die Straße nicht hinzugefügt werden
        return false;
    }

    // Wenn beide Städte vorhanden sind, Straße zur Straßenliste hinzufügen
    p_streets.append(s);

    // Erfolgreiches Hinzufügen bestätigen
    return true;
}




////////////////////////////////////////////////////////////////////////

void Map::draw(QGraphicsScene& scene)
{
    // Über alle Städte in der Liste p_cities iterieren
    for (City* city : p_cities)
    {
        // Jede Stadt zeichnet sich selbst auf der übergebenen Szene
        city->draw(scene);
    }
}


//////////////////////////////////////////////////////////////////////////////////

void Map::clear()
{
    // Alle City-Objekte in p_cities löschen und Speicher freigeben
    qDeleteAll(p_cities);
    // Die Liste der Städte leeren (alle Zeiger entfernen)
    p_cities.clear();

    // Alle Street-Objekte in p_streets löschen und Speicher freigeben
    qDeleteAll(p_streets);
    // Die Liste der Straßen leeren (alle Zeiger entfernen)
    p_streets.clear();
}

///////////////////////////////////////////////////////////////
City* Map::findCity(const QString cityName) const
{
    // Über alle Städte in p_cities iterieren
    for (auto city : p_cities)
    {
        // Prüfen, ob der Name der aktuellen Stadt mit cityName übereinstimmt
        if (city->getName() == cityName)
            return city;  // Gefundene Stadt zurückgeben
    }
    // Wenn keine Stadt mit dem Namen gefunden wurde, nullptr zurückgeben
    return nullptr;
}

//////////////////////////////////////////////////////////
/// getter funktionen
////////////////////////////////////////////////7

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> liste;
    // Über alle Straßen iterieren
    for (auto street : p_streets)
    {
        // Wenn die Straße an der Stadt city anliegt (entweder City_A oder City_B)
        if (street->getCity_A() == city || street->getCity_B() == city)
            liste.append(street);  // Straße zur Ergebnisliste hinzufügen
    }

    return liste;  // Liste aller Straßen zurückgeben, die an city angrenzen
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    // Prüfen, ob city der erste Endpunkt der Straße ist
    if (street->getCity_A() == city)
        return street->getCity_B();  // Rückgabe des gegenüberliegenden Endpunkts

    // Prüfen, ob city der zweite Endpunkt der Straße ist
    if (street->getCity_B() == city)
        return street->getCity_A();  // Rückgabe des gegenüberliegenden Endpunkts

    // city gehört nicht zu dieser Straße, daher nullptr zurückgeben
    return nullptr;
}

double Map::getLength(const Street* street) const
{
    if (!street)  // Falls Zeiger ungültig (nullptr) ist
        return 0.0;  // Länge 0 zurückgeben

    City* a = street->getCity_A();
    City* b = street->getCity_B();

    // Falls einer der beiden Städte nicht existiert, Länge 0 zurückgeben
    if (!a || !b)
        return 0.0;

    // Euklidischer Abstand berechnen
    double dx = a->getposX() - b->getposX();
    double dy = a->getposY() - b->getposY();

    double length = std::sqrt(dx * dx + dy * dy);

    return length;  // Berechnete Länge zurückgeben
}

QList<City*> Map::getCityList() const
{
    return p_cities;  // Liste aller Städte zurückgeben
}
