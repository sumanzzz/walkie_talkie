#include "worldscene.h"
#include "raylib.h"

WorldScene::WorldScene()
{
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 95.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}
void WorldScene::update(float dt)
{
    player.update(dt);
}

void WorldScene::draw()
{
    BeginMode3D(camera);

    DrawPlane({ 0,0,0 }, { 50,50 }, WHITE);
    player.draw();

    EndMode3D();
}

