/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MainWin.cpp
 * Author: Christine
 *
 * Created on December 2, 2018, 12:35 AM
 */
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <fstream>

#include "MainWin.h"


using namespace std;

MainWin::MainWin() {
    widget.setupUi(this);
    connect(widget.addJobFile, SIGNAL(released()), this, SLOT(on_addJobFile_clicked()));
    connect(widget.jobFileText, SIGNAL(textChanged(const QString&)), this, SLOT(textChanged(const QString&)));

}

MainWin::~MainWin() {
}

void MainWin::textChanged(const QString& text) {
    if (0 < text.trimmed().length()) {
        //widget.addJobFile->setText(text.trimmed());
    //fileName = text.trimmed();
        widget.showJobText->setText(text);
        fileName = text;
        fileName = "C:\\cygwin64\\home\\Christine\\test\\backup1130\\HelloQtWorld_2\\" + fileName;
        //widget.quantumEdit->clear();
    } else {
        widget.showJobText->clear();
    }
}

void MainWin::on_addJobFile_clicked() {
    //fileInput = "C:\\cygwin64\\home\\Christine\\test\\backup1130\\HelloQtWorld_2\\" + fileName;
    QFile file(fileName);
    int i = 0;
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Info", file.errorString());

    } else {
        QTextStream in(&file);
        do {
            widget.showJobText->setText(in.readLine() + "\n");
        } while (in.readLine() != NULL);
    }
    /*aj = new addJob();
    aj->show();
    this->close();*/
}

