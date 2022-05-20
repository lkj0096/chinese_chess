#include "ChessBoard.h"
#include <utility>

void ChessBoard::init() {
    gameEnd = false;
    winTeam = -1;
    BoardData = new Chess * *[13];
    for (int j = 0; j < 13; j++) {
        BoardData[j] = new Chess*[14];
        for (int k = 0; k < 14; k++) {
            BoardData[j][k] = nullptr;
        }
    }

    BoardData[2][2] = new Chariot(0, Point(2, 2));
    BoardData[3][2] = new Horse(0, Point(3, 2));
    BoardData[4][2] = new Elephant(0, Point(4, 2));
    BoardData[5][2] = new Advisor(0, Point(5, 2));
    BoardData[6][2] = new General(0, Point(6, 2));
    BoardData[7][2] = new Advisor(0, Point(7, 2));
    BoardData[8][2] = new Elephant(0, Point(8, 2));
    BoardData[9][2] = new Horse(0, Point(9, 2));
    BoardData[10][2] = new Chariot(0, Point(10, 2));
    BoardData[3][4] = new Cannon(0, Point(3, 4));
    BoardData[9][4] = new Cannon(0, Point(9, 4));
    BoardData[2][5] = new Soldier(0, Point(2, 5));
    BoardData[4][5] = new Soldier(0, Point(4, 5));
    BoardData[6][5] = new Soldier(0, Point(6, 5));
    BoardData[8][5] = new Soldier(0, Point(8, 5));
    BoardData[10][5] = new Soldier(0, Point(10, 5));

    BoardData[2][11] = new Chariot(1, Point(2, 11));
    BoardData[3][11] = new Horse(1, Point(3, 11));
    BoardData[4][11] = new Elephant(1, Point(4, 11));
    BoardData[5][11] = new Advisor(1, Point(5, 11));
    BoardData[6][11] = new General(1, Point(6, 11));
    BoardData[7][11] = new Advisor(1, Point(7, 11));
    BoardData[8][11] = new Elephant(1, Point(8, 11));
    BoardData[9][11] = new Horse(1, Point(9, 11));
    BoardData[10][11] = new Chariot(1, Point(10, 11));
    BoardData[3][9] = new Cannon(1, Point(3, 9));
    BoardData[9][9] = new Cannon(1, Point(9, 9));
    BoardData[2][8] = new Soldier(1, Point(2, 8));
    BoardData[4][8] = new Soldier(1, Point(4, 8));
    BoardData[6][8] = new Soldier(1, Point(6, 8));
    BoardData[8][8] = new Soldier(1, Point(8, 8));
    BoardData[10][8] = new Soldier(1, Point(10, 8));
}

void ChessBoard::GetBoardInfo() {
}

void ChessBoard::MoveChess(Point st, Point en) {
    Chess* temp = nullptr;
    if (BoardData[en.x][en.y] != nullptr) {
        if (BoardData[en.x][en.y]->isGeneral()) {
            gameEnd = true;
            winTeam = BoardData[en.x][en.y]->getTeam();
        }
        temp = BoardData[en.x][en.y];
        DeadChess[temp->getTeam()].push_back(temp);
    }
    BoardData[en.x][en.y] = BoardData[st.x][st.y];
    BoardData[en.x][en.y]->SetPoint(en);
    BoardData[st.x][st.y] = nullptr;
}

std::pair<std::vector<Point>, std::vector<Point>> ChessBoard::GetChessMove(Point point) {
    /// 
    std::vector<Point> move = BoardData[point.x][point.y]->canMoveTo(BoardData);
    std::vector<Point> atk = BoardData[point.x][point.y]->canAttackTo(BoardData);
    return std::make_pair(move, atk);
}

std::pair<Chess*, Point*> ChessBoard::GetChessMoves(int) {
    //return std::make_pair(&General(), &Point());
    return std::make_pair(nullptr, nullptr);
}

std::string ChessBoard::ToString() {
    std::string str = "";
    for (int i = 11; i > 1; i--) {
        for (int j = 2; j < 11; j++) {
            if (BoardData[j][i] == nullptr)
                str += "-";
            else
                str += BoardData[j][i]->toString();
        }
        str += "\n";
    }
    return str;
}
