#include "player.h"
#include <iostream>

Player::Player()
{
	
	
	position = { 0 , 1 , 0 };
	rotation = 0.0f;
}

void Player::update(float dt , float cameraAngle)
{
	float speed = 5.0f;

	Vector3 forward =
	{
		sinf(cameraAngle),
		0.0f,
		cosf(cameraAngle)
	};

	Vector3 right =
	{
		forward.z,
		0.0f,
		-forward.x
	};

	if (IsKeyPressed(KEY_W))
	{
		position.x -= forward.x * speed * dt;
		position.z -= forward.z * speed * dt;
	}
	if (IsKeyPressed(KEY_S))
	{
		position.x += forward.x * speed * dt;
		position.z += forward.z * speed * dt;
	}
	if (IsKeyPressed(KEY_A))
	{
		position.x -= right.x * speed * dt;
		position.z -= right.z * speed * dt;
	}
	if (IsKeyPressed(KEY_D))
	{
		position.x += right.x * speed * dt;
		position.z += right.z * speed * dt;
	}
}

Vector3 Player::getPosition() const
{
	return position;
}

float Player::getrotation() const
{
	return rotation;
}
void Player::setRotation(float rot)
{
	rotation = rot;
}
