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
    moving_cloud_platform(std::string filename, int plusSpeed); // Recibes the texture's file name passes it to Platform(filename)
    void Update(Game &game) override; //Updates the platform position and makes it bounce between the two edges of game.m_window
    bool collideWith(const Entity & ent2) override; //Checks if the player is colliding with this->_spr (if it already had once, this function is going to return false)
    ~moving_cloud_platform() override;
};

/*
This file is part of Skyjump.

    Skyjump is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Skyjump is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Skyjump.  If not, see <https://www.gnu.org/licenses/>.
*/