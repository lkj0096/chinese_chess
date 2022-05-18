#pragma once

#include<string>
using std::string;

#include <QtWidgets/QMainWindow>
#include "ui_Multiplayer.h"

class Multiplayer : public QMainWindow{
    Q_OBJECT

public:
    Multiplayer(QWidget* parent = Q_NULLPTR);
signals:
    void multitointe(string);
private:
    Ui::Multiplayer ui;
};