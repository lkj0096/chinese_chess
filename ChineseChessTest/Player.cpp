#include "Player.h"
#include "MainUserInterface.h"
#include <functional>
#include "DataConverter.h"
User::User() {
	client = NetworkClient(this);
	gameManager = GameManager(this);
}
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

void User::MoveChess(Point p) {
	client.Send("Move" + std::to_string(p.x) + std::to_string(p.y));
}

void User::HostClientDisConnect(SOCKET) {
}

void User::HostDealMsg(std::string) {
}

void User::HostClientFull() {
}

void User::HostServerTerminate() {
}

void User::ClientDealMsg(std::string msg) {
	if (msg.substr(0, 4) == "hint") {
		std::vector<Point> hint = DataConverter::DeSerializePoints(msg);
	}
	//Turn[xyxy]
	if (msg.substr(0, 4) == "Turn") {

	}
	//Winner:[team]
	if (msg.substr(0, 6) == "Winner") {

	}
}

void User::ClientNotifyServerCancel() {
}

void User::ClientTryConnect(int) {
}
