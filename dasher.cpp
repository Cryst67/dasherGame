#include "raylib.h"
#include "dasher.h"

void startDasher(){
    // window dimensions
    const int windowDimensions[]{512, 380};

    // init window
    InitWindow(windowDimensions[0], windowDimensions[1], "Dasher");

    // set FPS
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        // begin drawing
        BeginDrawing();
        ClearBackground(WHITE);



        
        // end drawing
        EndDrawing();
    }

    CloseWindow();
}