#pragma once

#include <vector>
#include <string>
#include "ChessBoard.h"
#include "NetworkHost.h"

class GameManager {
	std::vector<std::string> Log;

	std::vector<SOCKET> players;
	int TurnIndex;
	bool Gaming;
	bool respond;

	ChessBoard chessBoard;

	//For Online
	NetworkHost host = NULL;

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

	/// <summary>
	/// Turn to the next Player
	/// </summary>
	void CallNextPlayer();

	void GamingF();
public:

	GameManager();

	//For Online

	/// <summary>
	/// Create host socket to wait client 
	/// </summary>
	void CreateRoom();

	/// <summary>
	/// Close host socket to release 
	/// </summary>
	void CloseHost();

	/// <summary>
	/// Start chinese chess game
	/// </summary>
	void startGame();


	
	///BackCall

	void DealMsg(std::string);
	void ClientFull();
	void ServerTerminate();
};