/**
 * @file addstreetdialog.h
 * @brief Dialog for adding new streets between cities on the map
 * @author Your Name
 * @date Current Date
 */

#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>
#include <QComboBox>
#include "city.h"

namespace Ui {
class AddStreetDialog;
}

/**
 * @class AddStreetDialog
 * @brief Dialog class for creating and adding new streets between existing cities.
 *
 * This dialog provides ComboBoxes for selecting start and end cities from available
 * cities on the map. It displays the calculated length of the street and allows
 * users to create connections between cities in the street planner.
 */
class AddStreetDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for AddStreetDialog
     * @param parent Pointer to parent widget (default: nullptr)
     */
    explicit AddStreetDialog(QWidget *parent = nullptr);

    /**
     * @brief Destructor - cleans up UI resources
     */
    ~AddStreetDialog();

    // === ComboBox Access Methods ===
    /**
     * @brief Gets pointer to the start city ComboBox
     * @return Pointer to ComboBox containing available start cities
     * @note Used by caller to populate and read city selection
     */
    QComboBox* getStartCityComboBox() const;

    /**
     * @brief Gets pointer to the end city ComboBox
     * @return Pointer to ComboBox containing available end cities
     * @note Used by caller to populate and read city selection
     */
    QComboBox* getEndCityComboBox() const;

    // === Street Information Methods ===
    /**
     * @brief Gets the displayed street length
     * @return Street length as QString from the length label
     * @note Length is typically calculated and displayed by the calling code
     */
    QString getLength() const;

private:
    /// UI pointer for dialog interface
    Ui::AddStreetDialog *ui;
};

#endif // ADDSTREETDIALOG_H
