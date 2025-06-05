#ifndef STREET_H
#define STREET_H

#include "city.h"  // City-Klasse wird für die Straßen-Endpunkte benötigt

class Street
{
private:
    City* City_A;  // Zeiger auf die erste Stadt (Endpunkt A) der Straße
    City* City_B;  // Zeiger auf die zweite Stadt (Endpunkt B) der Straße

public:
    // Konstruktor: Straße zwischen zwei Städten erstellen
    Street(City* city_a, City* city_b);

    // Zugriffsfunktionen für die Städte an den Endpunkten
    City* getCity_A() const;
    City* getCity_B() const;

    // Methoden zum Zeichnen der Straße auf einer Grafikszene
    void draw(QGraphicsScene& scene);
    void drawRed(QGraphicsScene& scene) const;
};

#endif // STREET_H
