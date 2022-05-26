#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Entity.hpp"

class Character : public Entity 
{
public:
    virtual void Tick(float deltatime) override;
    void Render() override;
    void SetWindowSize(int width, int height);
    void SetPosition(int posX, int posY);
    ~Character();
private:
    Texture2D texture = LoadTexture("assets/textures/actor/player-swiming.png");
    float x{};
    float y{};
    int winWidth;
    int winHeight;
    // animation data
    float runningTime{};
    int frame{};
    // 1: right, -1: left
    float rightLeft{1.0};
    const float updateTime{1.f / 6.f};
    int textureMaxFrames{7};
    // Vector2 velocity{};
};

#endif