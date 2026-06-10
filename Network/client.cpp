#include <WinSock2.h>
#include <ws2tcpip.h>

#include "client.h"

#include <iostream>

struct Client::Impl
{
    SOCKET clientSocket;
};

Client::Client()
{
    impl = new Impl();
    impl->clientSocket = INVALID_SOCKET;
}

bool Client::Connect(const char* ip, int port)
{
	WSADATA wsadata;

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        std::cout << "WSAStartup failed\n";
        return false;
    }

    impl->clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    

   
    if(impl->clientSocket == INVALID_SOCKET)
    {
        std::cout << "Socket creation failed.." << std::endl;
        return false;
    }

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    serverAddr.sin_addr.s_addr = inet_addr(ip);

    if (connect(impl->clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cout<<"Connection failed"<<std::endl;
        return false;
    }

    std::cout << "Connected to the server...." << std::endl;

    return true;
}
bool Client::sendRequest(const PlayerPacket& packet)
{
    int result = send(impl->clientSocket, (const char*)&packet, sizeof(packet) , 0);
    std::cout << "Sending: "<< packet.x << " "<< packet.y << " "<< packet.z << std::endl;   
    return result != SOCKET_ERROR;
}

Client::~Client()
{
    delete impl;
}