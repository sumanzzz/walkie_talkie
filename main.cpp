


#include <iostream>
#include "raylib.h"
#include "worldscene.h"
#include "Network/client.h"



const int screenWidth = 800;
const int screenHeight = 450;
   
int main(void)
{
    Client client;
    client.Connect("127.0.0.1", 8000);

    WorldScene scene;

    InitWindow(screenWidth, screenHeight, "Walkie Talkie");

    SetTargetFPS(60);     

    DisableCursor();

    

    while (!WindowShouldClose())    
    {
        float dt = GetFrameTime();
        scene.update(dt);
        

        BeginDrawing();

        ClearBackground(SKYBLUE);

        scene.draw();
       

        EndDrawing();
        
    }

   
    CloseWindow();        
   

    return 0;
}
