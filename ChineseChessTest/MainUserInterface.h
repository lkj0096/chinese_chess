#pragma once

#include "Player.h"

class MainUserInterface {
	User user;
public:
	int x = 3;
	MainUserInterface();

	void setX();

	/// <summary>
	/// Press Sigle Game Button
	/// </summary>
	void SingleGame();

	/// <summary>
	/// Press Play Self Button
	/// </summary>
	void PlaySelf();

	/// <summary>
	/// Press Play AI Button
	/// </summary>
	void PlayAI();

	/// <summary>
	/// Press Load Game Button
	/// </summary>
	void LoadGame();


	/// <summary>
	/// Press Multi Game Button
	/// </summary>
	void MultiGame();

	/// <summary>
	/// Press Create Room Button
	/// </summary>
	void CreateRoom();

	/// <summary>
	/// Press Join Room Button
	/// </summary>
	void JoinRoom(string);

	/// <summary>
	/// Press Back Button when user is host
	/// </summary>
	void CloseHost();

	/// <summary>
	/// Press Back Button when user is client
	/// </summary>
	void CloseClient();

	/// <summary>
	/// Press Start Game when user is host
	/// </summary>
	void StartOnlineGame();


	/// <summary>
	/// Press Setting Button
	/// </summary>
	void Setting();


	/// <summary>
	/// Press Back Button
	/// </summary>
	void Back();


	/// <summary>
	/// Press Leave App Button
	/// </summary>
	void LeaveGame();


	///////////////////Event///////////////////

	//void PlayerInRoom();
	//void PlayerOutRoom();


	///////////////////Gaming///////////////////

	void MoveChess();
};