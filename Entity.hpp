#ifndef ENTITY_H_
#define ENTITY_H_

#include "raylib.h"

class Entity
{
public:
    Entity();
    // Rectangle GetCollisionRect();
    Vector2 GetWorldPos();
    void UndoMovement();
    virtual void Tick(float deltatime);
    virtual void Render() = 0;

protected:
    Vector2 worldPos;
    Vector2 screenPos;
    Vector2 worldPosLastFrame;
};

#endif