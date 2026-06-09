#include "worldscene.h"
#include "raylib.h"

WorldScene::WorldScene()
{
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 65.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}
void WorldScene::update(float dt)
{
    player.update(dt);

    Vector3 playerPos = player.getPosition();

    camera.position =
    {
        playerPos.x,
        playerPos.y + 2.0f,
        playerPos.z + 4.0f
    };

    camera.target =
    {
        playerPos.x,
        playerPos.y,
        playerPos.z
    };
}

void WorldScene::draw()
{
    BeginMode3D(camera);

    DrawPlane({ 0,0,0 }, { 50,50 }, WHITE);
    //DrawCube({ 5,1,5 }, 1, 1, 1, RED);
    player.draw();

    EndMode3D();
}

