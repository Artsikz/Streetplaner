///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "mapio.h"  // Basisklasse MapIo einbinden

/// Diese Klasse stellt eine einfache, fest kodierte (hardcoded) Karte bereit.
/// Sie erbt von MapIo und implementiert dort definierte Funktionen.
class MapIoNrw : public MapIo
{
public:
    MapIoNrw();             // Konstruktor
    virtual ~MapIoNrw();    // Virtueller Destruktor für korrekte Vererbung

    // Überschreibt die virtuelle Funktion aus MapIo,
    // um die Karte mit Daten (hier fest kodiert) zu füllen
    virtual void fillMap(AbstractMap &map);
};

#endif // MAPIONRW_H
