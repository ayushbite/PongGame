#include "raylib.h"


struct Ball {
    float ball_xaxis, ball_yaxis;
    float ball_speed_xaxis, ball_speed_yaxis;
    float ball_raidus;

    void DrawBAll() {
        DrawCircle((int) ball_xaxis, (int) ball_yaxis, ball_raidus, WHITE);

    }


};

int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 500;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");


/*    vsync hint*/
    SetWindowState(FLAG_VSYNC_HINT);

    Ball ball;//struct of ball
    ball.ball_xaxis = GetScreenWidth() / 2.0f;
    ball.ball_yaxis = GetScreenHeight() / 2.0f;
    ball.ball_raidus = 10;
    ball.ball_speed_xaxis = 50;
    ball.ball_speed_yaxis = 500;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
//        before drarwing update the ball axis with speed
        ball.ball_xaxis += ball.ball_speed_xaxis * GetFrameTime();
        ball.ball_yaxis += ball.ball_speed_yaxis * GetFrameTime();

//         writing a condition when the ball is on to the end of the screen then boucing of the ball

//            when the ball goes to the top of the screen
        if (ball.ball_yaxis < 0) {
            ball.ball_yaxis = 0;
            ball.ball_speed_yaxis *= -1;


        }

//        when ball is bottom of the screen
        if (ball.ball_yaxis > GetScreenHeight()) {
            ball.ball_yaxis = GetScreenHeight();
            ball.ball_speed_yaxis *= -1;
        }


        BeginDrawing();

        ClearBackground(BLACK);
        DrawFPS(10, 10);

//        Drawing circle on to the middle of the screen
        ball.DrawBAll();

//        Drawing a rectangle on the left side as an counter attact rod
//        and making the y-axis subtracting to the half of the height of the rectangle to to appear as to the center
        int height_of_rectangle = 100;
        DrawRectangle(10, GetScreenHeight() / 2 - (height_of_rectangle / 2), 5, height_of_rectangle, WHITE);
        DrawRectangle(GetScreenWidth() - 10 - 5, GetScreenHeight() / 2 - (height_of_rectangle / 2), 5,
                      height_of_rectangle, WHITE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
