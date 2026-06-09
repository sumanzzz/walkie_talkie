#include "server.h"

#include <iostream>
#include <WS2tcpip.h> // winsock2 extension for TCP/IP

#pragma comment(lib , "Ws2_32.lib")

Server::Server()
{
	listenSocket = INVALID_SOCKET;
	clientSocket = INVALID_SOCKET;
}
bool Server::start(int port)
{
	WSADATA wsadata;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) 
	{
		std::cout << "WSAStartup failed\n";
		return false;
	}

	listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (listenSocket == INVALID_SOCKET)
	{
		std::cout << "Socket creation failed..." << std::endl;
		return false;
	}

	sockaddr_in serverAddr{};
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(listenSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		std::cout << "bind failed..." << std::endl;
		return false;
	}

	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		std::cout << "Failed to listen..." << std::endl;
		return false;
	}

	std::cout << "Server listening on port :" << port << std::endl;

	return true;

}

void Server::acceptClient()
{
	std::cout << "Waiting for client..." << std::endl;

	clientSocket = accept(listenSocket, nullptr, nullptr);

	if (clientSocket == INVALID_SOCKET)
	{
		std::cout << "Accept Failed...." << std::endl;
		return;
	}
	std::cout << "Client connected !" << std::endl;
}

void Server::sendResponse()
{
	Packet packet;

	while (true)
	{
		int bytesread = recv(clientSocket, (char*)&packet, sizeof(packet), 0);

		if (bytesread > 0)
		{
			std::cout << "Recieved :" << packet.x << " " << packet.y << " " << packet.z << std::endl;
		}
	}
	
}