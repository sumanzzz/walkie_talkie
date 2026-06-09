#include <iostream>
#include "raylib.h"
#include "worldscene.h"

const int screenWidth = 800;
const int screenHeight = 450;
   
int main(void)
{
    WorldScene scene;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);             
   
    while (!WindowShouldClose())    
    {
        
        BeginDrawing();

        ClearBackground(SKYBLUE);

        scene.draw();

        EndDrawing();
        
    }

   
    CloseWindow();        
   

    return 0;
}
