#include "MainUserInterface.h"
#include <regex>

MainUserInterface::MainUserInterface() {
}

void MainUserInterface::setX() {
	x = 4;
}

void MainUserInterface::SingleGame() {
}

void MainUserInterface::PlaySelf() {
}

void MainUserInterface::PlayAI() {
}

void MainUserInterface::LoadGame() {
	//void (MainUserInterface::* func)() = &MainUserInterface::setX;
	//(this->*func)();
	//user.LoadGame(this, &MainUserInterface::setX);
}

void MainUserInterface::SaveGame() {
}

void MainUserInterface::MultiGame() {
}

void MainUserInterface::CreateRoom() {
	user.CreateRoom();
}

void MainUserInterface::JoinRoom(string address) {
	user.JoinRoom(address);
}

void MainUserInterface::CloseHost() {
	user.CloseHost();
}

void MainUserInterface::CloseClient() {
	user.CloseClient();
}

void MainUserInterface::StartOnlineGame() {
	user.StartOnlineGame();
}

void MainUserInterface::Setting() {
}

void MainUserInterface::Back() {
}

void MainUserInterface::LeaveGame() {
}

void MainUserInterface::MoveChess() {
	user.MoveChess();
}
