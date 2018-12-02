/********************************************************************************
** Form generated from reading UI file 'addJob.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDJOB_H
#define UI_ADDJOB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addJob
{
public:
    QLabel *label;
    QLineEdit *jobFileText;
    QPushButton *addJobButton;

    void setupUi(QDialog *addJob)
    {
        if (addJob->objectName().isEmpty())
            addJob->setObjectName(QStringLiteral("addJob"));
        addJob->resize(375, 187);
        label = new QLabel(addJob);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 30, 221, 16));
        jobFileText = new QLineEdit(addJob);
        jobFileText->setObjectName(QStringLiteral("jobFileText"));
        jobFileText->setGeometry(QRect(50, 70, 261, 31));
        addJobButton = new QPushButton(addJob);
        addJobButton->setObjectName(QStringLiteral("addJobButton"));
        addJobButton->setGeometry(QRect(140, 130, 93, 28));

        retranslateUi(addJob);

        QMetaObject::connectSlotsByName(addJob);
    } // setupUi

    void retranslateUi(QDialog *addJob)
    {
        addJob->setWindowTitle(QApplication::translate("addJob", "addJob", nullptr));
        label->setText(QApplication::translate("addJob", "Enter job file name (must end in .txt)", nullptr));
        addJobButton->setText(QApplication::translate("addJob", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addJob: public Ui_addJob {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDJOB_H
