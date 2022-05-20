#pragma once

#include <utility>
#include "Chess.h"
#include "Point.h"
#include <vector>
#include <string>

class ChessBoard {
	Chess*** BoardData;

	std::vector<Chess*> DeadChess[2];
	//int boardData[10][11];


public:
	bool gameEnd = false;
	int winTeam = -1;
	/// <summary>
	/// when game start, put on the chess
	/// </summary>
	void init();

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
	std::pair<std::vector<Point>, std::vector<Point>> GetChessMove(Point);

	/// <summary>
	/// Get all chess where can go by their team.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::pair<Chess*, Point*> GetChessMoves(int);

	std::string ToString();
};