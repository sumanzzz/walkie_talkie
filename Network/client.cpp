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
    playerPacket packet;
    packet.x = 2.0f;
    packet.y = 3.0f;
    packet.z = 2.5f;
    while (true)
    {
        packet.x += 2.0f;
        packet.y += 1.0f;
        packet.z += 3.0f;

        send(clientSocket, (char*)&packet, sizeof(packet), 0);
        Sleep(100);
    }
    

   
}