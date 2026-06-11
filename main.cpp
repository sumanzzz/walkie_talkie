


#include <iostream>
#include "raylib.h"
#include "worldscene.h"
#include "Network/client.h"



const int screenWidth = 800;
const int screenHeight = 450;
   
int main(void)
{
    InitWindow(screenWidth, screenHeight, "Walkie Talkie");

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
       

        if (client.recievePacket(remotePacket))
        {
            if (remotePacket.disconnected)
            {
                scene.removeRemotePlayer(remotePacket.playerId);
            }
            else
            {
                scene.updateRemotePLayer(remotePacket.playerId, { remotePacket.x,remotePacket.y , remotePacket.z });
            }
           
        }
        packet.disconnected = false;

        
        packet.x = pos.x;
        packet.y = pos.y;
        packet.z = pos.z;

        client.sendRequest(packet);
        
       
        BeginDrawing();

        ClearBackground(SKYBLUE);

        scene.draw();
       

        EndDrawing();
        
    }

   
    CloseWindow();        
   

    return 0;
}
