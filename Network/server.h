#pragma once
#include <WinSock2.h>

class Server
{
private:
	SOCKET listenSocket;
	SOCKET clientSocket;
	
	struct Packet
	{
		float x;
		float y;
		float z;
	};


public:
	Server();

	bool start(int port);
	void acceptClient();
	void sendResponse();
};