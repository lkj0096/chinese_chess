#pragma once

#include <Ws2tcpip.h>
#include <vector>
#include <string>
#include "ChessBoard.h"
#include "NetworkHost.h"

class User;

class GameManager {
	User* BackCallInstance;
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

	std::pair<std::vector<Point>, std::vector<Point>> GetChessMove(Point);
public:

	GameManager(User* ins);

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

	void ClientDisConnect(SOCKET);
	void DealMsg(SOCKET, std::string);
	void ClientFull();
	void ServerTerminate();
};