#include "worldscene.h"
#include "raylib.h"
#include "raymath.h"

WorldScene::WorldScene()
{
    bunny = LoadModel("assets/bunny3.glb");
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 65.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    cameraAngle = 0.0f;

}

void WorldScene::update(float dt)
{
    if (!isTyping)
    {
        player.update(dt, cameraAngle);
    }
    
    cameraAngle -= GetMouseDelta().x * 0.005f;
    player.setRotation(cameraAngle);
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
    for (auto& player : remotePlayers)
    {
        if (player.second.messageTimer > 0)
        {
            player.second.messageTimer -= dt;
        }
    }
}
Vector3 WorldScene::getPlayerPosition()
{
    return player.getPosition();
}
float WorldScene::getPlayerRotation()
{
    return player.getrotation();
}
void WorldScene::updateRemotePLayer(int id, Vector3 pos , float rot ,std::string username)
{
    remotePlayers[id].position = pos;
    remotePlayers[id].rotation = rot;
    remotePlayers[id].username = username;
    
}
void WorldScene::updateRemotePlayerChat(int id, std::string message)
{
    remotePlayers[id].currentMessage = message;
    remotePlayers[id].messageTimer = 5.0f;
}
void WorldScene::removeRemotePlayer(int id)
{
    remotePlayers.erase(id);
}
void WorldScene::setCurrentInput(const std::string& input)
{
    currentInput = input;
}
void WorldScene::setIsTyping(bool state)
{
    isTyping = state;
}

void WorldScene::draw()
{
    BeginMode3D(camera);

    DrawPlane({ 0,0,0 }, { 50,50 }, WHITE);
    Vector3 playerPos = player.getPosition();
    playerPos.y -= 0.6f;
    DrawModelEx(bunny, playerPos, { 0 , 1, 0 }, player.getrotation() * RAD2DEG+ 90.f, { 1,1,1 }, WHITE);

    
    for (auto& player : remotePlayers)
    {
        //DrawCube(player.second, 1.0f, 1.0f, 1.0f, RED);
        Vector3 remotePlayerPos = player.second.position;
        remotePlayerPos.y -= 0.6f;
        DrawModelEx(bunny, remotePlayerPos, {0,1,0},player.second.rotation * RAD2DEG + 90.0f,{1,1,1}, PINK);
        
    }
   
    
    DrawGrid(50, 1.0f);

    

    EndMode3D();
    for (auto& player : remotePlayers)
    {
        Vector3 textPos = player.second.position;
        textPos.y += 2.0f;

        Vector2 screenPos = GetWorldToScreen(textPos, camera);
        DrawText(player.second.username.c_str(), (int)screenPos.x, (int)screenPos.y, 20, ORANGE);
    }
    for (auto& player : remotePlayers)
    {
        if (player.second.messageTimer > 0)
        {
            Vector3 textPos = player.second.position;
            textPos.y += 2.0f;

            Vector2 screenPos = GetWorldToScreen(textPos, camera);
            DrawText(player.second.currentMessage.c_str(), (int)screenPos.x, (int)screenPos.y, 20, DARKBLUE);
        }
        
    }
    if (isTyping)
    {
        DrawRectangle(20, GetScreenHeight() - 50, 400, 30, LIGHTGRAY);
        DrawText(currentInput.c_str(), 25, GetScreenHeight() - 45, 20, BLACK);
    }
}

