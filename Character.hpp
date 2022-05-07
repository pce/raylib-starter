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
    // Texture2D texture = LoadTexture("assets/textures/player.png");
    float x{};
    float y{};
    int winWidth;
    int winHeight;
};

#endif