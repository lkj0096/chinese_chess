#pragma once
#include <string>
using std::string;

#include <QtWidgets/QMainWindow>
#include "ui_single.h"

class Single : public QMainWindow{
    Q_OBJECT

public:
    Single(QWidget* parent = Q_NULLPTR);
signals:
    void singtointe(string);
private:
    Ui::Single ui;
};