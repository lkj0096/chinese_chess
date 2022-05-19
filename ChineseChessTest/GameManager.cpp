#include "GameManager.h"
#include "DebugLogger.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

void GameManager::init() {
	chessBoard.init();
}

void GameManager::RandomTeam() {
	srand(time(NULL));
	for (int i = 0; i < players.size(); i++) {
		swap(players[i], players[rand() % 2]);
	}
}

int GameManager::getTurnIndex() {
	int i = TurnIndex;
	TurnIndex = (TurnIndex + 1) & 1;
	return i;
}

void GameManager::CallNextPlayer() {
	string str = "your turn";
	send(players[getTurnIndex()], str.c_str(), strlen(str.c_str()), 0);
}

void GameManager::GamingF() {
	while (Gaming) {
		if (respond) {
			respond = false;
			CallNextPlayer();
		}
	}
}

GameManager::GameManager() {
	TurnIndex = 0;
	Gaming = true;
	respond = true;
	host = NetworkHost(this);
}

void GameManager::CreateRoom() {
	DebugLogger::Print(0, __LINE__, std::vector({ "OpenServer" }));
	host.OpenServer();
}

void GameManager::CloseHost() {
	host.CloseServer();
}

void GameManager::startGame() {
	players = host.getPlayers();
	TurnIndex = 0;
	Gaming = true;
	respond = true;
	RandomTeam();
	host.BoardCast("Game Start!");
	for (auto player : players) {
		host.SendMsg(player, to_string(getTurnIndex()));
	}
	thread gamingThread = thread(&GameManager::GamingF, this);
	gamingThread.detach(); 
}

void GameManager::DealMsg(string msg) {
	if (msg == "Move") {
		//chessBoard.MoveChess();
		respond = true;
	}
}

void GameManager::ClientFull() {
	cout << "client already full" << endl;
}

void GameManager::ServerTerminate() {
}
