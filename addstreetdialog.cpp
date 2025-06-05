/**
 * @file addstreetdialog.cpp
 * @brief Implementation of AddStreetDialog class
 */

#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

//==============================================================================
// Constructor & Destructor
//==============================================================================

AddStreetDialog::AddStreetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStreetDialog)
{
    ui->setupUi(this);
    // Additional dialog setup could be added here (e.g., ComboBox styling, validation)
}

AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

//==============================================================================
// ComboBox Access Methods
//==============================================================================

QComboBox* AddStreetDialog::getStartCityComboBox() const
{
    return ui->comboBox_startCity;
}

QComboBox* AddStreetDialog::getEndCityComboBox() const
{
    return ui->comboBox_endCity;
}

//==============================================================================
// Street Information Methods
//==============================================================================

QString AddStreetDialog::getLength() const
{
    return ui->label_lenght->text();
}
