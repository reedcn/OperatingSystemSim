/*Christine Reed
CMSC 312
Operating System Simulator*/

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

#include "HelloForm.h"
#include "MainWin.h"

using namespace std;

#define ARGU 2
#define SIZE 1000

HelloForm::HelloForm() {
    widget.setupUi(this);
    connect(widget.quantumEdit, SIGNAL(textChanged(int x)), this, SLOT(textChanged(int x)));
    //quantumOK = new QPushButton("OK", this);
    connect(widget.quantumOK, SIGNAL (clicked()), this, SLOT (handleButton()));
}

HelloForm::~HelloForm() {
}

void HelloForm::textChanged(int x) {
    if (0 < x) {
        //widget.quantumEdit->setText("Hello " + text.trimmed() + "!");
        q = x;
    } else {
        widget.quantumEdit->clear();
    }
}

void HelloForm::handleButton() {
    
    mw = new MainWin();
    mw->show();
    this->close();
}
