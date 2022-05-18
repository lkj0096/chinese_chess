#pragma once
#include <QtWidgets/QApplication>
#include <string>
#include <vector>
#include "All_form.h"
#include "Point.h"
#ifdef PLAYER_H
#include "Player.h"
#endif // PLAYER_H



using std::string, std::vector;

class MainUserInterface {
	QApplication* a;
	All_form* forms;
	int argc;
	char** argv;

#ifdef PLAYER_H
	User user;
#endif // PLAYER_H
public:
	MainUserInterface(int argc, char* argv[]);
	int x = 3;
	
	/// main thread
	void run();
	/// end main thread
	
	void setX() {};

	/// <summary>
	/// Press Sigle Game Button
	/// </summary>
	void SingleGame() {};

	/// <summary>
	/// Press Play Self Button
	/// </summary>
	void PlaySelf() {};

	/// <summary>
	/// Press Play AI Button
	/// </summary>
	void PlayAI() {};

	/// <summary>
	/// Press Load Game Button
	/// </summary>
	void LoadGame() {};


	/// <summary>
	/// Press Multi Game Button
	/// </summary>
	void MultiGame() {};

	/// <summary>
	/// Press Create Room Button
	/// </summary>
	void CreateRoom() {};

	/// <summary>
	/// Press Join Room Button
	/// </summary>
	void JoinRoom(string) {};

	/// <summary>
	/// Press Back Button when user is host
	/// </summary>
	void CloseHost() {};

	/// <summary>
	/// Press Back Button when user is client
	/// </summary>
	void CloseClient() {};

	/// <summary>
	/// Press Start Game when user is host
	/// </summary>
	void StartOnlineGame() {};


	/// <summary>
	/// Press Setting Button
	/// </summary>
	void Setting() {};


	/// <summary>
	/// Press Back Button
	/// </summary>
	void Back() {};


	/// <summary>
	/// Press Leave App Button
	/// </summary>
	void LeaveGame() {};

	void QuitAPP() { QCoreApplication::quit(); };
	///////////////////Event///////////////////

	//void PlayerInRoom();
	//void PlayerOutRoom();


	///////////////////Gaming///////////////////

	void MoveChess(Point pt) {
		forms->MoveChess(pt);
	};

	void ShowHintPos(vector<Point> pts1, vector<Point> pts2) {
		forms->ShowHintPos(pts1,pts2);
	};

	void HintPressed(Point, Point) {};
	void ChessPressed(Point) {};

	void CheckMate() { forms->CheckMate(); };
	void EndGame() { forms->EndGame(); };
};