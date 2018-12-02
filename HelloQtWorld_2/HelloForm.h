#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <fstream>

#ifndef _HELLOFORM_H
#define	_HELLOFORM_H

#include "ui_HelloForm.h"
#include "HelloForm.h"
#include "MainWin.h"

class HelloForm : public QDialog {
    Q_OBJECT
public:
    HelloForm();
    virtual ~HelloForm();
public slots:
    void textChanged(int x);
    void handleButton();
private:
    Ui::HelloForm widget;
    QPushButton *quantumOK;
    MainWin *mw;
    
    int q = 0;
};

#endif	/* _HELLOFORM_H */
