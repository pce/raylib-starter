#include "Character.hpp"

void Character::Tick(float deltatime)
{
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

    Entity::Tick(deltatime);
}

void Character::Render()
{
    // Vector2 fg2Pos{fgX + foreground.width * 2, 0.0};
    // DrawTextureEx(texture, fg2Pos, 0.0, 2.0, WHITE);
            DrawCircle(circleX, circleY, circleRadius, circleColor);
}

Character::~Character() 
{
    UnloadTexture(texture);
}
