#pragma once
#include <WinSock2.h>

#include <vector>

class Server
{
private:
	SOCKET listenSocket;
	std::vector<SOCKET> clients;
	

public:
	Server();

	bool start(int port);
	void acceptClient();
	void handleClient(SOCKET clientSocket);
	
};