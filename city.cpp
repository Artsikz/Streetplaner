/**
 * @file city.cpp
 * @brief Implementation of the City class
 * @author Your Name
 * @date Current Date
 */

#include "city.h"
#include <qgraphicsitem.h>

//==============================================================================
// Constructor
//==============================================================================


City::City(QString name, int x, int y)
    : p_name(name), p_posX(x), p_posY(y)
{
    qDebug() << "Stadt initialisiert: " << name << "(" << x << "," << y << ")";
}

//==============================================================================
// Accessor Methods
//==============================================================================


QString City::getName() const
{
    return p_name;
}


int City::getposX() const
{
    return p_posX;
}

int City::getposY() const
{
    return p_posY;
}

//==============================================================================
// Drawing Method
//==============================================================================


void City::draw(QGraphicsScene& scene)
{
    const int punktRadius = 5;  ///< Radius of the city's visual representation

    // Draw city as red point
    scene.addEllipse(
        p_posX - punktRadius,
        p_posY - punktRadius,
        punktRadius * 2,
        punktRadius * 2,
        QPen(Qt::red),
        QBrush(Qt::red)
        );

    // Create and position label with city info
    QString label = QString("%1 P(%2,%3)").arg(p_name).arg(p_posX).arg(p_posY);
    QGraphicsTextItem* textItem = scene.addText(label);
    textItem->setDefaultTextColor(Qt::black);
    textItem->setPos(p_posX + 5, p_posY - 10);

    // Debug output
    qDebug() << "Stadt " << p_name
             << " erfolgreich gezeichnet in P("
             << p_posX << "," << p_posY << ")";
}
