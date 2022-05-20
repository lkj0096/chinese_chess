#include "qtui_ChessBoard.h"
#include <vector>
#include <QVBoxLayout>
using std::vector;

namespace ChessBoardLoacation{
    struct Coordinate{
        int x, y;
    };

    const vector<vector<Coordinate>> CoordinateMap = {
    {{17,670},{17,598},{17,526},{17,454},{17,382},{17,310},{17,238},{17,166},{17,94},{17,22}},
    {{89,670},{89,598},{89,526},{89,454},{89,382},{89,310},{89,238},{89,166},{89,94},{89,22}},
    {{161,670},{161,598},{161,526},{161,454},{161,382},{161,310},{161,238},{161,166},{161,94},{161,22}},
    {{233,670},{233,598},{233,526},{233,454},{233,382},{233,310},{233,238},{233,166},{233,94},{233,22}},
    {{305,670},{305,598},{305,526},{305,454},{305,382},{305,310},{305,238},{305,166},{305,94},{305,22}},
    {{377,670},{377,598},{377,526},{377,454},{377,382},{377,310},{377,238},{377,166},{377,94},{377,22}},
    {{449,670},{449,598},{449,526},{449,454},{449,382},{449,310},{449,238},{449,166},{449,94},{449,22}},
    {{521,670},{521,598},{521,526},{521,454},{521,382},{521,310},{521,238},{521,166},{521,94},{521,22}},
    {{593,670},{593,598},{593,526},{593,454},{593,382},{593,310},{593,238},{593,166},{593,94},{593,22}}
    };
    //[x][y]的實際座標

}


qtui_ChessBoard::qtui_ChessBoard(QWidget* parent)
	: QMainWindow(parent) {
    time_remained = 0;
    bear = new QIcon(":/pics/pics/ind.jpg");
    bear_rev = new QIcon(":/pics/pics/ind_rev.jpg");
    ui.setupUi(this);
    // init set
    chesses = { ui.btn_RD_shi_R,  ui.btn_RD_shi_L,
                ui.btn_RD_xiang_R,ui.btn_RD_xiang_L,
                ui.btn_RD_ma_R,   ui.btn_RD_ma_L,
                ui.btn_RD_ju_R,   ui.btn_RD_ju_L,
                ui.btn_RD_pao_R,  ui.btn_RD_pao_L,
                ui.btn_RD_bing_5, ui.btn_RD_bing_4,ui.btn_RD_bing_3,
                ui.btn_RD_bing_2, ui.btn_RD_bing_1,
                ui.btn_RD_shuai,
                
                ui.btn_BL_shi_R,  ui.btn_BL_shi_L,
                ui.btn_BL_xiang_R,ui.btn_BL_xiang_L,
                ui.btn_BL_ma_R,   ui.btn_BL_ma_L,
                ui.btn_BL_ju_R,   ui.btn_BL_ju_L,
                ui.btn_BL_pao_R,  ui.btn_BL_pao_L,
                ui.btn_BL_zu_5,   ui.btn_BL_zu_4,ui.btn_BL_zu_3,
                ui.btn_BL_zu_2,   ui.btn_BL_zu_1,
                ui.btn_BL_jiang
               };
    // end init set
    // 
    // Create Hint Button
    QIcon circle(":/pics/pics/circle.png");
    hints = vector<vector<QPushButton*>>(9, vector<QPushButton*>(10));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            QPushButton* newcircle = new QPushButton(this);
            newcircle->setGeometry(QRect(
                ChessBoardLoacation::CoordinateMap[i][j].x,
                ChessBoardLoacation::CoordinateMap[i][j].y,
                51, 51));
            newcircle->setVisible(false);
            newcircle->setText(QString());
            newcircle->setEnabled(false);
            newcircle->setLayoutDirection(Qt::LeftToRight);
            newcircle->setFlat(true);
            newcircle->setIcon(circle);
            newcircle->setIconSize(QSize(51, 51));
            newcircle->setObjectName(QString("btn_circle%1%2").arg(i, 2, 10).arg(j, 2, 10));
            newcircle->raise();
            hints[i][j] = newcircle;
            
            connect(newcircle, &QPushButton::clicked, [=] {
                emit hint_pressed(last_pressed_pos,Point(i, j));
            });
        }
    }
    // End Create Hint Button
    //
    // Set connection about chess and signal
    for (auto& i : chesses) {
        connect(i, &QPushButton::clicked, [=] {
            last_pressed_btn = i;
            last_pressed_pos = Point(
                (i->x() - 017) / 72,
                (670 - i->y()) / 72);
            emit chess_pressed(last_pressed_pos); 
        });
    }
    //
    //
    // surrender
    connect(ui.btn_RD_surrender, &QPushButton::clicked, [=] {
        emit chesstointe("RDsurr");
    });
    connect(ui.btn_BL_surrender, &QPushButton::clicked, [=] {
        emit chesstointe("BLsurr");
    });
    connect(ui.btn_save, &QPushButton::clicked, [=] {
        emit chesstointe("Savelog");
    });
}

void qtui_ChessBoard::MoveChess(Point pt) {
    for (auto& m : chesses) {
        if (m->x() == ChessBoardLoacation::CoordinateMap[pt.x][pt.y].x &&
            m->y() == ChessBoardLoacation::CoordinateMap[pt.x][pt.y].y) {
            m->setVisible(false);
            m->setEnabled(false);
            break;
        }
    }
    last_pressed_btn->setGeometry(
        ChessBoardLoacation::CoordinateMap[pt.x][pt.y].x,
        ChessBoardLoacation::CoordinateMap[pt.x][pt.y].y,
        50, 50);
}

void qtui_ChessBoard::ShowHintPos(vector<Point> blank, vector<Point> eatable) {
    for (auto& i : hints) {
        for (auto& j : i) {
            j->setVisible(false);
            j->setEnabled(false);
        }
    }
    for (const auto& i : blank) {
        hints[i.x][i.y]->setVisible(true);
        hints[i.x][i.y]->setEnabled(true);
    }
    for (const auto& i : eatable) {
        hints[i.x][i.y]->setVisible(true);
        hints[i.x][i.y]->setEnabled(true);
    }
}

void qtui_ChessBoard::timerEvent(QTimerEvent* event) {
    if (event->timerId() == timerId){
        time_remained += 1;
        int secs = time_remained % 60;
        int mins = time_remained / 60;
        ui.lb_timer->setText(QString("%1:%2")
        .arg(mins, 2, 10, QLatin1Char('0'))
        .arg(secs, 2, 10, QLatin1Char('0')));
        if (time_remained & 1) {
            ui.pic_bear_RD->setIcon(*bear);
            ui.pic_bear_BL->setIcon(*bear_rev);
        }
        else {
            ui.pic_bear_RD->setIcon(*bear_rev);
            ui.pic_bear_BL->setIcon(*bear);
        }
        
    }
}

void qtui_ChessBoard::ui_init() {
    for (auto& i : chesses) {
        i->setVisible(true);
        i->setEnabled(true);
    }
    ui.BACK->setGeometry(QRect(0, 0, 661, 741));
    ui.btn_BL_shi_R->setGeometry(QRect(377, 670, 50, 50));
    ui.btn_BL_shi_L->setGeometry(QRect(233, 670, 50, 50));
    ui.btn_RD_shi_R->setGeometry(QRect(377, 22, 50, 50));
    ui.btn_RD_shi_L->setGeometry(QRect(233, 22, 50, 50));
    ui.btn_BL_pao_R->setGeometry(QRect(521, 526, 50, 50));
    ui.btn_BL_pao_L->setGeometry(QRect(89, 526, 50, 50));
    ui.btn_RD_pao_R->setGeometry(QRect(521, 166, 50, 50));
    ui.btn_RD_pao_L->setGeometry(QRect(89, 166, 50, 50));
    ui.btn_BL_xiang_R->setGeometry(QRect(449, 670, 50, 50));
    ui.btn_BL_xiang_L->setGeometry(QRect(161, 670, 50, 50));
    ui.btn_BL_jiang->setGeometry(QRect(305, 670, 50, 50));
    ui.btn_BL_ma_R->setGeometry(QRect(521, 670, 50, 50));
    ui.btn_BL_ma_L->setGeometry(QRect(89, 670, 50, 50));
    ui.btn_BL_ju_R->setGeometry(QRect(593, 670, 50, 50));
    ui.btn_BL_ju_L->setGeometry(QRect(17, 670, 50, 50));
    ui.btn_RD_bing_5->setGeometry(QRect(593, 238, 50, 50));
    ui.btn_RD_bing_4->setGeometry(QRect(449, 238, 50, 50));
    ui.btn_RD_bing_3->setGeometry(QRect(305, 238, 50, 50));
    ui.btn_RD_bing_2->setGeometry(QRect(161, 238, 50, 50));
    ui.btn_RD_bing_1->setGeometry(QRect(17, 238, 50, 50));
    ui.btn_BL_zu_5->setGeometry(QRect(593, 454, 50, 50));
    ui.btn_BL_zu_1->setGeometry(QRect(17, 454, 50, 50));
    ui.btn_BL_zu_4->setGeometry(QRect(449, 454, 50, 50));
    ui.btn_BL_zu_3->setGeometry(QRect(305, 454, 50, 50));
    ui.btn_BL_zu_2->setGeometry(QRect(161, 454, 50, 50));
    ui.btn_RD_ju_R->setGeometry(QRect(593, 22, 50, 50));
    ui.btn_RD_ju_L->setGeometry(QRect(17, 22, 50, 50));
    ui.btn_RD_xiang_L->setGeometry(QRect(161, 22, 50, 50));
    ui.btn_RD_ma_L->setGeometry(QRect(89, 22, 50, 50));
    ui.btn_RD_shuai->setGeometry(QRect(305, 22, 50, 50));
    ui.btn_RD_ma_R->setGeometry(QRect(521, 22, 50, 50));
    ui.btn_RD_xiang_R->setGeometry(QRect(449, 22, 50, 50));
}

void qtui_ChessBoard::game_start(bool BorR) {
    this->ui_init();
    time_remained = 0;
    ui.lb_timer->setText(QString("00:00"));
    timerId = startTimer(1000);
}

void qtui_ChessBoard::game_over() {
    killTimer(timerId);
}