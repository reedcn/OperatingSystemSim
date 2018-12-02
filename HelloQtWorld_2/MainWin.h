/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainWin.h
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
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <fstream>


#ifndef _MAINWIN_H
#define _MAINWIN_H

#include "ui_MainWin.h"

class MainWin : public QMainWindow {
    Q_OBJECT
public:
    MainWin();
    virtual ~MainWin();
public slots:
    void textChanged(const QString& text);
    void on_addJobFile_clicked();
private:
    Ui::MainWin widget;
    QPushButton *addJobFile;
    QString fileName;
    QString fileInput;
    QFile file;
    QObject *parent;
    int q;
    
};

#endif /* _MAINWIN_H */
