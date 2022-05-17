#pragma once

#include <Ws2tcpip.h>
#include <iostream>
#include <thread>
#include "Network.h";

void Network::start() {

	//NetworkDll Check
	WSAData wsaData;
	WORD DLLVSERION;
	DLLVSERION = MAKEWORD(2, 1);
	int err = WSAStartup(DLLVSERION, &wsaData);

	//Address Set
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	inet_pton(AF_INET, "0.0.0.0", (void*)&addr.sin_addr.S_un.S_addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(3141);

	//SOCKET For SERVER listen client
	SOCKET sListen;
	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, 2);
	//listen(sListen, SOMAXCONN);

	//SOCKET CLIENT which Connected on server
	SOCKET sConnect;
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

}