#include "Environment.hpp"

void Environment::Tick(float deltatime)
{

    // Scroll background
    bgX -= 20 * deltatime;
    if (bgX <= -background.width * 2)
    {
        bgX = 0.0;
    }
    // Scroll the midground
    mgX -= 40 * deltatime;
    if (mgX <= -midground.width * 2)
    {
        mgX = 0.0;
    }
    // Scroll the foreground
    fgX -= 80 * deltatime;
    if (fgX <= -foreground.width * 2)
    {
        fgX = 0.0;
    }

    Entity::Tick(deltatime);
}

void Environment::Render()
{
    // far
    Vector2 bg1Pos{bgX, 0.0};
    DrawTextureEx(background, bg1Pos, 0.0, 2.0, WHITE);
    Vector2 bg2Pos{bgX + background.width * 2, 0.0};
    DrawTextureEx(background, bg2Pos, 0.0, 2.0, WHITE);
    // mid
    Vector2 mg1Pos{mgX, 0.0};
    DrawTextureEx(midground, mg1Pos, 0.0, 2.0, WHITE);
    Vector2 mg2Pos{mgX + midground.width * 2, 0.0};
    DrawTextureEx(midground, mg2Pos, 0.0, 2.0, WHITE);
    // fore
    Vector2 fg1Pos{fgX, 0.0};
    DrawTextureEx(foreground, fg1Pos, 0.0, 2.0, WHITE);
    Vector2 fg2Pos{fgX + foreground.width * 2, 0.0};
    DrawTextureEx(foreground, fg2Pos, 0.0, 2.0, WHITE);
}

Environment::~Environment() 
{
    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
}
