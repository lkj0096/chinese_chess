#include "Player.h"
#include "MainUserInterface.h"
#include <functional>
void User::playerSelfGame() {
}

void User::playerAIGame() {
}

void User::LoadGame(MainUserInterface* instance, void(MainUserInterface::* func)()) {
	(instance->*func)();
}

//void User::LoadGame(MainUserInterface* instance) {
//	//using std::placeholders::_1;
//	//std::function<void()> f_add_display3 = std::bind(func, *instance, _1);
//	//std::function<void(const MainUserInterface&)> fun = func;
//	instance->setX();
//}
//void User::LoadGame() {
//	
//}

void User::CreateRoom() {
	gameManager.CreateRoom();
	client.Connect("127.0.0.1");
}

void User::JoinRoom(string address) {
	client.Connect(address);
}

void User::CloseHost() {
	gameManager.CloseHost();
	client.close();
}

void User::CloseClient() {
	client.close();
}

void User::StartOnlineGame() {
	gameManager.startGame();
}

void User::MoveChess() {
	client.Send("Move");
}
