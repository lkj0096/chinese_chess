#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <QtWidgets/QMainWindow>
#include <QTimerEvent>
#include "ui_ChessBoard.h"

class my_pos {
    int x, y;
};

class ChessBoard : public QMainWindow
{
    Q_OBJECT

public:
    ChessBoard(QWidget* parent = Q_NULLPTR);
    void game_start();
public slots:
    void hint_pos(vector<my_pos>) {};
    void checkmate() {};
    void settime() {};
    void move_chess(string) {};
    void game_start();
    void game_over();
private slots:
    void timerEvent(QTimerEvent* event);
signals:
    void maintointe(string) {};
private:
    int timerId;
    size_t time_remained;
    Ui::ChessBoard ui;
};
