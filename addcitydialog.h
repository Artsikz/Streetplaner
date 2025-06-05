/**
 * @file addcitydialog.h
 * @brief Dialog for adding new cities to the map
 * @author Your japhe
 * @date Current Date
 */

#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include "city.h"
#include <QDialog>

namespace Ui {
class AddCityDialog;
}

/**
 * @class AddCityDialog
 * @brief Dialog class for creating and adding new cities to the street planner map.
 *
 * This dialog provides input fields for city name and coordinates (X, Y position).
 * It validates user input and creates City objects based on the provided data.
 */
class AddCityDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for AddCityDialog
     * @param parent Pointer to parent widget (default: nullptr)
     */
    explicit AddCityDialog(QWidget *parent = nullptr);

    /**
     * @brief Destructor - cleans up UI resources
     */
    ~AddCityDialog();

    // === City Creation Methods ===
    /**
     * @brief Creates a new City object from dialog input
     * @return Pointer to newly created City object with name and coordinates from input fields
     * @note Caller is responsible for memory management of returned City object
     */
    City* createCity() const;

    // === Input Field Getters ===
    /**
     * @brief Gets the city name from input field
     * @return City name as QString
     */
    QString getName() const;

    /**
     * @brief Gets the X coordinate from input field
     * @return X coordinate as QString (unconverted)
     */
    QString getX() const;

    /**
     * @brief Gets the Y coordinate from input field
     * @return Y coordinate as QString (unconverted)
     */
    QString getY() const;

private slots:
               // Reserved for future dialog-specific slots

private:
    /// UI pointer for dialog interface
    Ui::AddCityDialog *ui;
};

#endif // ADDCITYDIALOG_H
