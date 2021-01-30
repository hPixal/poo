#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
#include "Entity.hpp"

class moving_cloud_platform : public Platform{
    int m_speed;
public:
    bool canBounce=true;
    int transp=255;
    moving_cloud_platform(std::string filename);
    void Update(Game &game) override;
    bool collideWith(const Entity & ent2) override;
    ~moving_cloud_platform() override;
};