#include "Character.hpp"
#include "raymath.h"

void Character::Tick(float deltatime)
{

    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;

    if (Vector2Length(velocity) != 0.0) {
        worldPosLastFrame = worldPos;
        // set world pos  = worldpos + velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        rightLeft = (velocity.x < 0.f) ? -1.f : 1.f;
    }
    velocity = {};

    // animation (column based)
    runningTime += deltatime;
    if (runningTime > updateTime) {
        frame++;
        runningTime = 0;
    }
    if (frame > textureMaxFrames) {
        frame = 0;
    }

    if (frame == 0) {
        showBubble = true;        
    }

    Entity::Tick(deltatime);
}

void Character::Render()
{
    Rectangle textureSource{static_cast<float>(frame * texture.width / textureMaxFrames), static_cast<float>(texture.height), rightLeft * (texture.width / textureMaxFrames), static_cast<float>(texture.height)};
    // worldPos, better use screenPos
    Rectangle textureDest{worldPos.x,
                          worldPos.y,
                          scaleFactor * (texture.width / textureMaxFrames),
                          scaleFactor * texture.height};
    // character draw
    DrawTexturePro(texture, textureSource, textureDest, Vector2{}, 0.f, WHITE);

    // draw bubbles
    if (showBubble) {
        if (frame == 1) {
            x = worldPos.x;
            y = worldPos.y;
        }
        if (frame == bubblesMaxFrames) {
            showBubble = false;
        }
        Vector2 pos{x, y};
        Rectangle rec;

        int xOffset = (rightLeft > 0) ? (texture.width / textureMaxFrames) - 26 : 0;
        pos.x += xOffset;

        rec.x = frame * bubbles.width / bubblesMaxFrames;
        rec.y = 0;
        rec.width = bubbles.width / bubblesMaxFrames;
        rec.height = bubbles.height;
        DrawTextureRec(bubbles, rec, pos, WHITE);
    }
}

void Character::SetWindowSize(int width, int height)
{
    winWidth = width;
    winHeight = height;
}

void Character::SetPosition(int posX, int posY)
{
    worldPos.x = posX;
    worldPos.y = posY;
}

Character::~Character()
{
    // UnloadTexture(texture);
    // UnloadTexture(bubbles);
}
