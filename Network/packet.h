#pragma once

struct PlayerPacket
{
	int playerId;
	float x;
	float y;
	float z;
	float rotation;
	bool disconnected;
	char username[32];

	bool isChat;
	char message[32];
};

