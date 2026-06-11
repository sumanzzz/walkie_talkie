#include "worldscene.h"
#include "raylib.h"
#include "raymath.h"

WorldScene::WorldScene()
{
    bunny = LoadModel("assets/bunny2.glb");
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 65.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    cameraAngle = 0.0f;

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

void WorldScene::updateRemotePLayer(int id, Vector3 pos)
{
    remotePlayers[id] = pos;
}
void WorldScene::removeRemotePlayer(int id)
{
    remotePlayers.erase(id);
}


void WorldScene::draw()
{
    BeginMode3D(camera);

    DrawPlane({ 0,0,0 }, { 50,50 }, WHITE);
    Vector3 playerPos = player.getPosition();
    playerPos.y -= 0.6f;
    DrawModel(bunny, playerPos, 1.0f, WHITE);
    for (auto& player : remotePlayers)
    {
        //DrawCube(player.second, 1.0f, 1.0f, 1.0f, RED);
        Vector3 remotePlayerPos = player.second;
        remotePlayerPos.y -= 0.6f;
        DrawModel(bunny, remotePlayerPos, 1.0f, PINK);
    }
    
    DrawGrid(50, 1.0f);

    

    EndMode3D();
}

