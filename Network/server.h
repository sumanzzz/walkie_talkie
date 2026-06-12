#pragma once
#include <WinSock2.h>

#include <vector>
#include <unordered_map>
#include <string>

class Server
{
private:
	SOCKET listenSocket;
	std::vector<SOCKET> clients;
	std::unordered_map<SOCKET, int> playerIds;
	std::unordered_map<int, std::string> usernames;
	int nextPlyerId;
	

public:
	Server();

	bool start(int port);
	void acceptClient();
	void handleClient(SOCKET clientSocket);
	
};