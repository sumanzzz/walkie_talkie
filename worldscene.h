#pragma once
#include "scene.h"
#include "raylib.h"
#include "player.h"
#include <unordered_map>

class WorldScene : public Scene
{
private:
	Camera camera;
	Player player;
	Model bunny;
	float cameraAngle;

	struct RemotePlayer
	{
		Vector3 position;
		float rotation;
	};

	std::unordered_map<int, RemotePlayer> remotePlayers;

	//bool hasRemotePlayer;
	

public:
	WorldScene();
	
	void update(float dt) override;
	void draw() override;
	float getPlayerRotation();
	void updateRemotePLayer(int id, Vector3 pos , float rot);
	void removeRemotePlayer(int id);
	Vector3 getPlayerPosition();
};