#include "raylib.h"
#include "Environment.hpp"

auto main() -> int
{
    int winWidth{512};
    int winHeight{380};

    InitWindow(winWidth, winHeight, "Game");

    Environment environment;
    Character character;

    float circleRadius = 25;
    int circleX = winWidth * .5;
    int circleY = winHeight * .5;
    Color circleColor = BLUE;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Env
        environment.Tick(GetFrameTime());

        environment.Render();

        // Character
        character.Tick(GetFrameTime());
        character.Render();


        EndDrawing();
    }

    return 0;
}