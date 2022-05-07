#include "Character.hpp"

void Character::Tick(float deltatime)
{
    if (IsKeyDown(KEY_A) && x > 0)
    {
        x -= 1;
    }
    if (IsKeyDown(KEY_D) && x < winWidth)
    {
        x += 1;
    }
    if (IsKeyDown(KEY_S) && y < winHeight)
    {
        y += 1;
    }
    if (IsKeyDown(KEY_W) && y > 0)
    {
        y -= 1;
    }

    Entity::Tick(deltatime);
}

void Character::Render()
{
    // Vector2 fg2Pos{fgX + foreground.width * 2, 0.0};
    // DrawTextureEx(texture, fg2Pos, 0.0, 2.0, WHITE);
    
    DrawCircle(x, y, 23.0, DARKBLUE);

    // DrawTriangleLines((Vector2){circleX, 160.0f},
    //                     (Vector2){circleY - 20.0f, 230.0f},
    //                     (Vector2){circleX + circleRadius, 230.0f}, circleColor);

    // Polygon shapes and lines
    // DrawPoly((Vector2){screenWidth/4.0f*3, 320}, 6, 80, 0, BROWN);
    // DrawPolyLinesEx((Vector2){screenWidth/4.0f*3, 320}, 6, 80, 0, 6, BEIGE);

}


void Character::SetWindowSize(int width, int height) 
{
    winWidth = width;
    winHeight = height;
}

void Character::SetPosition(int posX, int posY) 
{
    x = posX;
    y = posY;
}

Character::~Character() 
{
    // UnloadTexture(texture);
}
