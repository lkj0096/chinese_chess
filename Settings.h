#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Settings.h"

class Settings : public QMainWindow{
    Q_OBJECT

public:
    Settings(QWidget* parent = Q_NULLPTR);

private:
    Ui::Settings ui;
};