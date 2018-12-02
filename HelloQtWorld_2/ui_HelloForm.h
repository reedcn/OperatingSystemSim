/********************************************************************************
** Form generated from reading UI file 'HelloForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOFORM_H
#define UI_HELLOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HelloForm
{
public:
    QLineEdit *quantumEdit;
    QLabel *label;
    QPushButton *quantumOK;

    void setupUi(QDialog *HelloForm)
    {
        if (HelloForm->objectName().isEmpty())
            HelloForm->setObjectName(QStringLiteral("HelloForm"));
        HelloForm->resize(402, 142);
        quantumEdit = new QLineEdit(HelloForm);
        quantumEdit->setObjectName(QStringLiteral("quantumEdit"));
        quantumEdit->setGeometry(QRect(22, 47, 361, 31));
        label = new QLabel(HelloForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 361, 18));
        quantumOK = new QPushButton(HelloForm);
        quantumOK->setObjectName(QStringLiteral("quantumOK"));
        quantumOK->setGeometry(QRect(150, 90, 93, 28));

        retranslateUi(HelloForm);

        QMetaObject::connectSlotsByName(HelloForm);
    } // setupUi

    void retranslateUi(QDialog *HelloForm)
    {
        HelloForm->setWindowTitle(QApplication::translate("HelloForm", "Hello Qt World", nullptr));
        label->setText(QApplication::translate("HelloForm", "Enter time quantum q:", nullptr));
        quantumOK->setText(QApplication::translate("HelloForm", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelloForm: public Ui_HelloForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOFORM_H
