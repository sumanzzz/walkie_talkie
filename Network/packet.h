#pragma once

struct PlayerPacket
{
	int playerId;

	float x;
	float y;
	float z;
	float rotation;
	bool disconnected;
};