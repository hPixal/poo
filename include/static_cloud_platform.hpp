#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
#include "Entity.hpp"

using namespace sf;

class static_cloud_platform : public Platform{
public:
    bool canBounce=true;
    int transp=255;
    static_cloud_platform(std::string filename);
    void Update(Game &game) override;
    bool collideWith(const Entity & ent2) override;
    ~static_cloud_platform() override;
};