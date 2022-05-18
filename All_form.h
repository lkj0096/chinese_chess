#pragma once
#include <QObject>
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "MainWindow.h"
#include "Single.h"
#include "ChessBoard.h"
#include "Multiplayer.h"
#include "Lobby.h"
#include "Settings.h"

struct pos {
    int x, y;
};

class All_form : public QObject{
    Q_OBJECT

public:
    All_form(QWidget* parent = Q_NULLPTR);
signals:

    void sig_board(vector<pos>);

public slots:
    void ret_to_main(string str) {};

private:
    void showform(QMainWindow* w) {
        form_main.hide();
        form_board.hide();
        form_lobb.hide();
        form_sing.hide();
        form_multi.hide();
        form_set.hide();
        w->show();
    }
    ChessBoard form_board;
    MainWindow form_main;
    Single form_sing;
    Multiplayer form_multi;
    Lobby form_lobb;
    Settings form_set;
};