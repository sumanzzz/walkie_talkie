#include "worldscene.h"
#include "raylib.h"
#include "raymath.h"

WorldScene::WorldScene()
{
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 65.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    cameraAngle = 0.0f;

    hasRemotePlayer = false;
    remotePlayerPosition = { 5, 1 , 0 };
}

void WorldScene::update(float dt)
{
    player.update(dt , cameraAngle);
    cameraAngle -= GetMouseDelta().x * 0.005f;
    Vector3 playerPos = player.getPosition();

    float radius = 5.0f;

    camera.position =
    {
        playerPos.x + sinf(cameraAngle) * radius,
        playerPos.y + 3.0f,
        playerPos.z + cosf(cameraAngle) * radius
    };

    camera.target =
    {
        playerPos.x,
        playerPos.y + 1.0f,
        playerPos.z
    };
}
Vector3 WorldScene::getPlayerPosition()
{
    return player.getPosition();
}

void WorldScene::setRemotePlayerPosition(Vector3 pos)
{
    remotePlayerPosition = pos;
    hasRemotePlayer = true;
}

void WorldScene::draw()
{
    BeginMode3D(camera);

    DrawPlane({ 0,0,0 }, { 50,50 }, WHITE);
    if (hasRemotePlayer)
    {
        DrawCube(remotePlayerPosition, 1, 1, 1, RED);
    }
    
    DrawGrid(50, 1.0f);

    player.draw();

    EndMode3D();
}

