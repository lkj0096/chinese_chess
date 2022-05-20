#pragma once
#include <QtWidgets/QApplication>
#include <string>
#include <vector>
#include "All_form.h"
#include "Point.h"
#include "Player.h"




using std::string, std::vector;

class MainUserInterface {
	QApplication* a;
	All_form* forms;
	int argc;
	char** argv;

	User user;

public:
	MainUserInterface(int argc, char* argv[]);
	int x = 3;
	
	/// main thread
	void run();
	/// end main thread
	
	void setX() {};

	void SelfGameStart(bool RorB) { forms->gamestart(RorB); }

	void AIGameStart(bool RorB) { forms->gamestart(RorB); }

	void LoadGame();

	void LoadGameStart(bool RorB) { forms->gamestart(RorB); }

	void MultiGameStart(bool RorB) { forms->gamestart(RorB); }

	/// <summary>
	/// Press Create Room Button
	/// </summary>
	void CreateRoom() {	user.CreateRoom(); };

	/// <summary>
	/// Press Join Room Button
	/// </summary>
	void JoinRoom(string address) { user.JoinRoom(address); };

	/// <summary>
	/// Press Back Button when user is host
	/// </summary>
	void CloseHost() { user.CloseHost(); };

	/// <summary>
	/// Press Back Button when user is client
	/// </summary>
	void CloseClient() { user.CloseClient(); };

	/// <summary>
	/// Press Start Game when user is host
	/// </summary>
	void StartOnlineGame() { user.StartOnlineGame(); };


	/// <summary>
	/// Press Setting Button
	/// </summary>
	void Setting() {};


	/// <summary>
	/// Press Back Button
	/// </summary>

	/// <summary>
	/// Surr
	/// </summary>
	void Surr(string str) {
		if (str == "BLsurr") user.SendMess("");
		else if (str == "RDsurr") user.SendMess("");
	};

	void QuitAPP() { QCoreApplication::quit(); };
	///////////////////Event///////////////////

	//void PlayerInRoom();
	//void PlayerOutRoom();


	///////////////////Gaming///////////////////

	void MoveChess(Point pt) {
		forms->MoveChess(pt);
	};

	void ShowHintPos(vector<Point> pts) {
		forms->ShowHintPos(pts);
	};

	void HintPressed(Point, Point) {};
	void ChessPressed(Point) {};

	void CheckMate() { forms->CheckMate(); };
	void EndGame() { forms->EndGame(); };

	void setTurn(const bool BlackTurn) { forms->setTurn(BlackTurn); };
};