#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include "Entity.hpp"

class Environment : public Entity 
{
public:
    virtual void Tick(float deltatime) override;
    void Render() override;
    ~Environment();
private:
    Texture2D background = LoadTexture("assets/textures/far.png");
    float bgX{};
    Texture2D midground = LoadTexture("assets/textures/sand.png");
    float mgX{};
    Texture2D foreground = LoadTexture("assets/textures/foregound-merged.png");
    float fgX{};
};

#endif