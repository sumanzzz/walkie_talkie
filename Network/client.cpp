#include "client.h"

#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>


Client::Client()
{
	clientSocket = INVALID_SOCKET;
}

bool Client::Connect(const char* ip, int port)
{
	WSADATA wsadata;

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        std::cout << "WSAStartup failed\n";
        return false;
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(clientSocket == INVALID_SOCKET)
    {
        std::cout << "Socket creation failed.." << std::endl;
        return false;
    }

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    serverAddr.sin_addr.s_addr = inet_addr(ip);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cout<<"Connection failed"<<std::endl;
        return false;
    }

    std::cout << "Connected to the server...." << std::endl;

    return true;
}
void Client::sendRequest()
{
    const char* msg = "Hello to server from client";

    send(clientSocket, msg, strlen(msg) , 0);
}