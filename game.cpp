#include "raylib.h"

auto main() -> int
{
    int winWidth{320};
    int winHeight{240};

    InitWindow(winWidth, winHeight, "Game");

    float circleRadius = 25;
    int circleX = winWidth * .5;
    int circleY = winHeight * .5;
    Color circleColor = BLUE;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // Game logic
        DrawCircle(circleX, circleY, circleRadius, circleColor);
        if (IsKeyDown(KEY_A) && circleX > 0)
        {
            circleX -= 1;
        }
        if (IsKeyDown(KEY_D) && circleX < winWidth)
        {
            circleX += 1;
        }
        if (IsKeyDown(KEY_S) && circleY < winHeight)
        {
            circleY += 1;
        }
        if (IsKeyDown(KEY_W) && circleY > 0)
        {
            circleY -= 1;
        }
        EndDrawing();
    }

    return 0;
}