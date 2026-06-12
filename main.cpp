


#include <iostream>
#include <string>
#include "raylib.h"
#include "worldscene.h"
#include "Network/client.h"



const int screenWidth = 800;
const int screenHeight = 450;
   
int main(void)
{
    InitWindow(screenWidth, screenHeight, "Walkie Talkie");

    std::string username;
    std::getline(std::cin, username);

    Client client;
    client.Connect("127.0.0.1", 8000);

    WorldScene scene;

    

    SetTargetFPS(60);     

    DisableCursor();

    

    while (!WindowShouldClose())    
    {
        
        float dt = GetFrameTime();
        scene.update(dt);
        
        
        Vector3 pos = scene.getPlayerPosition();

        PlayerPacket packet{};
        PlayerPacket remotePacket{};
        
        strcpy(packet.username, username.c_str());
        if (client.recievePacket(remotePacket))
        {
            if (remotePacket.disconnected)
            {
                scene.removeRemotePlayer(remotePacket.playerId);
            }
            else
            {
                scene.updateRemotePLayer(remotePacket.playerId, { remotePacket.x,remotePacket.y , remotePacket.z } , remotePacket.rotation , remotePacket.username);
            }
           
        }
        packet.disconnected = false;

        
        packet.x = pos.x;
        packet.y = pos.y;
        packet.z = pos.z;
        packet.rotation = scene.getPlayerRotation();
        packet.isChat = false;
        client.sendRequest(packet);
        
        if (IsKeyPressed(KEY_ENTER))
        {
            PlayerPacket chatPacket{};
            chatPacket.isChat = true;

            strcpy_s(chatPacket.message, "Hello");

            client.sendRequest(chatPacket);
        }
       
        BeginDrawing();

        ClearBackground(SKYBLUE);

        scene.draw();
       

        EndDrawing();
        
    }

   
    CloseWindow();        
   

    return 0;
}
