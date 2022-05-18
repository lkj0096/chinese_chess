#include "Multiplayer.h"

Multiplayer::Multiplayer(QWidget* parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

    connect(ui.btn_back, &QPushButton::clicked, [=] {
        emit multitointe("back");
    });

    connect(ui.btn_create, &QPushButton::clicked, [=] {
        emit multitointe("create");
    });

    connect(ui.btn_join, &QPushButton::clicked, [=] {
        emit multitointe("join");
    });
}

