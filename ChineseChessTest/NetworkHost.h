#pragma once

#include "Network.h"
#include <Ws2tcpip.h>
#include <string>
#include <thread>
#include <vector>
#include <map>

class GameManager;

class NetworkHost : public Network {
	//std::vector<std::thread*> players;
	GameManager* BackCallInstance;

	SOCKET server;
	SOCKADDR_IN serverAddr;
	int serverAddrLen;
	bool serverOpen;

	std::thread* waitingThread;

	void Listening(int, SOCKET, SOCKADDR_IN);
	void WaitingClient();
public:
	NetworkHost(GameManager*);

	std::map<SOCKET, std::thread*> players;

	std::vector<SOCKET> getPlayers();

	/// <summary>
	/// Open listen socket.
	/// </summary>
	void OpenServer();

	/// <summary>
	/// Close listen socket listen thread.
	/// </summary>
	void CloseServer();

	/// <summary>
	/// send msg
	/// </summary>
	/// <param name="code"></param>
	void SendMsg(int code);
	void SendMsg(int code, std::string msg);
	void SendMsg(SOCKET targetClent, std::string msg);

	/// <summary>
	/// Send msg to all client
	/// </summary>
	/// <param name="msg"></param>
	void BoardCast(std::string msg);
};