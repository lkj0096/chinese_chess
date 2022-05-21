#pragma once
#include <QObject>
#include <QtWidgets/QApplication>
#include <string>
#include <vector>
#include "All_form.h"
#include "Point.h"
#include "Player.h"
using std::string, std::vector;

class MainUserInterface : public QObject {
	Q_OBJECT
private:
	QApplication* a; //main thread
	All_form* forms; //main thread
	int argc;
	char** argv;

	User user; // second thread
public:
	MainUserInterface(int argc, char* argv[]);

	/// main thread
	void run();
	/// end main thread

	void SelfGameStart() { forms->SelfGameStart(); user.playerSelfGame(); }

	//void AIGameStart(bool RorB) { forms->gamestart(RorB); }

	void LoadGame() {};

	//void LoadGameStart(bool RorB) { forms->gamestart(RorB); }

	void MultiGameStart(bool RorB) { forms->MultiGameStart(RorB); }

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
	void StartSelfGame() { user.playerSelfGame(); };

	/// <summary>
	/// Press again Button
	/// </summary>
	void SendAgain() {};

	/// <summary>
	/// Press Setting Button
	/// </summary>
	void Setting() {};

	/// <summary>
	/// Surr
	/// </summary>
	void Surr(string str) {
		//if (str == "BLsurr") user.SendMess("");
		//else if (str == "RDsurr") user.SendMess("");
	};

	void QuitAPP() { QCoreApplication::quit(); };
	///////////////////Event///////////////////

	//void PlayerInRoom();
	//void PlayerOutRoom();


	///////////////////Gaming///////////////////

	void MoveChess(Point pt1, Point pt2) {
		forms->MoveChess(pt1, pt2);
	};

	void ShowHintPos(vector<Point> pts) {
		forms->ShowHintPos(pts);
	};

	void HintPressed(Point pt1, Point pt2) { user.MoveChess(pt1, pt2); };
	void ChessPressed(Point pt) { user.GetHint(pt); };

	void CheckMate() { forms->CheckMate(); };
	
	//void HostEndGame(const bool RorB) { forms->EndGame_host(RorB); };
	//void ClientEndGame(const bool RorB) { forms->EndGame_client(RorB); };
	void EndGame(const bool RorB) { forms->EndGame(RorB); };

	void setTurn(const bool BlackTurn) { forms->setTurn(BlackTurn); };
	void setCanMove() { forms->setCanMove(); };
};