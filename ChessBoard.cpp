#include <vector>
using std::vector;
using std::pair;
#include "ChessBoard.h"
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


ChessBoard::ChessBoard(QWidget* parent)
	: QMainWindow(parent) {
    //board_timer = new QTimer();
    //board_timer->setInterval(1000);
	ui.setupUi(this);
    connect(ui.btn_BL_jiang, &QPushButton::clicked, [=] {emit });
    //connect(board_timer, SIGNAL(&QTimer::timeout), this, SLOT(&ChessBoard::update_time));
}

void ChessBoard::timerEvent(QTimerEvent* event) {
    if (event->timerId() == timerId){
        time_remained += 1;
        int secs = time_remained % 60;
        int mins = time_remained / 60;
        ui.lb_timer->setText(QString("%1:%2")
        .arg(mins, 2, 10, QLatin1Char('0'))
        .arg(secs, 2, 10, QLatin1Char('0')));
    }
}

void ChessBoard::game_start() {
    time_remained = 0;
    ui.lb_timer->setText(QString("00:00"));
    timerId = startTimer(1000);
}

void ChessBoard::game_over() {
    time_remained = 0;
    ui.lb_timer->setText(QString("00:00"));
    killTimer(timerId);
}