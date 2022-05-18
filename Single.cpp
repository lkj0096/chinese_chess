#include "Single.h"

Single::Single(QWidget* parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
    connect(ui.btn_back, &QPushButton::clicked, [=] {
        emit singtointe("back");
    });

    connect(ui.btn_self, &QPushButton::clicked, [=] {
        emit singtointe("self");
    });

    connect(ui.btn_AI, &QPushButton::clicked, [=] {
        emit singtointe("AI");
    });
    connect(ui.btn_load, &QPushButton::clicked, [=] {
        emit singtointe("load");
    });
}