#pragma once
#include <WinSock2.h>

class Server
{
private:
	SOCKET listenSocket;
	SOCKET clientSocket;
	


public:
	Server();

	bool start(int port);
	void acceptClient();
	void sendResponse();
};