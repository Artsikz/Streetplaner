#include "street.h"

// Konstruktor: Initialisiert die Straße mit zwei Städten als Endpunkte
Street::Street(City* city_a, City* city_b): City_A(city_a), City_B(city_b)
{
    // Keine weitere Logik im Konstruktor notwendig
}

// Getter für die erste Stadt (City_A)
City* Street::getCity_A() const
{
    return City_A;
}

// Getter für die zweite Stadt (City_B)
City* Street::getCity_B() const
{
    return City_B;
}

// Zeichnet die Straße als schwarze Linie auf der übergebenen Szene
void Street::draw(QGraphicsScene& scene)
{
    // Sicherstellen, dass beide Städte gültig sind
    if (!City_A || !City_B)
    {
        qDebug() << "Error: One of the cities is null!";
        return;  // Abbrechen, wenn eine Stadt fehlt
    }

    QPen pen(Qt::black);  // Schwarzer Stift
    pen.setWidth(5);      // Linienbreite auf 5 setzen

    // Linie von City_A zu City_B hinzufügen
    scene.addLine(
        City_A->getposX(), City_A->getposY(),
        City_B->getposX(), City_B->getposY(),
        pen);

    // Debug-Ausgabe für die Zeichnung
    qDebug() << "street drawn between" << City_A->getName()
             << "and" << City_B->getName();
}

// Zeichnet die Straße als rote, etwas dickere Linie (z.B. Hervorhebung)
void Street::drawRed(QGraphicsScene& scene) const
{
    // Sicherstellen, dass beide Städte gültig sind
    if (!City_A || !City_B)
    {
        qDebug() << "Error: One of the cities is null!";
        return;  // Abbrechen, wenn eine Stadt fehlt
    }

    QPen pen(Qt::red);    // Roter Stift
    pen.setWidth(8);      // Linienbreite auf 8 (dicker) setzen

    // Linie von City_A zu City_B hinzufügen
    scene.addLine(
        City_A->getposX(), City_A->getposY(),
        City_B->getposX(), City_B->getposY(),
        pen);

    // Debug-Ausgabe für die Zeichnung
    qDebug() << "street drawn in red between" << City_A->getName()
             << "and" << City_B->getName();
}
