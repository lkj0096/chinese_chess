#include <iostream>
#include <string>
#include "MainUserInterface.h"
#include "NetworkClient.h"
#include "NetworkHost.h"
#include "ChessBoard.h"
#include "Point.h"
#include "DataConverter.h"
using namespace std;
int main() {
	vector<Point> points{ Point(1,3), Point(2,4), Point(88,5) };
	string str = DataConverter::Serialize(points);
	cout << str << endl;
	points = DataConverter::DeSerializePoints(str);
	str = DataConverter::Serialize(points);
	cout << str << endl;
	return 0;
	ChessBoard chessBoard;
	chessBoard.init();
	std::cout << chessBoard.ToString() << "\n";
	chessBoard.MoveChess(Point(2, 2), Point(2, 4));
	std::cout << chessBoard.ToString() << "\n";
	return 0;

	MainUserInterface UI;
	//string str;
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