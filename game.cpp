#include <string>
#include "raylib.h"
#include "Environment.hpp"
#include "Character.hpp"

auto main() -> int
{
    enum class GameScreen
    {
        TITLE,
        GAMEPLAY,
        GAMEOVER,
    };
    GameScreen currentScreen{GameScreen::TITLE};

    int winWidth{512};
    int winHeight{380};

    InitWindow(winWidth, winHeight, "Game");
    // InitAudioDevice();

    // Sound bgWav = LoadSound("assets/audio/bg.wav");
    // SetSoundVolume(bgWav, 0.2f);

    Environment environment;
    Character character;

    character.SetWindowSize(winWidth, winHeight);
    character.SetPosition(winWidth * .5, winHeight * .5);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case GameScreen::TITLE:
        {
            BeginDrawing();
            ClearBackground(GRAY);

            std::string title{"Press any Key to Play!"};
            // std::string help{"ASDW and MouseClick..."};
            DrawText(title.c_str(), 23.f, 13.f, 20, BLACK);
            DrawText(title.c_str(), 25.f, 15.f, 20, WHITE);
            EndDrawing();
            // is any key pressed
            int key = GetKeyPressed();
            if ((key >= 32) && (key <= 126))
            {
                // initGame()
                // .Init();
                currentScreen = GameScreen::GAMEPLAY;
            }
        }
        break;
        case GameScreen::GAMEOVER:
        {
            BeginDrawing();
            ClearBackground(GRAY);

            std::string health{"Game Over!"};
            DrawText(health.c_str(), 23.f, 13.f, 20, BLACK);
            DrawText(health.c_str(), 25.f, 15.f, 20, WHITE);
            EndDrawing();
            // is any key pressed
            int key = GetKeyPressed();
            if ((key >= 32) && (key <= 126))
            {
                currentScreen = GameScreen::TITLE;
            }
        }
        break;
        case GameScreen::GAMEPLAY:
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
        }
    }

    // StopSoundMulti();
    // UnloadSound(bgWav);
    // CloseAudioDevice();

    return 0;
}