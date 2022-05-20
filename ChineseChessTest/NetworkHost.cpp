#pragma comment(lib, "Ws2_32.lib")
#pragma once

#include "NetworkHost.h";
#include <Ws2tcpip.h>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include "DebugLogger.h";
#include "GameManager.h"

using namespace std;

void NetworkHost::Listening(int index, SOCKET client, SOCKADDR_IN clientAddr) {
	char message[200];
	int r;
	while (1) {
		ZeroMemory(message, 200);
		r = recv(client, message, 200, 0);
		if (r == -1 || r == 0) {
			break;
		}
		BackCallInstance->DealMsg(client, string(message));
		DebugLogger::Print(0, __LINE__, vector({ client }));
		DebugLogger::Print(0, __LINE__, vector({ ":"}));
		DebugLogger::Print(0, __LINE__, vector({ message }));
		DebugLogger::Print(0, __LINE__, vector({ r }));
	}
	delete players[client];
	players.erase(client);
	BackCallInstance->ClientDisConnect(client);
	DebugLogger::Print(0, __LINE__, vector({ client }));
	DebugLogger::Print(0, __LINE__, vector({ "disconnect :" }));
}

void NetworkHost::WaitingClient() {
	serverOpen = true;

	WSAData wsaData;
	WORD DLLVersion;
	DLLVersion = MAKEWORD(2, 1);
	int r = WSAStartup(DLLVersion, &wsaData);
	

	serverAddrLen = sizeof(serverAddr);
	inet_pton(AF_INET, "0.0.0.0", (void*)&serverAddr.sin_addr.S_un.S_addr);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(3141);

	server = socket(AF_INET, SOCK_STREAM, NULL);
	
	int b = bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	int l = listen(server, SOMAXCONN);

	DebugLogger::Print(0, __LINE__, vector({ b, l }));

	while (true) {
		if (players.size() >= 2 && serverOpen) {
			BackCallInstance->ClientFull();
		}
		if (players.size() >= 2) {
			closesocket(server);
			serverOpen = false;
			continue;
		}

		if (!serverOpen) {
			server = socket(AF_INET, SOCK_STREAM, NULL);
			bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
			listen(server, SOMAXCONN);
		}

		SOCKET sConnect;
		sConnect = socket(AF_INET, SOCK_STREAM, NULL);
		b = bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
		l = listen(server, SOMAXCONN);

		SOCKADDR_IN clientAddr;
		DebugLogger::Print(0, __LINE__, vector({ "wating..." }));

		if (sConnect = accept(server, (SOCKADDR*)&clientAddr, &serverAddrLen)) {
			if (sConnect == -1) {
				BackCallInstance->ServerTerminate();
				DebugLogger::Print(0, __LINE__, vector({ "server terminate" }));
				break;
			}

			DebugLogger::Print(0, __LINE__, vector({ sConnect }));
			//enable_keepalive(sConnect);
			SOCKADDR_IN clientaddr;
			clientaddr = clientAddr;

			const char* sendbuf = "who r u?";
			send(sConnect, sendbuf, (int)strlen(sendbuf), 0);

			thread* t = new thread(&NetworkHost::Listening, this, players.size() - 1, sConnect, clientaddr);
			(*t).detach();
			players[sConnect] = t;
		}
	}
}

NetworkHost::NetworkHost(GameManager* ins) {
	BackCallInstance = ins;
}

std::vector<SOCKET> NetworkHost::getPlayers() {
	vector<SOCKET> vecPlayer;
	for (auto player : players) {
		vecPlayer.push_back(player.first);
	}
	return vecPlayer;
}

void NetworkHost::OpenServer() {
	//WSAData wsaData;
	//WORD DLLVersion;
	//DLLVersion = MAKEWORD(2, 1);
	//int r = WSAStartup(DLLVersion, &wsaData);

	//serverAddrLen = sizeof(serverAddr);
	//inet_pton(AF_INET, "0.0.0.0", (void*)&serverAddr.sin_addr.S_un.S_addr);
	//serverAddr.sin_family = AF_INET;
	//serverAddr.sin_port = htons(3141);

	//server = socket(AF_INET, SOCK_STREAM, NULL);
	waitingThread = new thread(&NetworkHost::WaitingClient, this);
	waitingThread->detach();
}

void NetworkHost::CloseServer() {
	for (auto player : players) {
		const char* sendbuf = "Server is terminated.";
		send(player.first, sendbuf, (int)strlen(sendbuf), 0);
		player.second->~thread();
		delete player.second;
	}
	players.clear();
	
	waitingThread->~thread();
	if(waitingThread) delete waitingThread;
	serverOpen = false;
	closesocket(server);
	WSACleanup();
}

void NetworkHost::SendMsg(int code) {};
//void NetworkHost::SendMsg(int code, string msg) {};
void NetworkHost::SendMsg(int code, std::string msg) {
	
}

void NetworkHost::SendMsg(SOCKET targetClent, std::string msg) {
	send(targetClent, msg.c_str(), (int)strlen(msg.c_str()), 0);
}

void NetworkHost::BoardCast(std::string msg) {
	for (auto player : players) {
		send(player.first, msg.c_str(), (int)strlen(msg.c_str()), 0);
	}
}


void enable_keepalive(int sock) {
	int yes = 1;
	setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, (const char*)&yes, sizeof(int));

	int idle = 20;
	setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, (const char*)&idle, sizeof(int));

	int interval = 5;
	setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL, (const char*)&interval, sizeof(int));

	int maxpkt = 5;
	setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT, (const char*)&maxpkt, sizeof(int));

	unsigned int timeout = 10000;  // 10s
	//setsockopt(sock, IPPROTO_TCP, TCP_, (const char*)&timeout, sizeof(timeout));
}
