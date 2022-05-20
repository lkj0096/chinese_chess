#pragma once
#include "NetworkClient.h"
#include "NetworkHost.h"
#include "GameManager.h"
#include "OfflineGameManager.h"
class MainUserInterface;
class Player {
	void GetMoveTo() {};
};

class User {
	MainUserInterface* instance;

	GameManager gameManager = NULL;
	OfflineGameManager offGameManager = NULL;

	//For Online
	NetworkClient client = NULL;
	
public:
	User();

	/// <summary>
	/// Bridge UI -- GM
	/// </summary>
	void playerSelfGame();

	/// <summary>
	/// Bridge UI -- GM
	/// </summary>
	void playerAIGame();

	/// <summary>
	/// Bridge UI -- 
	/// </summary>
	void LoadGame(MainUserInterface* instance, void(MainUserInterface::*func)());

	//For Online

	/// <summary>
	/// Bridge UI -- GM
	/// </summary>
	void CreateRoom();

	/// <summary>
	/// Bridge UI -- NC
	/// </summary>
	void JoinRoom(string);

	/// <summary>
	/// Bridge UI -- GM
	/// </summary>
	void CloseHost();

	/// <summary>
	/// Bridge UI -- NC
	/// </summary>
	void CloseClient();

	/// <summary>
	/// Bridge UI -- GM
	/// </summary>
	void StartOnlineGame();


	///////////////////Gaming///////////////////

	void MoveChess(Point);

	/// BackCall
	void HostClientDisConnect(SOCKET);
	void HostDealMsg(std::string);
	void HostClientFull();
	void HostServerTerminate();

	void ClientDealMsg(std::string);
	void ClientNotifyServerCancel();
	void ClientTryConnect(int);

};

class AI{

};