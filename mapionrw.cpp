///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapionrw.h"
#include "abstractmap.h"

MapIoNrw::MapIoNrw()
{
}

MapIoNrw::~MapIoNrw()
{
}

void MapIoNrw::fillMap(AbstractMap &map)
{
    // Städte mit Namen und Positionen anlegen
    City* aachen = new City("Aachen", -100, 100);
    City* bonn = new City("Bonn", 0, 200);
    City* koeln = new City("Köln", 0, 0);
    City* duesseldorf = new City("Düsseldorf", 50, -100);

    // Straßen zwischen den Städten erstellen
    Street* aachenKoeln = new Street(aachen, koeln);
    Street* bonnKoeln = new Street(bonn, koeln);
    Street* ddorfKoeln = new Street(duesseldorf, koeln);

    // Städte zur Karte hinzufügen
    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);

    // Straßen zur Karte hinzufügen
    map.addStreet(aachenKoeln);
    map.addStreet(bonnKoeln);
    map.addStreet(ddorfKoeln);
}
