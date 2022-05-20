#include "GameManager.h"
#include "DebugLogger.h"
#include "Player.h"
#include "DataConverter.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <utility>

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
	string str = "Turn";
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

std::pair<std::vector<Point>, std::vector<Point>> GameManager::GetChessMove(Point point) {
	return chessBoard.GetChessMove(point);
}

GameManager::GameManager(User* ins) {
	TurnIndex = 0;
	Gaming = true;
	respond = true;
	host = NetworkHost(this);
	BackCallInstance = ins;
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

void GameManager::ClientDisConnect(SOCKET client) {
	BackCallInstance->HostClientDisConnect(client);
}

void GameManager::DealMsg(SOCKET client, string msg) {
	if (msg.substr(0, 4) == "Move") {
		chessBoard.MoveChess(Point(msg[4] - '0', msg[5] - '0'), Point(msg[6] - '0', msg[7] - '0'));
		respond = true;
		if (chessBoard.gameEnd) {
			host.BoardCast("Winner:" + std::to_string(chessBoard.winTeam));
		}
	}
	if (msg.substr(0, 7) == "GetMove") {
		Point point = Point(msg[7] - '0', msg[8] - '0');
		auto move = chessBoard.GetChessMove(point);
		for (auto p : move.second) {
			move.first.push_back(p);
		}
		host.SendMsg(client, DataConverter::Serialize("hint", move.first));
	}
	BackCallInstance->HostDealMsg(msg);
}

void GameManager::ClientFull() {
	cout << "client already full" << endl;
	BackCallInstance->HostClientFull();
}

void GameManager::ServerTerminate() {
	BackCallInstance->HostServerTerminate();
}
