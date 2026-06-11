#pragma once
#include "raylib.h"
class Player
{
private:
	
	Vector3 position;
public:
	Player();
	
	void update(float dt , float cameraAngle);
	
	Vector3 getPosition() const;

	
};
