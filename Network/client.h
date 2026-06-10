#pragma once

//#include <WinSock2.h>
#include "packet.h"

class Client
{
private:
	struct Impl;
	Impl* impl;


public:
	Client();

	bool Connect(const char* ip, int port);

	bool sendRequest(const PlayerPacket& packet);

	~Client();
};