#pragma once

#include <utility>
#include "Chess.h"
#include "Point.h"

class ChessBoard {
	Chess* BoardData[2][13][14];
	//int boardData[10][11];


	/// <summary>
	/// when game start, put on the chess
	/// </summary>
	void init();
public:
	/// <summary>
	/// Get all the chess on the board
	/// </summary>
	void GetBoardInfo();

	/// <summary>
	/// Move the chess to another place by its position.
	/// </summary>
	void MoveChess(Point, Point);

	/// <summary>
	/// Get the chess where can go by its position.
	/// </summary>
	/// <param name=""></param>
	void GetChessMove(Point);

	/// <summary>
	/// Get all chess where can go by their team.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::pair<Chess*, Point*> GetChessMoves(int);
};