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
    void MoveChess(Point& pt) { form_board->MoveChess(pt); };
    void ShowHintPos(vector<Point>& pts1, vector<Point>& pts2) { form_board->ShowHintPos(pts1,pts2); };
    void CheckMate() { form_board->checkmate(); };
    void EndGame() { form_board->game_over(); };
private:
    void showform(QMainWindow* w);
    MainUserInterface* main_in;
    qtui_ChessBoard* form_board;
    MainWindow* form_main;
    Single* form_sing;
    Multiplayer* form_multi;
    Lobby* form_lobb;
    Settings* form_set;
};