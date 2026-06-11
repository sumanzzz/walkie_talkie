#include <WinSock2.h>
#include <WS2tcpip.h> // winsock2 extension for TCP/IP

#include "server.h"
#include "packet.h"
#include <iostream>
#include <thread>
#include <algorithm>


#pragma comment(lib , "Ws2_32.lib")

Server::Server()
{
	listenSocket = INVALID_SOCKET;
	nextPlyerId = 1;
	
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
	while (true)
	{
		std::cout << "Waiting for client..." << std::endl;

		SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);

		if (clientSocket == INVALID_SOCKET)
		{
			std::cout << "Accept Failed...." << std::endl;
			return;
		}

		clients.push_back(clientSocket);
		int assignedId = nextPlyerId++;
		playerIds[clientSocket] = assignedId;

		std::cout << "Client connected !" << std::endl;
		std::cout << "Assigned Player ID : " << assignedId << std::endl;
		std::cout << "Client count : " << clients.size() << std::endl;

		std::thread(&Server::handleClient, this, clientSocket).detach();
	}
	
}

void Server::handleClient(SOCKET clientSocket)
{
	PlayerPacket packet;

	while (true)
	{
		int bytesread = recv(clientSocket, (char*)&packet, sizeof(packet), 0);
		if (bytesread == -1)
		{
			std::cout << "Client disconnected.." << std::endl;
			PlayerPacket disconnectedPacket{};

			disconnectedPacket.disconnected = true;

			disconnectedPacket.playerId = playerIds[clientSocket];

			for (SOCKET other : clients)
			{
				if (other != clientSocket)
				{
					send(other, (char*)&disconnectedPacket, sizeof(disconnectedPacket), 0);
				}
			}
			break;
		}
		if (bytesread > 0)
		{
			packet.playerId = playerIds[clientSocket];

			//std::cout << "Thread : " <<std::this_thread::get_id() <<" Position : "<< packet.x << " " << packet.y << " " << packet.z << std::endl;

			for (SOCKET other : clients)
			{
				if (other != INVALID_SOCKET && other != clientSocket)
				{
					send(other, (char*)&packet, sizeof(packet), 0);
				}
			}
		}
	}
	closesocket(clientSocket);
	clients.erase(std::remove(clients.begin(), clients.end(), clientSocket), clients.end());
	playerIds.erase(clientSocket);
	
}