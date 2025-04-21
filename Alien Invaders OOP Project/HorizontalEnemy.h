#pragma once
#include "BasicEnemy.h"
class HorizontalEnemy :
    public BasicEnemy
{
public:

    HorizontalEnemy(sf::Texture& enemyTex,
        sf::Vector2f position,
        float newScreenWidth);

protected:

    virtual void Move(float frameTime) override;

private:

    float screenWidth;
    float hVel;

};

