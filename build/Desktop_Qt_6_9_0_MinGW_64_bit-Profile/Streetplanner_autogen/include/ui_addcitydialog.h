/********************************************************************************
** Form generated from reading UI file 'addcitydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCITYDIALOG_H
#define UI_ADDCITYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddCityDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label_stadtName;
    QLineEdit *lineEdit_stadtName;
    QFrame *line;
    QLabel *label_stadtKoordinaten;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_posX;
    QLineEdit *lineEdit_posY;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddCityDialog)
    {
        if (AddCityDialog->objectName().isEmpty())
            AddCityDialog->setObjectName("AddCityDialog");
        AddCityDialog->resize(400, 119);
        formLayout = new QFormLayout(AddCityDialog);
        formLayout->setObjectName("formLayout");
        label_stadtName = new QLabel(AddCityDialog);
        label_stadtName->setObjectName("label_stadtName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_stadtName);

        lineEdit_stadtName = new QLineEdit(AddCityDialog);
        lineEdit_stadtName->setObjectName("lineEdit_stadtName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_stadtName);

        line = new QFrame(AddCityDialog);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, line);

        label_stadtKoordinaten = new QLabel(AddCityDialog);
        label_stadtKoordinaten->setObjectName("label_stadtKoordinaten");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_stadtKoordinaten);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_posX = new QLineEdit(AddCityDialog);
        lineEdit_posX->setObjectName("lineEdit_posX");
        lineEdit_posX->setMaxLength(600);

        horizontalLayout->addWidget(lineEdit_posX);

        lineEdit_posY = new QLineEdit(AddCityDialog);
        lineEdit_posY->setObjectName("lineEdit_posY");

        horizontalLayout->addWidget(lineEdit_posY);


        formLayout->setLayout(2, QFormLayout::ItemRole::FieldRole, horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(3, QFormLayout::ItemRole::FieldRole, verticalSpacer);

        buttonBox = new QDialogButtonBox(AddCityDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(7, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(AddCityDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddCityDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddCityDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddCityDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCityDialog)
    {
        AddCityDialog->setWindowTitle(QCoreApplication::translate("AddCityDialog", "Dialog", nullptr));
        label_stadtName->setText(QCoreApplication::translate("AddCityDialog", "Stadt:", nullptr));
        lineEdit_stadtName->setPlaceholderText(QCoreApplication::translate("AddCityDialog", "Stadt", nullptr));
        label_stadtKoordinaten->setText(QCoreApplication::translate("AddCityDialog", "Koordinaten:", nullptr));
        lineEdit_posX->setInputMask(QString());
        lineEdit_posX->setText(QString());
        lineEdit_posX->setPlaceholderText(QCoreApplication::translate("AddCityDialog", "X_Koordinate", nullptr));
        lineEdit_posY->setPlaceholderText(QCoreApplication::translate("AddCityDialog", "Y_Koordinate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCityDialog: public Ui_AddCityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCITYDIALOG_H
