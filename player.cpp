#include "player.h"

Player::Player()
{
	position = { 0 , 1 , 0 };
}

void Player::update(float dt)
{
	float speed = 5.0f;

	if (IsKeyPressed(KEY_W)) position.z -= speed * dt;
	if (IsKeyPressed(KEY_S)) position.z += speed * dt;
	if (IsKeyPressed(KEY_A)) position.x -= speed * dt;
	if (IsKeyPressed(KEY_D)) position.x += speed * dt;
}

void Player::draw()
{
	DrawCube(position, 1, 1, 1, BLUE);
}

Vector3 Player::getPosition() const
{
	return position;
}