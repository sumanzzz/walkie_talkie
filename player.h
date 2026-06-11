#pragma once
#include "raylib.h"
class Player
{
private:
	
	Vector3 position;
	float rotation;

public:
	Player();
	
	void update(float dt , float cameraAngle);
	
	Vector3 getPosition() const;

	float getrotation() const;
	void setRotation(float rot);
	

	
};
