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

class MainUserInterface;

class All_form : public QObject{
    Q_OBJECT
public:
    All_form(QWidget* parent = Q_NULLPTR);
    void set_interface(MainUserInterface* inf) { main_in = inf; };
    void MoveChess(const Point& pt) { form_board->MoveChess(pt); };
    void ShowHintPos(const vector<Point>& pts1) { form_board->ShowHintPos(pts1); };
    void CheckMate() { form_board->checkmate(); };
    void EndGame() { form_board->game_over(); };
    void gamestart(bool RorB) { form_board->game_start(RorB); };
    void setTurn(const bool& bl) { form_board->setTurn(bl); };

private:
    void showform(QMainWindow* w);
    MainUserInterface* main_in;
    qtui_ChessBoard* form_board;
    MainWindow* form_main;
    Single* form_sing;
    Multiplayer* form_multi;
    Lobby* form_lobb_host;
    Lobby* form_lobb_client;
    Settings* form_set;
};