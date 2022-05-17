#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <Ws2tcpip.h>
#include <string>
#include <thread>

using namespace std;

class NetworkClient {
	SOCKET  sConnect;
	thread* listenThread;
private:
	void Listening(SOCKET);
public:
	void Send(string);
	void Connect(string);
	void close();
};