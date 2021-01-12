#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Platform : public Entity {

public:
    Platform();

    //Functions
    Vector2f spawnPlatform();
    void renderPlatform(RenderTarget & target);


    //Override
    virtual void Update();
    virtual void movement() = 0;
    ~Platform();
};