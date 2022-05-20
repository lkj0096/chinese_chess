#include "OfflineGameManager.h"

void OfflineGameManager::init() {
	chessBoard.init();
}

void OfflineGameManager::RandomTeam() {
}

int OfflineGameManager::getTurnIndex() {
	return 0;
}

OfflineGameManager::OfflineGameManager(User* ins) {
	TurnIndex = 0;
	Gaming = true;
	BackCallInstance = ins;
}
