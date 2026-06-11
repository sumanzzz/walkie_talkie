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
	float cameraAngle;
	std::unordered_map<int, Vector3> remotePlayers;

	//bool hasRemotePlayer;
	

public:
	WorldScene();
	
	void update(float dt) override;
	void draw() override;
	void updateRemotePLayer(int id, Vector3 pos);
	
	Vector3 getPlayerPosition();
};