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
public slots:
    void ShowHintPos(vector<Point>, vector<Point>);
    void MoveChess(Point);
    void checkmate() {};
    void game_start(bool);
    void game_over();

signals:
    void chesstointe(string);
    void chess_pressed(Point);
    void hint_pressed(Point, Point);
private:
    bool thisisred;
    QPushButton* eaten;
    QPushButton* last_pressed_btn;
    Point last_pressed_pos;
    vector<Point> last_eatable;
    unsigned long long time_remained;
    int timerId;
    Ui::ChessBoard ui;
    QIcon *bear, *bear_rev;
    vector<vector<QPushButton*>> hints;
    vector<QPushButton*> chesses;
    void ui_init();
};
