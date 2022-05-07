#include "Entity.hpp"

#include "raymath.h"

Entity::Entity() {}


Vector2 Entity::GetWorldPos()
{
    return worldPos;
}

void Entity::UndoMovement()
{
    worldPos = worldPosLastFrame;
}

void Entity::Tick(float deltatime)
{
    // base entity stuff
}
