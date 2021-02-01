#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
#include "Entity.hpp"

class moving_cloud_platform : public Platform{
    int m_speed; //Speed of the platform
    bool canBounce=true; //This converts to false once the player collides 1 time with the platform
    int transp=255; 
public:
    moving_cloud_platform(std::string filename); // Recibes the texture's file name passes it to Platform(filename)
    void Update(Game &game) override; //Updates the platform position and makes it bounce between the two edges of game.m_window
    bool collideWith(const Entity & ent2) override; //Checks if the player is colliding with this->_spr (if it already had once, this function is going to return false)
    ~moving_cloud_platform() override;
};