#include "ChessBoard.h"
#include <utility>

void ChessBoard::init() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k < 12; k++) {
                BoardData[i][j][k] = nullptr;
            }
        }
    }

    BoardData[0][0][0] = new Soldier();
}

void ChessBoard::GetBoardInfo() {
}

void ChessBoard::MoveChess(Point, Point) {
}

void ChessBoard::GetChessMove(Point) {
}

std::pair<Chess*, Point*> ChessBoard::GetChessMoves(int) {
    return std::make_pair(&Chess(), &Point());
}
