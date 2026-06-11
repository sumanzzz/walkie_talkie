#pragma once

struct PlayerPacket
{
	int playerId;

	float x;
	float y;
	float z;

	bool disconnected;
};