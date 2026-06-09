#pragma once

#include <WinSock2.h>

class Client
{
private:
	SOCKET clientSocket;

	struct playerPacket
	{
		float x;
		float y;
		float z;
	};

public:
	Client();

	bool Connect(const char* ip, int port);

	void sendRequest();
};