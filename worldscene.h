#pragma once
#include "scene.h"
#include "raylib.h"

class WorldScene : public Scene
{
private:
	Camera camera;
public:
	WorldScene();
	
	void update(float dt) override;
	void draw() override;
};