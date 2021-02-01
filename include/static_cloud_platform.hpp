#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
#include "Entity.hpp"

using namespace sf;

class static_cloud_platform : public Platform{
    bool canBounce=true; //This converts to false once the player collides 1 time with the platform
    int transp=255;
public:
    static_cloud_platform(std::string filename);
    void Update(Game &game) override; //Updates cloud's transparency
    bool collideWith(const Entity & ent2) override;  //Checks if the player is colliding with this->_spr (if it already had once, this function is going to return false)
    ~static_cloud_platform() override;
};