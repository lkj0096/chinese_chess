#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <QtWidgets/QMainWindow>
#include "ui_ChessBoard.h"
#include "Point.h"
//class my_pos {
//    int x, y;
//};

class qtui_ChessBoard : public QMainWindow{
    Q_OBJECT
public:
    qtui_ChessBoard(QWidget* parent = Q_NULLPTR);
    void timerEvent(QTimerEvent* event);
    void set_turn(const bool& bl) {
        allcanmove = 1;
        thisisblack = bl;
    };
    void set_canmove() {
        allcanmove = 1;
    };

public slots:
    void ShowHintPos(const vector<Point>&);
    void MoveChess(const Point& ,const Point&);
    void checkmate() {};
    void game_start(bool);
    void game_over();

signals:
    void chesstointe(string);
    void chess_pressed(Point);
    void hint_pressed(Point, Point);

private:
    //bool BlackTurn;
    bool allcanmove;
    bool thisisblack;
    unsigned long long time_remained;
    int timerId;
    Ui::ChessBoard ui;
    QIcon *bear, *bear_rev;
    Point last_pressed_pos;
    vector<vector<QPushButton*>> hints;
    vector<QPushButton*> chesses;
    void ui_init();
};
