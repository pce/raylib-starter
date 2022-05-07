#include "raylib.h"
#include "Environment.hpp"
#include "Character.hpp"

auto main() -> int
{
    int winWidth{512};
    int winHeight{380};

    InitWindow(winWidth, winHeight, "Game");

    Environment environment;
    Character character;

    character.SetWindowSize(winWidth, winHeight);
    character.SetPosition(winWidth * .5, winHeight * .5);

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