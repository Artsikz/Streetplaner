/**
 * @file city.h
 * @brief Header for the City class representing a city in the street planner
 * @author Your Name
 * @date Current Date
 */

#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>
#include <QDebug>

/**
 * @class City
 * @brief Represents a city with name and coordinates on a 2D map
 *
 * The City class encapsulates all properties and behaviors of a city
 * in the street planner application, including drawing capabilities.
 */
class City
{
private:
    int p_posX;         ///< X-coordinate of the city's position
    int p_posY;         ///< Y-coordinate of the city's position
    QString p_name;     ///< Name of the city

public:
    /**
     * @brief Constructor for City class
     * @param name Name of the city
     * @param x X-coordinate position
     * @param y Y-coordinate position
     */
    City(QString name, int x, int y);

    /**
     * @brief Draws the city on a graphics scene
     * @param scene Reference to the QGraphicsScene where the city will be drawn
     * @details Draws the city as a red dot with a label showing its name and coordinates
     */
    void draw(QGraphicsScene& scene);

    // === Accessor Methods ===

    /**
     * @brief Gets the city's name
     * @return City name as QString
     */
    QString getName() const;

    /**
     * @brief Gets the X-coordinate of the city
     * @return X-coordinate as integer
     */
    int getposX() const;

    /**
     * @brief Gets the Y-coordinate of the city
     * @return Y-coordinate as integer
     */
    int getposY() const;
};

#endif // CITY_H
