#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"


class Platform : public Entity {

public:
    Platform();
    Vector2f spawn();
    virtual void Update();
    void render(RenderTarget & target);
    ~Platform();
};