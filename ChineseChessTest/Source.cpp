#include <iostream>
#include <string>
#include "MainUserInterface.h"
#include "NetworkClient.h"
#include "NetworkHost.h"


int main() {
	MainUserInterface UI;
	string str;
	while (std::cin >> str) {
		switch (str[0]) {
		case '0':
			UI.CreateRoom();
			break;
		case '1':
			//cin >> str;
			str = "127.0.0.1";
			UI.JoinRoom(str);
			break;
		case '2':
			UI.CloseHost();
			break;
		case '3':
			UI.CloseClient();
			break;
		case '4':
			UI.StartOnlineGame();
			break;
		case '5':
			UI.MoveChess();
			break;
		case '6':
			UI.LoadGame();
			cout << UI.x << endl;
		default:
			break;
		}
	}
	
	//if (i & 1) {
	//	NetworkHost host;
	//	//host.start();
	//	//host.Run();
	//	host.OpenServer();
	//} else {
	//	NetworkClient client;
	//	client.Connect("");
	//}
	return 0;
}