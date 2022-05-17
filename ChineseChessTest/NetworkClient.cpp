#include "NetworkClient.h"
#include "DebugLogger.h"
#include <thread>

void NetworkClient::Listening(SOCKET server) {
    char message[200];
    while (1) {
        ZeroMemory(message, 200);
        int r = recv(server, message, sizeof(message), 0);
        if (r == -1 || r == 0) break;
        if (message == "your turn") {

        }

        if (message[0] >= '0' && message[0] <= '9') {

        } else {

        }

        cout << message << endl;
    }
    DebugLogger::Print(0, __LINE__, vector({ "server cancel" }));
}

void NetworkClient::Send(string msg) {
    send(sConnect, msg.c_str(), strlen(msg.c_str()), 0);
}

void NetworkClient::Connect(string address) {
    WSAData wsaData;
    WORD DLLVersion;
    DLLVersion = MAKEWORD(2, 1);
    int r = WSAStartup(DLLVersion, &wsaData);

    sConnect = socket(AF_INET, SOCK_STREAM, NULL);

    SOCKADDR_IN addr;
    inet_pton(AF_INET, address.c_str(), (void*)&addr.sin_addr.S_un.S_addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3141);
    
    int tryConnectTime = 5;
    while (tryConnectTime--) {
        int connectCode = connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
        if (connectCode == 0) break;
        cout << "code : " << connectCode << " || tryConnect " << 5 - tryConnectTime << " : failed" << endl;
        Sleep(1000);
    }
    if (!tryConnectTime) return;


    listenThread = new thread(&NetworkClient::Listening, this, sConnect);
    listenThread->detach();

}



void NetworkClient::close() {
    listenThread->~thread();
    delete listenThread;
    closesocket(sConnect);
    WSACleanup();
    cout << "client close" << endl;
}
