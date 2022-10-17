#include "raylib.h"
#include "dasher.h"

void startDasher(){
    // window dimensions
    const int windowDimensions[]{512, 380};

    // init window
    InitWindow(windowDimensions[0], windowDimensions[1], "Dasher");

    //physics 
    const int gravity {1'000};
    const int jumpVel {-600};
    int velocity = 0;

     // hazard variables
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebRec{0.0, 0.0, nebula.width/8.0f, nebula.height/8.0f};
    Vector2 nebPos{(float)windowDimensions[0], windowDimensions[1] - nebRec.height};

    // nebula X velocity (pixels/second)
    int nebVel{-600};

    // player variables
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;

    Vector2 scarfyPos;
    scarfyPos.x = windowDimensions[0]/2 - scarfyRec.width/2;
    scarfyPos.y = windowDimensions[1] - scarfyRec.height;

    //animation frame
    int frame{};

    // amount of time before animation frame update
    const float updateTime{1.0/12.0};
    float runningTime{};

    // prevent double jumping
    bool isInAir{};

    // set FPS
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        
        // delta time
        const float dT{GetFrameTime()};

        // begin drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // player on ground
        if(scarfyPos.y >= windowDimensions[1] - scarfyRec.height){
           velocity = 0;
           isInAir = false; 
        }

        // player in air
        else{
            velocity += gravity * dT;    
            isInAir = true;
        }                  

        // jump mechanic
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            velocity += jumpVel;                                     
        }
        
        // update hazard position
         nebPos.x += nebVel * dT;

        // update player position
        scarfyPos.y += velocity * dT;

        if(!isInAir){
            runningTime += dT;
            if (runningTime >= updateTime)
            {
                runningTime = 0.0;
                // update animation frame
                scarfyRec.x = frame * scarfyRec.width;
                frame++;
                if (frame > 5)
                {
                    frame = 0;
                }
            }
        }
        
        DrawTextureRec(nebula, nebRec, nebPos, WHITE);
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        // end drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);

    CloseWindow();
}