#pragma once
#include "raylib.h"
class Player
{
private:
	Vector3 position;
public:
	Player();
	
	void update(float dt , float cameraAngle);
	void draw();
	Vector3 getPosition() const;
};
