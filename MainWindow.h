#pragma once
#include <string>
using std::string;
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
signals:
    void maintointe(string);
private:
    Ui::qt_MainWindow ui;
};
