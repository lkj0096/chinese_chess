#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <Ws2tcpip.h>
#include <string>
#include <thread>

using namespace std;

class User;

class NetworkClient {
	User* BackCallInstance;
	SOCKET  sConnect;
	thread* listenThread;
private:
	void Listening(SOCKET);
public:
	NetworkClient(User* ins);
	void Send(string);
	void Connect(string);
	void close();
};