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


    // animation (column based)
    runningTime += deltatime;
    if (runningTime > updateTime)
    {
        frame++;
        runningTime = 0;
    }
    if (frame > textureMaxFrames)
    {
        frame = 0;
    }

    Entity::Tick(deltatime);
}   

void Character::Render()
{
    Vector2 pos{x, y};
    Rectangle rec;
    rec.x = frame * texture.width/textureMaxFrames;
    rec.y = 0;
    rec.width = texture.width/textureMaxFrames;
    rec.height = texture.height;

    DrawTextureRec(texture, rec, pos, WHITE);
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
