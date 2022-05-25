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
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground(BLACK);
        DrawFPS(10,10);

//        Drawing circle on to the middle of the screen
        DrawCircle(GetScreenWidth()/2,GetScreenHeight()/2,10,WHITE);
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
