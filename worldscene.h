#pragma once
#include "scene.h"
#include "raylib.h"
#include "player.h"

class WorldScene : public Scene
{
private:
	Camera camera;
	Player player;
	float cameraAngle;
	Vector3 remotePlayerPosition;
	bool hasRemotePlayer;
	

public:
	WorldScene();
	
	void update(float dt) override;
	void draw() override;
	void setRemotePlayerPosition(Vector3 pos);

	Vector3 getPlayerPosition();
};