#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"

class Platform : public Entity {

public:
    Platform(std::string file_loc);
    //Point system
    int points=10;
    bool canGetPoints=true;
    //Functions
    int getpoints();
    void spawnPlatform(Vector2f pos);
    /*virtual void Draw(sf::RenderTarget &tar)const override = 0;*/

    //Override
    virtual bool collideWith(const Entity & ent2) override;
    virtual void Update(Game &game)=0;
    virtual ~Platform() override { }
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