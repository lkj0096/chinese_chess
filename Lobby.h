#pragma once
#include <string>
using std::string;
#include <QtWidgets/QMainWindow>
#include "ui_Lobby.h"

class Lobby : public QMainWindow
{
    Q_OBJECT

public:
    Lobby(QWidget* parent = Q_NULLPTR);
signals:
    void lobtointe(string);
private:
    Ui::Lobby ui;
};