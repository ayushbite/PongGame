#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 500;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop

/*    vsync hint*/
    SetWindowState(FLAG_VSYNC_HINT);
    float ball_xaxis = GetScreenWidth()/2.0f;
    float ball_yaxis = GetScreenHeight()/2.0f;
    float ball_raidus = 10;
    float ball_speed_xaxis = 10;
    float ball_speed_yaxis = 10;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
//        before drarwing update the ball axis with speed
            ball_xaxis += ball_speed_xaxis * GetFrameTime();
            ball_yaxis += ball_speed_yaxis * GetFrameTime();



        BeginDrawing();

        ClearBackground(BLACK);
        DrawFPS(10,10);

//        Drawing circle on to the middle of the screen
        DrawCircle((int)ball_xaxis,(int)ball_yaxis,ball_raidus,WHITE);
//        Drawing a rectangle on the left side as an counter attact rod
//        and making the y-axis subtracting to the half of the height of the rectangle to to appear as to the center
        int height_of_rectangle = 100;
        DrawRectangle(10,GetScreenHeight()/2 - (height_of_rectangle/2),5,height_of_rectangle,WHITE);
        DrawRectangle(GetScreenWidth() - 10-5,GetScreenHeight()/2 - (height_of_rectangle/2),5,height_of_rectangle,WHITE);







        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
