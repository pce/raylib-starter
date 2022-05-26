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
    Texture2D background = LoadTexture("assets/textures/env/far.png");
    float bgX{};
    Texture2D midground = LoadTexture("assets/textures/env/sand.png");
    float mgX{};
    Texture2D foreground = LoadTexture("assets/textures/env/foregound-merged.png");
    float fgX{};
};

#endif