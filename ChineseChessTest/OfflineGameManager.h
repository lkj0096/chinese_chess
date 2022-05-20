#pragma once
#include <vector>
#include <string>
#include "ChessBoard.h"
class User;

class OfflineGameManager {
	User* BackCallInstance;
	ChessBoard chessBoard;
	std::vector<std::string> Log;
	int TurnIndex;
	bool Gaming;

	/// <summary>
	/// To put the chesses on board
	/// </summary>
	void init();

	/// <summary>
	/// RandomTeam Red or Black
	/// </summary>
	void RandomTeam();

	/// <summary>
	/// Get whose turn, and turn next
	/// </summary>
	/// <returns></returns>
	int getTurnIndex();
public:
	OfflineGameManager(User* ins);
};