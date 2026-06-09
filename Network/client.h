#pragma once

#include <WinSock2.h>

class Client
{
private:
	SOCKET clientSocket;
public:
	Client();

	bool Connect(const char* ip, int port);

	void sendRequest();
};