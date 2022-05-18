#include "MainWindow.h"
#include <QtWidgets/QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    ui.setupUi(this);
    connect(ui.btn_single, &QPushButton::clicked, [=] {
        emit maintointe("single");
    });

    connect(ui.btn_multi, &QPushButton::clicked, [=] {
        emit maintointe("multi");
    });

    connect(ui.btn_end, &QPushButton::clicked, [=] {
        emit maintointe("end");
    });
}
