#include "Lobby.h"

Lobby::Lobby(QWidget* parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

    connect(ui.btn_back, &QPushButton::clicked, [=] {
        emit lobtointe("back");
    });

    connect(ui.btn_start, &QPushButton::clicked, [=] {
        emit lobtointe("start");
    });

    connect(ui.btn_kickp2, &QPushButton::clicked, [=] {
        emit lobtointe("kickp2");
    });
}