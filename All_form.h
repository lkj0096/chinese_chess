#pragma once
#ifndef ALLFORM_H
#define ALLFORM_H
#endif // !ALLFORM_H

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Point.h"
#include "MainWindow.h"
#include "Single.h"
#include "qtui_ChessBoard.h"
#include "Multiplayer.h"
#include "Lobby.h"
#include "Settings.h"
#include "Summery.h"

class MainUserInterface;

class All_form : public QObject{
    Q_OBJECT
public:
    All_form(QWidget* parent = Q_NULLPTR);
    void set_interface(MainUserInterface* inf) { main_in = inf; };
    void MoveChess(const Point& pt1, const Point& pt2) { 
        form_board->MoveChess(pt1, pt2);
    };
    void ShowHintPos(const vector<Point>& pts) { 
        form_board->ShowHintPos(pts);
    };
    void CheckMate() { 
        form_board->checkmate();
    };
    //void EndGame_client(bool RorB);
    void EndGame(bool RorB);
    //void EndGame_single(bool RorB);

    void SelfGameStart() {
        showform(form_board);
        form_board->game_start(0);
    }

    void MultiGameStart(bool RorB) {
        showform(form_board); 
        form_board->game_start(RorB); 
    };

    // for multi every turn
    void setCanMove() { form_board->set_canmove(); }

    // for single every turn
    void setTurn(const bool& bl) { form_board->set_turn(bl); };

private:
    int mymode; // 0->default 1->host 2->client 3->single
    void showform(QMainWindow* w);
    MainUserInterface* main_in;
    MainWindow* form_main;
    Single* form_sing;
    Multiplayer* form_multi;
    Lobby* form_lobb_host;
    Lobby* form_lobb_client;
    Settings* form_set;
    qtui_ChessBoard* form_board;
    Summery* form_summ_single;
    Summery* form_summ_host;
    Summery* form_summ_client;
};