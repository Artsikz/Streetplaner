/********************************************************************************
** Form generated from reading UI file 'addstreetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTREETDIALOG_H
#define UI_ADDSTREETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddStreetDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_endCity;
    QLabel *label;
    QComboBox *comboBox_startCity;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QLabel *label_lenght;

    void setupUi(QDialog *AddStreetDialog)
    {
        if (AddStreetDialog->objectName().isEmpty())
            AddStreetDialog->setObjectName("AddStreetDialog");
        AddStreetDialog->resize(400, 188);
        gridLayout = new QGridLayout(AddStreetDialog);
        gridLayout->setObjectName("gridLayout");
        buttonBox = new QDialogButtonBox(AddStreetDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 3);

        comboBox_endCity = new QComboBox(AddStreetDialog);
        comboBox_endCity->setObjectName("comboBox_endCity");

        gridLayout->addWidget(comboBox_endCity, 3, 0, 1, 1);

        label = new QLabel(AddStreetDialog);
        label->setObjectName("label");
        QPalette palette;
        QBrush brush(QColor(85, 170, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush);
        label->setPalette(palette);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_startCity = new QComboBox(AddStreetDialog);
        comboBox_startCity->setObjectName("comboBox_startCity");

        gridLayout->addWidget(comboBox_startCity, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        line = new QFrame(AddStreetDialog);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);

        label_lenght = new QLabel(AddStreetDialog);
        label_lenght->setObjectName("label_lenght");
        QPalette palette1;
        QBrush brush1(QColor(85, 255, 255, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        label_lenght->setPalette(palette1);

        gridLayout->addWidget(label_lenght, 3, 2, 1, 1);


        retranslateUi(AddStreetDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddStreetDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddStreetDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddStreetDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStreetDialog)
    {
        AddStreetDialog->setWindowTitle(QCoreApplication::translate("AddStreetDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddStreetDialog", "Stra\303\237en einf\303\274gen", nullptr));
        label_lenght->setText(QCoreApplication::translate("AddStreetDialog", "  Street lenght:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStreetDialog: public Ui_AddStreetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTREETDIALOG_H
