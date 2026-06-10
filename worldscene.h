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

public:
	WorldScene();
	
	void update(float dt) override;
	void draw() override;

	Vector3 getPlayerPosition();
};