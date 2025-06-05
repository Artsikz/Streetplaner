/**
    * @file addcitydialog.cpp
         * @brief Implementation of AddCityDialog class
             */

#include "addcitydialog.h"
#include "ui_addcitydialog.h"

//==============================================================================
// Constructor & Destructor
//==============================================================================

    AddCityDialog::AddCityDialog(QWidget *parent)
    : QDialog(parent)
, ui(new Ui::AddCityDialog)
{
    ui->setupUi(this);
    // Additional dialog setup could be added here (e.g., validators, focus)
}

AddCityDialog::~AddCityDialog()
{
    delete ui;
}

//==============================================================================
// City Creation Methods
//==============================================================================

City* AddCityDialog::createCity() const
{
    // Extract input data from UI fields
    QString name = ui->lineEdit_stadtName->text();
    int x = ui->lineEdit_posX->text().toInt();
    int y = ui->lineEdit_posY->text().toInt();

    // Debug output for verification
    qDebug() << "Creating new city:" << name << "at position (" << x << "," << y << ")";

    // Create and return new City object
    return new City(name, x, y);
}

//==============================================================================
// Input Field Getters
//==============================================================================

QString AddCityDialog::getName() const
{
    return ui->lineEdit_stadtName->text();
}

QString AddCityDialog::getX() const
{
    return ui->lineEdit_posX->text();
}

QString AddCityDialog::getY() const
{
    return ui->lineEdit_posY->text();
}
