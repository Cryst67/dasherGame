#include "raylib.h"
#include "dasher.h"

void startDasher(){
    // window dimensions
    const int windowDimensions[]{512, 288};

    // init window
    InitWindow(windowDimensions[0], windowDimensions[1], "Dasher");

    //player dimensions
    const int width{50};
    const int height{80};

    //physics 
    const int gravity {1};
    int velocity = 0;

    int posY{windowDimensions[1] - height};

    // prevent double jumping
    bool isInAir{};

    // set FPS
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        // begin drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // player on ground
        if(posY >= windowDimensions[1] - height){
           velocity = 0;
           isInAir = false; 
        }

        // player in air
        else{
            velocity += gravity;    
            isInAir = true;
        }                  

        // jump mechanic
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            velocity -= 10;                                     
        }

        // update position (/frame)
        posY += velocity;

        DrawRectangle(windowDimensions[0]/2 - width/2, posY, width, height, BLUE);
        // end drawing
        EndDrawing();
    }

    CloseWindow();
}