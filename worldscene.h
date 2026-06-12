#pragma once
#include "scene.h"
#include "raylib.h"
#include "player.h"
#include <unordered_map>
#include <string>

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
		std::string username;

		std::string currentMessage;
		float messageTimer;
	};

	std::unordered_map<int, RemotePlayer> remotePlayers;

	
	

public:
	WorldScene();
	
	void update(float dt) override;
	void draw() override;
	float getPlayerRotation();
	void updateRemotePLayer(int id, Vector3 pos , float rot , std::string username);
	void updateRemotePlayerChat(int id, std::string message);
	void removeRemotePlayer(int id);
	Vector3 getPlayerPosition();
};